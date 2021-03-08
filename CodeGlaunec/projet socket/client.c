/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.c
 * Author: snir2g1
 *
 * Created on 9 février 2021, 16:42
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>     /* Pour exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/socket.h> /* Pour socket */
#include <arpa/inet.h>  /* Pour IPPROTO_TCP */
#include <stdio.h>      /* Pour perror */
#include <unistd.h>     /* Pour close */
#include <string.h>     /* Pour memset */
 
int main(int argc, char *argv[]) {
  int fd;
  struct sockaddr_in adresse;
  size_t taille;
 
  /* Verification des arguments */
  if(argc != 4) {
    fprintf(stderr, "Usage : %s adresseServeur portServeur message\n", argv[0]);
    fprintf(stderr, "Ou :\n");
    fprintf(stderr, "  adresseServeur : adresse IPv4 du serveur\n");
    fprintf(stderr, "  portServeur    : numero de port du serveur\n");
    fprintf(stderr, "  message        : le message a envoyer\n");
    exit(EXIT_FAILURE);
  }
 
  /* Creation de la socket */
  if((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("Erreur lors de la creation de la socket ");
    exit(EXIT_FAILURE);
  }
 
  /* Remplissage de la structure */
  memset(&adresse, 0, sizeof(struct sockaddr_in));
  adresse.sin_family = AF_INET;
  inet_pton(AF_INET, argv[1], &adresse.sin_addr.s_addr);
  adresse.sin_port = htons(atoi(argv[2]));
 
  /* Connexion au serveur */
  if(connect(fd, (struct sockaddr*)&adresse, sizeof(adresse)) == -1) {
    perror("Erreur lors de la connexion ");
    exit(EXIT_FAILURE);
  }
 
  /* Envoi du message au serveur */
  taille = strlen(argv[3]) + 1;
  if(write(fd, &taille, sizeof(size_t)) == -1) {
    perror("Erreur lors de l'envoi de la taille du message ");
    exit(EXIT_FAILURE);
  }
  if(write(fd, argv[3], sizeof(char) * taille) == -1) {
    perror("Erreur lors de l'envoi du message ");
    exit(EXIT_FAILURE);
  }
  printf("Client : message envoye.\n");
 
  /* Fermeture de la socket */
  if(close(fd) == -1) {
    perror("Erreur lors de la fermeture de la socket ");
    exit(EXIT_FAILURE);
  }
 
  return EXIT_SUCCESS;
}