/*#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "../Enregistrement.h"
#include "../BDD.h"
#include "../Collecteur.h"
#include "../Logger.h"

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
	//------------------------

	//Déclaration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();

		//-----------------------------------
    string mon_fichier = "/home/pi/test.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //d�claration du flux et ouverture du fichier
	//-----------------------------------
	cout<<HTTPHTMLHeader();
			//--------------------------Recuperation latitude -------------------------
			form_iterator fvalue = cgi.getElement("latitude"); //Récupération valeur du champs "lattitude" 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
				fichier << "La latitude est : " << **fvalue << endl;
				aLatitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for latitude" << endl; //Retourne ce texte si aucune valeur n'est entrée 

			//--------------------------R�cup�ration longitude ---------------------------
			fvalue = cgi.getElement("longitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
								fichier << "La longitude est : " << **fvalue << endl; 
				aLongitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for longitude" << endl; 
			//--------------------------R�cup�ration  altitude -----------------------------
			fvalue = cgi.getElement("altitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
								fichier << "L'altitude est : " << **fvalue << endl; 
				aAltitude = atoi((**fvalue).c_str()); // atof => convertit un string en int 
			} 
			else 
				fichier << "No text entered for altitude" << endl; 

			//--------------------------R�cup�ration typeLampadaire -------------------------
			fvalue = cgi.getElement("typeLampadaire"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				streetlight = **fvalue;
			} 
			
			//--------------------------R�cup�ration ulor -------------------------
			fvalue = cgi.getElement("ulor"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				ULOR = atoi((**fvalue).c_str()); // atoi => convertit un string en int  
			} 
			else ULOR = 0;


			//--------------------------R�cup�ration typeAmpoule -------------------------
			fvalue = cgi.getElement("typeAmpoule"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				lamp = **fvalue; 
			} 
			
			//--------------------------R�cup�ration hauteur -------------------------
			fvalue = cgi.getElement("hauteur"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				height = **fvalue;
			} 

			//--------------------------R�cup�ration puissance -------------------------
			fvalue = cgi.getElement("puissance"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				power = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else power = 0;
			
			//--------------------------R�cup�ration albedo -------------------------
			fvalue = cgi.getElement("albedo"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				albedo = **fvalue;
			} 
			

			//--------------------------R�cup�ration agglomeration -------------------------
			fvalue = cgi.getElement("agglomeration"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				town = **fvalue;
			} 
		
			//--------------------------R�cup�ration rue -------------------------
			fvalue = cgi.getElement("rue"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
 
				street = **fvalue;
			} 

			//--------------------------R�cup�ration notes -------------------------
			fvalue = cgi.getElement("notes"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aNotes = **fvalue;
			} 
			
			//--------------------------R�cup�ration fluxlum -------------------------
			fvalue = cgi.getElement("fluxlum"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				fluxLum = **fvalue;
			} 


			//--------------------------R�cup�ration nbImage -------------------------
			fvalue = cgi.getElement("nbImage"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aNbImages = atoi((**fvalue).c_str()); // atoi => convertit un string en int
			} 
			else aNbImages=0;


			//--------------------------R�cup�ration date -------------------------
			fvalue = cgi.getElement("date"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aDate=(**fvalue).c_str(); // atoi => convertit un string en int
			} 
			
			//--------------------------Recuperation heure -----------------------
			fvalue = cgi.getElement("heure");
			if( !fvalue->isEmpty() && fvalue !=(*cgi).end()){
				aHeure=(**fvalue).c_str(); //convertir un string en int
			} 
		
			//fichier<<"\r\n" << env.getPostData(); no treated
	//			albedo="0.5";
	//fluxLum="210";
	//aIdRaspberry="0000112354e";
	//lamp="incandescente";
	//streetlight="lampadaire sur pied";
	//height="5";
	//power=2;
	//aLatitude = -41.123512;
	//aLongitude=-120.123561;
	//aAltitude=10;
	//aNbImages=2;
	//town="Hong kong";
	//aNotes="";
	//street="jdfglkj";
	//ULOR=53;
	//aDate="120619";


			//Instanciation des classes Enregistrement.cpp BDD.cpp et Collecteur.cpp
			Enregistrement* enregistrement = new Enregistrement(albedo, fluxLum, lamp,  streetlight,height, aLatitude,  
				aLongitude, aAltitude, aNbImages, town,  street,  ULOR, aDate, aHeure, aNotes, power);


			Collecteur* monCollecteur = new Collecteur();


			//Enregistrement dans la BDD
			enregistrement=monCollecteur->creerEnregistrement(enregistrement);



						fichier<<endl;
			fichier<<"ENREGISTREMENT EFFECTUÉ OK"<<endl;
	           fichier.close();  // on referme le fichier
			//----------------------------------------------------------------------
			/*	string identifiantCollecteur;
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
	int aNbImages;
	string town;
	string aNotes;
	string street;
	int ULOR;
	string aDate;*/
		/*	char longitude[12];
			char latitude[12];
			char altitude[5];
			char date[6];
			char heure[6]; 

			//retour nouvel enregistrement
			cout<<"{\n\t\"ID\":\""<<enregistrement->getIdentifiant()<<"\",";
			
			enregistrement->getLampadaire(streetlight,height,ULOR,albedo);
			enregistrement->getAmpoule(lamp,fluxLum,power);
			cout<<"\n\t\t\t\"POWER\":\""<<power<<"\",";
			cout<<"\n\t\t\t\"ALBEDO\":\""<<albedo<<"\",";
			cout<<"\n\t\t\t\"FLUX\":\""<<fluxLum<<"\",";
			cout<<"\n\t\t\t\"BUBOID\":\""<<enregistrement->getBuboID() <<"\",";
			cout<<"\n\t\t\t\"LAMP\":\""<<lamp <<"\",";
			cout<<"\n\t\t\t\"STREETLIGHT\":\""<<streetlight <<"\",";
			cout<<"\n\t\t\t\"HEIGHT\":\""<<height <<"\",";

			enregistrement->getGeolocalisation(latitude,longitude, altitude);
			string laLongitude=longitude; 
			string laLatitude=latitude;
			string lAltitude = altitude;
			cout<<"\n\t\t\t\"LATITUDE\":\""<<laLatitude <<"\",";
			cout<<"\n\t\t\t\"LONGITUDE\":\""<<laLongitude <<"\",";
			cout<<"\n\t\t\t\"ALTITUDE\":\""<<lAltitude <<"\",";

			enregistrement->getGalerie(aNbImages);
			cout<<"\n\t\t\t\"NBIMAGES\":\""<<aNbImages <<"\",";
			town = enregistrement->getAgglomeration();
			cout<<"\n\t\t\t\"TOWN\":\""<<town <<"\",";
			street = enregistrement->getRue();
			cout<<"\n\t\t\t\"STREET\":\""<<street <<"\",";
			cout<<"\n\t\t\t\"ULOR\":\""<<ULOR<<"\",";
			
                        enregistrement->getHorodatage(date);
			 string laDate(date, 6); 
			cout<<"\n\t\t\t\"DATE\":\""<<laDate<<"\",";
                        
                        enregistrement->getHorodatage2(heure); 
                        string leHeure(heure, 6); 
                        cout<<"\n\t\t\t\"HEURE\":\""<<leHeure<<"\",";
                        
 			aNotes=enregistrement->getNotes();
			cout<<"\n\t\t\t\"NOTES\":\""<<aNotes<<"\"";
			
                        cout<<"\n\t\t}\n";
			system("sqlite3 /home/pi/bdd/Enregistrement.db < /home/pi/ShelScript.txt");
			
                        system("sudo cp /usr/local/apache2/cgi-bin/bdd.txt /home/pi");
                        system("sudo cp /usr/local/apache2/cgi-bin/bdd.txt /usr/local/apache2/htdocs");
    return 0;
}*/
