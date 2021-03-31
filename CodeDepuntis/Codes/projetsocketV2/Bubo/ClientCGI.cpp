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
	string leMessage = "localiser";

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	memset(&servaddr, 0 , sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

	// function for chat 
	length = send(sockfd, leMessage.c_str(), sizeof(leMessage.c_str())+1,0); 
	printf("Le message est : %s de %d octets\n", leMessage.c_str(), length);
	memset(buff,0 , sizeof(buff)); 
	int taille = read(sockfd, buff, sizeof(buff));
perror("problème lecture"); 
cout<<string(buff)<<endl;
	printf("From Server : %s avec %d octets \n", buff, taille); 
	if ((strncmp(buff, "exit", 4)) == 0) { 
		printf("Client Exit...\n"); 
		exit(0);  
	} 

	// close the socket 
	close(sockfd); 
} 

