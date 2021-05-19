#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#define MAX 1048576
#define PORT 7256 
#define SA struct sockaddr 

using namespace std;
using namespace cgicc;

int main()
{
	int sockfd, connfd, length; 
	struct sockaddr_in servaddr, cli; 
	char buff[MAX]; 
	string listerEnregistrements = "listerEnregistrement";
	string mon_fichier_log = "/home/pi/gps.log";
    ofstream fichier_log(mon_fichier_log.c_str(),  ios::out | ios::app  );
	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		fichier_log<<"socket creation failed... "<<endl;
		exit(0); 
	} 
	else
		fichier_log<<"Socket successfully created.."<<endl; 
	memset(&servaddr, 0 , sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		fichier_log<<"connection with the server failed..."<<endl; 
		exit(0); 
	} 
	else
		fichier_log<<"connected to the server.."<<endl; 
	length = send(sockfd, listerEnregistrements.c_str(),listerEnregistrements.size(),0); 
	memset(buff,0 , sizeof(buff)); 
	int taille = read(sockfd, buff, sizeof(buff));
	cout <<HTTPHTMLHeader();
	cout<<string(buff)<<endl;
	// close the socket 
	close(sockfd); 

}