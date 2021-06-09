#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <fcntl.h> 
#include <iostream> 
#define MAX 1024
#define PORT 7256 
#define SA struct sockaddr 

using namespace std;

int main() 
{ 
	int sockfd, connfd, length; 
	struct sockaddr_in servaddr, cli; 
	char buff[MAX]; 
	string demandeLocalisation = "localiser";
	string listerEnregistrements = "listerEnregistrement";
	char demande;

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		cout<<"socket creation failed...\n"<<endl; 
		exit(0); 
	} 
	else
		cout<<"Socket successfully created..\n"<<endl; 
	memset(&servaddr, 0 , sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		cout<<"connection with the server failed..."<<endl; 
		exit(0); 
	} 
	else
		cout<<"connected to the server.."<<endl; 
	cout<<"Que souhaitez-vous? A. geolocaliser B. listerEnregistrements")
	cin>> demande;
	if (demande=='A')
	{
		length = send(sockfd, demandeLocalisation.c_str(),demandeLocalisation.size(),0); 
		printf("Le message est : %s de %d octets\n", demandeLocalisation.c_str(), length);
	}
	if (demande=='B')
	{
		length = send(sockfd, listerEnregistrement.c_str(),listerEnregistrement.size(),0); 
		printf("Le message est : %s de %d octets\n", listerEnregistrement.c_str(), length);
	}
	memset(buff,0 , sizeof(buff)); 

	int taille = read(sockfd, buff, sizeof(buff));
	perror("problème lecture"); 
	cout<<string(buff)<<endl;
	printf"From Server : %s avec %d octets \n", buff, taille); 
	if ((strncmp(buff, "exit", 4)) == 0) { 
		cout<<"Client Exit..."<<endl; 
		exit(0);  
	} 

	// close the socket 
	close(sockfd); 
} 

