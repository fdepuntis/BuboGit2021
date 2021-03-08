/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.cpp
 * Author: snir2g1
 *
 * Created on 10 février 2021, 14:50
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
#include <iostream> // pour std::cout
#include <string>   // pour std::string
#include <cstring> 

#define MYPORT  7000
#define BUFFER_SIZE 1024
int main()

{
    using namespace std;
    int sock_cli;
    fd_set rfds;
    struct timeval tv;
    int retval, maxfd;

    /// Définir sockfd
    sock_cli = socket(AF_INET,SOCK_STREAM, 0);
    /// Définir sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);  /// Port de serveur
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  /// IP du serveur

    //Connectez-vous au serveur, retournez 0 avec succès, retour d'erreur - 1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    while(1){
        /*Effacer la collection de descripteurs de fichiers lisibles*/
        FD_ZERO(&rfds);
        /*Ajouter des descripteurs de fichier d'entrée standard à la collection*/
        FD_SET(0, &rfds);
        maxfd = 0;
        /*Ajouter le descripteur de fichier actuellement connecté à la collection*/
        FD_SET(sock_cli, &rfds);
        /*Rechercher le plus grand descripteur de fichier dans l'ensemble de descripteurs de fichier*/    
        if(maxfd < sock_cli)
            maxfd = sock_cli;
        /*Réglage du délai d'expiration*/
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        /*En attente de chat*/
        retval = select(maxfd+1, &rfds, NULL, NULL, &tv);
        if(retval == -1){
            printf("select Error, client program exit\n");
            break;
        }/*else if(retval == 0){
            printf("Le client n'a aucune information d'entrée et le serveur n'a aucune information à venir. attendre...\n");
            continue;
        }*/else{
            /*Le serveur a envoyé un message.*/
            if(FD_ISSET(sock_cli,&rfds)){
                char recvbuf[BUFFER_SIZE];
                int len;
                len = recv(sock_cli, recvbuf, sizeof(recvbuf),0);
                printf("%s", recvbuf);
                memset(recvbuf, 0, sizeof(recvbuf));
            }
            
            /*Lorsque l'utilisateur entre les informations, il commence à traiter les informations et à les envoyer.*/
            if(FD_ISSET(0, &rfds)){
                char sendbuf[BUFFER_SIZE];
                fgets(sendbuf, sizeof(sendbuf), stdin);
                send(sock_cli, sendbuf, strlen(sendbuf),0); //Envoyer
                memset(sendbuf, 0, sizeof(sendbuf));
            }
            /*{
                std::string message = "Hello"; // création de la chaîne "Hello"
                message += " World !";         // concaténation de " Word !"

                // créer le buffer pour copier la chaîne 
                size_t size = message.size() + 1; 
                char * buffer = new char[ size ]; 
                // copier la chaîne 
                strncpy( buffer, message.c_str(), size ); 
                // utiliser le buffer 
                cout << buffer << '\n'; // "une chaîne de caractères"  
                // libérer la mémoire 
                delete [] buffer;
            }*/
            
                

             
                
            
        }
    }

    close(sock_cli);
    return 0;
}