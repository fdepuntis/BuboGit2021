/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   serveur.c
 * Author: snir2g1
 *
 * Created on 9 février 2021, 16:43
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>     /* Pour exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/socket.h> /* Pour socket */
#include <arpa/inet.h>  /* Pour sockaddr_in, IPPROTO_TCP */
#include <stdio.h>      /* Pour perror */
#include <unistd.h>     /* Pour close */
#include <string.h>     /* Pour memset */
 
int main(int argc, char *argv[]) {
  int fd, sockclient;
  struct sockaddr_in adresse;
  size_t taille;
  char *msg;
 
  /* Verification des arguments */
  if(argc != 2) {
    fprintf(stderr, "Usage : %s port\n", argv[0]);
    fprintf(stderr, "Ou :\n");
    fprintf(stderr, "  port : le numero de port d'ecoute du serveur\n");
    exit(EXIT_FAILURE);
  }
 
  /* Creation de la socket */
  if((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("Erreur lors de la creation de la socket ");
    exit(EXIT_FAILURE);
  }
 
  /* Creation de l'adresse du serveur */
  memset(&adresse, 0, sizeof(struct sockaddr_in));
  adresse.sin_family = AF_INET;
  adresse.sin_addr.s_addr = htonl(INADDR_ANY);
  adresse.sin_port = htons(atoi(argv[1]));
 
  /* Nommage de la socket */
  if(bind(fd, (struct sockaddr*)&adresse, sizeof(struct sockaddr_in)) == -1) {
    perror("Erreur lors du nommage de la socket ");
    exit(EXIT_FAILURE);
  }
 
  /* Mise en mode passif de la socket */
  if(listen(fd, 1) == -1) {
    perror("Erreur lors de la mise en mode passif ");
    exit(EXIT_FAILURE);
  }
 
  /* Attente d'une connexion */
  printf("Serveur : attente de connexion...\n");
  if((sockclient = accept(fd, NULL, NULL)) == -1) {
    perror("Erreur lors de la demande de connexion ");
    exit(EXIT_FAILURE);
  }
 
  /* Lecture du message */
  if(read(sockclient, &taille, sizeof(size_t)) == -1) {
    perror("Erreur lors de la lecture de la taille du message ");
    exit(EXIT_FAILURE);
  }
  if((msg = (char*)malloc(sizeof(char) * taille)) == NULL) {
    perror("Erreur lors de l'allocation memoire pour le message ");
    exit(EXIT_FAILURE);
  }
  if(read(sockclient, msg, sizeof(char) * taille) == -1) {
    perror("Erreur lors de la lecture de la taille du message ");
    exit(EXIT_FAILURE);
  }
  printf("Serveur : message recu '%s'.\n", msg);
 
  /* Fermeture des sockets */
  if(close(sockclient) == -1) {
    perror("Erreur lors de la fermeture de la socket de communication ");
    exit(EXIT_FAILURE);
  }
  if(close(fd) == -1) {
    perror("Erreur lors de la fermeture de la socket de connexion ");
    exit(EXIT_FAILURE);
  }
 
  /* Liberation memoire */
  free(msg);
 
  printf("Serveur termine.\n");
 
  return EXIT_SUCCESS;
}

