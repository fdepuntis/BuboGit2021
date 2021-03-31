//g++ Serveur.cpp Collecteur.cpp Enregistrement.cpp -o Serveur
//raspberry:g++ Serveur.cpp Collecteur.cpp Enregistrement.cpp Geolocalisation.cpp Horodatage.cpp Lampadaire.cpp Ampoule.cpp Galerie.cpp GPS.cpp Luxmetre.cpp BDD.cpp Mail.cpp Config.cpp Internet.cpp lib/serialib.o  -L /usr/local/lib -lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML -lcgicc  -pthread -lsqlite3   -o  Serveur 
//https://programmer.help/blogs/an-example-of-c-socket-programming-under-linux.html
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h> 
#include <cstring> 
#include <string> 
#include <sys/socket.h> 
#include <sys/types.h>

#include <iostream> 

#include "Collecteur.h"
#define MAX 1024 //ATTENTION! Taille à gérer
#define PORT 7256 
#define SA struct sockaddr 
  
using namespace std;
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, tailleMessage; 
    socklen_t len; 
	string laCommande="";
string response ;
	Collecteur *leCollecteur = new Collecteur();
    struct sockaddr_in servaddr, cli; 
        char buff[MAX]; 
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    memset(&servaddr, 0, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
        memset(buff, 0 ,MAX); 
  
        // read the message from client and copy it in buffer 
        recv(connfd, buff, sizeof(buff),0); 
	/*for (int i=0;i<MAX;i++)
		if (buff[i]!=0) laCommande = laCommande + buff[i];
		else break;*/
	laCommande = string(buff);
	cout<<laCommande<<endl;
	size_t found=laCommande.find("localiser");
  	if (found!=std::string::npos)
		{
			  leCollecteur->creerEnregistrementVirtuel();
			  response= leCollecteur->geolocaliser();
			  leCollecteur->supprimerEnregistrementVirtuel();
		}
        /*found=laCommande.find("liste");
        if (found!=std::string::npos)
        {
            response= leCollecteur->getlisteEnregistrements();
           
        }*/    
		
	cout<<response<<endl; 
printf("A envoyer  : %s  \n", response.c_str());
        memset(buff,0, MAX); 
	cout <<"octets à retourner = " <<response.length()<<endl; //ATTENTION! Réfléchir à la taille maximale à transmettre
        // and send that buffer to client 
        send(connfd, response.c_str(), response.length(), 0); 
  sleep(2);
    // After chatting close the socket 
    close(sockfd); 
} 
