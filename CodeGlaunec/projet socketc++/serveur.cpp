/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g1
 *
 * Created on 10 février 2021, 14:42
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <iostream>
#define PORT 7000
#define QUEUE 20

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval, maxfd;
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT);
    //printf ("% d \ n", INADDR_ANY);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        perror("bind");
        exit(1);
    }
    
    
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    /// Retour réussi du descripteur non négatif, erreur Return-1
    int conn = accept(ss, (struct sockaddr*)&client_addr, &length);
    if( conn < 0 ) {
        perror("connect");
        exit(1);
    }
    while(1) {
        /*Effacer la collection de descripteurs de fichiers lisibles*/
        FD_ZERO(&rfds);
        /*Ajouter des descripteurs de fichier d'entrée standard à la collection*/
        FD_SET(0, &rfds);
        maxfd = 0;
        /*Ajouter le descripteur de fichier actuellement connecté à la collection*/
        FD_SET(conn, &rfds);
        /*Rechercher le plus grand descripteur de fichier dans l'ensemble de descripteurs de fichier*/    
        if(maxfd < conn)
            maxfd = conn;
        /*Réglage du délai d'expiration*/
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        /*En attente de chat*/
        retval = select(maxfd+1, &rfds, NULL, NULL, &tv);
        if(retval == -1){
            printf("select Error, client program exit\n");
            break;
        }/*else if(retval == 0){
            printf("Le serveur n'a aucune information d'entrée, et le client n'a aucune information à venir. attendre...\n");
            continue;
        }*/else{
            /*Le client a envoyé un message.*/
            if(FD_ISSET(conn,&rfds)){
                char buffer[1024];    
                memset(buffer, 0 ,sizeof(buffer));
                int len = recv(conn, buffer, sizeof(buffer), 0);
                if(strcmp(buffer, "exit\n") == 0) break;
                printf("%s", buffer);
                //Send (conn, buffer, len, 0); send back the data to the client
            }
            /*Lorsque l'utilisateur entre les informations, il commence à traiter les informations et à les envoyer.*/
            if(FD_ISSET(0, &rfds)){
                char buf[1024];
                fgets(buf, sizeof(buf), stdin);
                //printf("you are send %s", buf);
                send(conn, buf, sizeof(buf), 0);
            }
        }
    }
    close(conn);
    close(ss);
    return 0;
}

