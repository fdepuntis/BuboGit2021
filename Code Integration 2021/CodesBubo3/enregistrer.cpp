#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"

#include "Poco/JSON/Object.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/JSON/Stringifier.h"

#include "Enregistrement.h"
#include "BDD.h"
#include "Collecteur.h"
#include "Logger.h"

#define MAX 1048576
#define PORT 7256 
#define SA struct sockaddr 

using namespace std;
using namespace cgicc;

int main()
{      
      Logger* monLogger = new Logger();
	//Déclaration des variables
	string identifiantCollecteur;
	string  aIdEnregistrement;
	//int aId;
	string albedo;
	string fluxLum;
	string aIdRaspberry;
	string lamp;
	string streetlight;
	string height;
	int power;
	double aLatitude;
	double aLongitude;
	int aAltitude;
	int aNbImages;
	string town;
	string aNotes;
	string street;
	int ULOR;
	string aDate;
	string aHeure; 
	//chaine d'envoi
	string enregistrer = "enregistrer";
	//------------------------
	int sockfd,  length; 
	struct sockaddr_in servaddr, cli; 
	char buff[MAX]; 
	string mon_fichier_log = "/home/pi/enregistrer.log";
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
	//Déclaration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();
	Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
		//-----------------------------------
			//-------------------------Recuperation latitude -------------------------
			form_iterator fvalue = cgi.getElement("latitude"); //Récupération valeur du champs "lattitude" 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
				aLatitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
				json->set("LATITUDE", aLatitude);
			} 
			else 
				fichier_log << "No text entered for latitude" << endl; //Retourne ce texte si aucune valeur n'est entrée 

			//--------------------------R�cup�ration longitude ---------------------------
			fvalue = cgi.getElement("longitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aLongitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
				json->set("LONGITUDE", aLongitude);
			} 
			else 
				fichier_log << "No text entered for longitude" << endl; 
			//--------------------------R�cup�ration  altitude -----------------------------
			fvalue = cgi.getElement("altitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aAltitude = atoi((**fvalue).c_str()); // atof => convertit un string en int 
				json->set("ALTITUDE", aAltitude);
			} 
			else 
				fichier_log << "No text entered for altitude" << endl; 

			//--------------------------R�cup�ration typeLampadaire -------------------------
			fvalue = cgi.getElement("typeLampadaire"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				streetlight = **fvalue;
			} else streetlight="";
			json->set("STREETLIGHT", streetlight); 
			
			//--------------------------R�cup�ration ulor -------------------------
			fvalue = cgi.getElement("ulor"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				ULOR = atoi((**fvalue).c_str()); // atoi => convertit un string en int  
			} 
			else ULOR = 0;
			json->set("ULOR", ULOR);

			//--------------------------R�cup�ration typeAmpoule -------------------------
			fvalue = cgi.getElement("typeAmpoule"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				lamp = **fvalue;
			}else lamp="";
			json->set("LAMP", lamp); 
			
			//--------------------------R�cup�ration hauteur -------------------------
			fvalue = cgi.getElement("hauteur"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				height = **fvalue;
			} else height="";
			json->set("HEIGHT", height);

			//--------------------------R�cup�ration puissance -------------------------
			fvalue = cgi.getElement("puissance"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				power = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else power = 0;
			json->set("POWER", power);			
			//--------------------------R�cup�ration albedo -------------------------
			fvalue = cgi.getElement("albedo"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				albedo = **fvalue;
			} else albedo="";
			json->set("ALBEDO", albedo);
			

			//--------------------------R�cup�ration agglomeration -------------------------
			fvalue = cgi.getElement("agglomeration"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				town = **fvalue;
			} else town="";
			json->set("TOWN", town);
		
			//--------------------------R�cup�ration rue -------------------------
			fvalue = cgi.getElement("rue"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
 
				street = **fvalue;
			} else street="";
			json->set("STREET", street);
			//--------------------------R�cup�ration notes -------------------------
			fvalue = cgi.getElement("notes"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aNotes = **fvalue;
			} else aNotes = "";
				json->set("NOTES", aNotes);
			
			//--------------------------R�cup�ration fluxlum -------------------------
			fvalue = cgi.getElement("fluxlum"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				fluxLum = **fvalue;

			} else fluxLum="";
			json->set("FLUX", fluxLum);


			//--------------------------R�cup�ration nbImage -------------------------
			fvalue = cgi.getElement("nbImage"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aNbImages = atoi((**fvalue).c_str()); // atoi => convertit un string en int
			} 
			else aNbImages=0;
			json->set("NBIMAGES", aNbImages);

			//--------------------------R�cup�ration date -------------------------
			fvalue = cgi.getElement("date"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aDate=(**fvalue).c_str(); // atoi => convertit un string en int
				json->set("DATE", aDate);
			} 
			
			//--------------------------Recuperation heure -----------------------
			fvalue = cgi.getElement("heure");
			if( !fvalue->isEmpty() && fvalue !=(*cgi).end()){
				aHeure=(**fvalue).c_str(); //convertir un string en int
				json->set("HEURE", aHeure);
			} 
			std::ostringstream oss;
			Poco::JSON::Stringifier::stringify(json, oss);
			enregistrer+="\n";
			enregistrer+=oss.str();		

			length = send(sockfd, enregistrer.c_str(),enregistrer.size(),0); 
			fichier_log<<endl;
			fichier_log<<"ENREGISTREMENT EFFECTUÉ OK"<<endl;
	        fichier_log.close();  // on referme le fichier
			//----------------------------------------------------------------------
	cout<<HTTPHTMLHeader();
	memset(buff,0 , sizeof(buff)); 

	int taille = read(sockfd, buff, sizeof(buff));
	cout<<string(buff)<<endl;
    return 0;
}
