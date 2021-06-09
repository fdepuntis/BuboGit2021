//g++ Serveur.cpp Collecteur.cpp Enregistrement.cpp -o Serveur
//https://programmer.help/blogs/an-example-of-c-socket-programming-under-linux.html
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string> 
#include <cstring>
#include <sys/socket.h> 
#include <sys/types.h>
#include <vector>
#include <iostream> 
//#include "rapidjson/writer.h"
//#include "rapidjson/document.h"
//#include "rapidjson/stringbuffer.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/JSON/Stringifier.h"
#include "Enregistrement.h"
#include "Collecteur.h"
#define MAX 1048576 //ATTENTION! Taille à gérer
#define PORT 7256 
#define SA struct sockaddr 

using namespace std;

// Driver function 

int main() {
    int sockfd, connfd, tailleMessage;
    socklen_t len;
    string laCommande = "";
    string response;
    Collecteur *leCollecteur = new Collecteur();
    leCollecteur->mettreCollecteurAJour();
    struct sockaddr_in servaddr, cli;
    char buff[MAX];
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else
        printf("Socket successfully created..\n");
    memset(&servaddr, 0, sizeof (servaddr));

    // assign IP, PORT 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*) & servaddr, sizeof (servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	} else
		printf("Socket successfully binded..\n");
	do {
		// Now server is ready to listen and verification 
		if ((listen(sockfd, 5)) != 0) {
			printf("Listen failed...\n");
			exit(0);
		} else
			printf("Server listening..\n");
		len = sizeof (cli);

		// Accept the data packet from client and verification 
		connfd = accept(sockfd, (SA*) & cli, &len);
		if (connfd < 0) {
			printf("server acccept failed...\n");
			exit(0);
		} else
			printf("server acccept the client...\n");

		// Function for chatting between client and server 
		memset(buff, 0, MAX);

		// read the message from client and copy it in buffer 
		recv(connfd, buff, sizeof (buff), 0);
		/*for (int i=0;i<MAX;i++)
				if (buff[i]!=0) laCommande = laCommande + buff[i];
				else break;*/
		laCommande = string(buff);
		cout << laCommande << endl;
		size_t found = laCommande.find("localiser");
		if (found != std::string::npos) {
			leCollecteur->creerEnregistrementVirtuel();
			response = leCollecteur->geolocaliser();
			leCollecteur->supprimerEnregistrementVirtuel();
		}
		 found = laCommande.find("listerEnregistrement");
		if (found != std::string::npos) {
			vector<Enregistrement*> laListeEnregistrements = leCollecteur->getlisteEnregistrements();
			response="{\"enregistrement\":\n\t[";
			if (!laListeEnregistrements.empty())
			{
				for (std::vector<Enregistrement*>::iterator it = laListeEnregistrements.begin() ; it != laListeEnregistrements.end(); ++it)
				{

					response+="\n\t\t";
					string lamp;
  					string streetlight;
					string height;
					int ULOR;
					int power;
					string  albedo;
					string fluxLum;
					int nbimages;
					char date [7];
								char heure [7]; 
					char longitude[12];
					char latitude[12];
					char altitude[5];
					int identifiantE;
					string  town;
					string  street;
					string notes;
					identifiantE = ((Enregistrement*)*it)->getIdentifiant();
					Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
					json->set("ID", to_string(identifiantE));
                                        //response+="\n\t\t\t\"ID\":\""+to_string(identifiantE)+"\",";

                                        ((Enregistrement*)*it)->getLampadaire(streetlight,height,ULOR,albedo);
                                        ((Enregistrement*)*it)->getAmpoule(lamp,fluxLum,power);
                                        json->set("POWER", to_string(power));
                                        //response+="\n\t\t\t\"POWER\":\""+to_string(power)+"\",";
                                        json->set("ALBEDO", albedo);
                                        //response+="\n\t\t\t\"ALBEDO\":\""+albedo+"\",";
                                        json->set("FLUX", fluxLum);
                                        //response+="\n\t\t\t\"FLUX\":\""+fluxLum+"\",";
                                        json->set("BUBOID", ((Enregistrement*)*it)->getBuboID());
                                        //response+="\n\t\t\t\"BUBOID\":\""+((Enregistrement*)*it)->getBuboID() +"\",";
                                        json->set("LAMP", lamp);
                                        //response+="\n\t\t\t\"LAMP\":\""+lamp +"\",";
                                        json->set("STREETLIGHT", streetlight);
                                        //response+="\n\t\t\t\"STREETLIGHT\":\""+streetlight +"\",";
                                        json->set("HEIGHT", height);
                                        //response+="\n\t\t\t\"HEIGHT\":\""+height +"\",";

                                        ((Enregistrement*)*it)->getGeolocalisation(latitude,longitude, altitude);
                                        string laLongitude=longitude; 
                                        string laLatitude=latitude;
                                        string lAltitude=altitude;
                                        json->set("LATITUDE", laLatitude);
                                        //response+="\n\t\t\t\"LATITUDE\":\""+laLatitude +"\",";
                                        json->set("LONGITUDE", laLongitude);
                                        //response+="\n\t\t\t\"LONGITUDE\":\""+laLongitude +"\",";
                                        json->set("ALTITUDE", lAltitude);
                                        //response+="\n\t\t\t\"ALTITUDE\":\""+lAltitude +"\",";

                                        ((Enregistrement*)*it)->getGalerie(nbimages);
                                        json->set("NBIMAGES", to_string(nbimages));
                                        //response+="\n\t\t\t\"NBIMAGES\":\""+to_string(nbimages) +"\",";
                                        town = ((Enregistrement*)*it)->getAgglomeration();
                                        json->set("TOWN", town);
                                        //response+="\n\t\t\t\"TOWN\":\""+town +"\",";
                                        street = ((Enregistrement*)*it)->getRue();
                                        json->set("STREET", street);
                                        //response+="\n\t\t\t\"STREET\":\""+street +"\",";
                                        json->set("ULOR", to_string(ULOR));
                                        //response+="\n\t\t\t\"ULOR\":\""+to_string(ULOR)+"\",";

                                                                ((Enregistrement*)*it)->getHorodatage(date);
                                        string laDate(date, 6);
                                        json->set("DATE", laDate);
                                        //response+="\n\t\t\t\"DATE\":\""+laDate+"\",";

                                                                ((Enregistrement*)*it)->getHorodatage2(heure);
                                                                string leHeure(heure, 6);
                                         json->set("HEURE", leHeure);
                                        //response+="\n\t\t\t\"HEURE\":\""+leHeure+"\",";

                                        notes=((Enregistrement*)*it)->getNotes();
                                        json->set("NOTES", notes);
                                        //response+="\n\t\t\t\"NOTES\":\""+notes+"\"";
                                        //response+="\n\t\t}";
					 std::ostringstream oss;
                               		 Poco::JSON::Stringifier::stringify(json, oss);
                               		 response+=oss.str();
					if (!(it+1 == laListeEnregistrements.end())) response+=",";
				}
			}
			else printf("Base is empty...\n");
				response+="\n\t]\n}";

		}
		found = laCommande.find("enregistrer");
		if (found != std::string::npos) {
			string lamp;
  			string streetlight;
			string height;
			int ULOR;
			int power;
			string  albedo;
			string fluxLum;
			int nbimages;
			char date [7];
			char heure [7]; 
			char longitude[12];
			char latitude[12];
			char altitude[5];
			int identifiantE;
			string  town;
			string  street;
			string notes;
			string lEnregistrement = laCommande.substr (found+11);

			Poco::JSON::Parser lAnalyseur;
			Poco::DynamicAny result = lAnalyseur.parse(lEnregistrement);
			Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
									cout<<"Objet JSON extrait"<<endl;
			//string name = object->get("ALBEDO");
			//cout<<"bubo ID :" << name<<endl;
					//Instanciation des classes Enregistrement.cpp BDD.cpp et Collecteur.cpp

			Enregistrement* enregistrement = new Enregistrement(object->get("ALBEDO"), object->get("FLUX"), object->get("LAMP"),   object->get("STREETLIGHT"),
				object->get("HEIGHT"), object->get("LATITUDE"), object->get("LONGITUDE"), object->get("ALTITUDE"), object->get("NBIMAGES"), object->get("TOWN"),
				object->get("STREET"),  object->get("ULOR"), object->get("DATE"), object->get("HEURE"),
				object->get("NOTES"), object->get("POWER"));

			//Enregistrement dans la BDD
			enregistrement=leCollecteur->creerEnregistrement(enregistrement);
			Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
			json->set("ID", to_string(enregistrement->getIdentifiant()));
			

				//response="{\n\t\"ID\":\""+to_string(enregistrement->getIdentifiant())+"\",";
			
				enregistrement->getLampadaire(streetlight,height,ULOR,albedo);
				enregistrement->getAmpoule(lamp,fluxLum,power);
				json->set("POWER", to_string(power));
				//response+= "\n\t\t\t\"POWER\":\""+to_string(power)+"\",";
				json->set("ALBEDO", albedo);
				//response+= "\n\t\t\t\"ALBEDO\":\""+albedo+"\",";
				json->set("FLUX", fluxLum);
				//response+= "\n\t\t\t\"FLUX\":\""+fluxLum+"\",";
				json->set("BUBOID", enregistrement->getBuboID());
				//response+= "\n\t\t\t\"BUBOID\":\""+enregistrement->getBuboID() +"\",";
				json->set("LAMP", lamp);
				//response+= "\n\t\t\t\"LAMP\":\""+lamp +"\",";
				json->set("STREETLIGHT", streetlight);
				//response+= "\n\t\t\t\"STREETLIGHT\":\""+streetlight+"\",";
				json->set("HEIGHT", height);
				//response+= "\n\t\t\t\"HEIGHT\":\""+height +"\",";

				enregistrement->getGeolocalisation(latitude,longitude, altitude);
				string laLongitude=longitude; 
				string laLatitude=latitude;
				string lAltitude = altitude;
				json->set("LATITUDE", laLatitude);
				//response+= "\n\t\t\t\"LATITUDE\":\""+laLatitude +"\",";
				json->set("LONGITUDE", laLongitude);
				//response+= "\n\t\t\t\"LONGITUDE\":\""+laLongitude +"\",";
				json->set("ALTITUDE", lAltitude);
				//response+= "\n\t\t\t\"ALTITUDE\":\""+lAltitude +"\",";

				enregistrement->getGalerie(nbimages);
				json->set("NBIMAGES", to_string(nbimages));
				//response+= "\n\t\t\t\"NBIMAGES\":\""+to_string(nbimages) +"\",";
				town = enregistrement->getAgglomeration();
				json->set("TOWN", town);
				//response+= "\n\t\t\t\"TOWN\":\""+town +"\",";
				street = enregistrement->getRue();
				json->set("STREET", street);
				//response+= "\n\t\t\t\"STREET\":\""+street +"\",";
				json->set("ULOR", to_string(ULOR));
				//response+= "\n\t\t\t\"ULOR\":\""+to_string(ULOR)+"\",";
			
				enregistrement->getHorodatage(date);
				string laDate(date, 6); 
				json->set("DATE", laDate);
				//response+= "\n\t\t\t\"DATE\":\""+laDate+"\",";
                        
				enregistrement->getHorodatage2(heure); 
				string leHeure(heure, 6); 
				json->set("HEURE", leHeure);
				//response+= "\n\t\t\t\"HEURE\":\""+leHeure+"\",";
                        
 				notes=enregistrement->getNotes();
				json->set("NOTES", notes);
				//response+= "\n\t\t\t\"NOTES\":\""+notes+"\"";
			
				//response+= "\n\t\t}\n";
				std::ostringstream oss;
				Poco::JSON::Stringifier::stringify(json, oss);
				response=oss.str();
				system("sqlite3 /home/pi/bdd/Enregistrement.db < /home/pi/ShelScript.txt");
				//system("sudo cp /usr/local/apache2/cgi-bin/bdd.txt /home/pi");
				system("sudo cp bdd.txt /home/pi");
				//system("sudo cp /usr/local/apache2/cgi-bin/bdd.txt /usr/local/apache2/htdocs");
				system("sudo cp bdd.txt /usr/local/apache2/htdocs");
			lAnalyseur.reset();
		}
		/*found=laCommande.find("ViderTable");
		if (found!=std::string::npos)
		{
			response= leCollecteur ->viderTable();
		}
		found=laCommande.find("modifier");
		if (found!=std::string::npos)
		{
			response= leCollecteur ->modifier(Enregistrement *aDonnee);
		}
		found=laCommande.find("supprimer");
		if (found!=std::string::npos)
		{
			response= leCollecteur ->supprimerEnregistrement(int ID);
		}*/




		cout << response << endl;
		printf("A envoyer  : %s  \n", response.c_str());
		memset(buff, 0, MAX);
		cout << "octets à retourner = " << response.length() << endl; //ATTENTION! Réfléchir à la taille maximale à transmettre
		// and send that buffer to client 
		send(connfd, response.c_str(), response.length(), 0);
		close(connfd);
		sleep(2);
	}
	while(true);
    // After chatting close the socket 
    close(sockfd);
}
