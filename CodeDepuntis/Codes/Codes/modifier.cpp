#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <string>
#include <fstream>
#include "Enregistrement.h"
#include <stdio.h>
#include "Collecteur.h"


#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/CgiEnvironment.h>
#include <cgicc/FormEntry.h>


using namespace std;
using namespace cgicc;

int main(){
	//Déclaration des variables
	string identifiantCollecteur;
	int aId;
	string aAlbedo;
	string aFluxLum;
	string aIdRaspberry;
	string aTypeAmpoule;
	string aTypeLampadaire;
	string aHauteur;
	int puissance;
	double aLatitude;
	double aLongitude;
	int aAltitude;
	int aNbImages;
	string aAgglo;
	string aNotes;
	string aRue;
	int aUlor;
	string aDate;
        string aHeure;
	//------------------------

	//Déclaration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();
	//-----------------------------------
	string mon_fichier = "/home/pi/test.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //d�claration du flux et ouverture du fichier
	cout<<HTTPHTMLHeader();
    if(fichier)  // si l'ouverture a r�ussi
        {
			//--------------------------R�cup�ration latitude -------------------------
			form_iterator fvalue = cgi.getElement("latitude"); //Récupération valeur du champs "lattitude" 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
				fichier << "La latitude est : " << **fvalue << endl;
				aLatitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for latitude" << endl; //Retourne ce texte si aucune valeur n'est entrée 

			//--------------------------R�cup�ration longitude -------------------------
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
				fichier << "Le typeLampadaire est : " << **fvalue << endl; 
				aTypeLampadaire = **fvalue;
			} 
			else 
			{
				aTypeLampadaire = " ";
				fichier << "No text entered for typeLampadaire" << endl; 		
			}
			//--------------------------R�cup�ration ulor -------------------------
			fvalue = cgi.getElement("ulor"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'ulor est : " << **fvalue << endl;
				aUlor = atoi((**fvalue).c_str()); // atoi => convertit un string en int  
			} 
			else 
			{
				aUlor = 0;
				fichier << "No text entered for ulor value : "<<aUlor  << endl; 

			}

			//--------------------------R�cup�ration typeAmpoule -------------------------
			fvalue = cgi.getElement("typeAmpoule"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le typeAmpoule est : " << **fvalue << endl; 
				aTypeAmpoule = **fvalue; 
			} 
			else 
			{
				fichier << "No text entered for typeAmpoule" << endl; 
				aTypeAmpoule = " ";
			}
			//--------------------------R�cup�ration hauteur -------------------------
			fvalue = cgi.getElement("hauteur"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La hauteur est : " << **fvalue << endl; 
				aHauteur = **fvalue;
			} 
			else 
			{
				aHauteur = " ";
				fichier << "No text entered for hauteur : "<< aHauteur << endl; 
			}
			//--------------------------R�cup�ration puissance -------------------------
			fvalue = cgi.getElement("puissance"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La puissance est : " << **fvalue << endl;
				puissance = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else 
			{
				puissance = 0;
				fichier << "No text entered for puissance : "<< puissance << endl; 			

			}
			//--------------------------R�cup�ration albedo -------------------------
			fvalue = cgi.getElement("albedo"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'albedo est : " << **fvalue << endl; 
				aAlbedo = **fvalue;
			} 
			else 
			{
				aAlbedo = " ";
				fichier << "No text entered for albedo" << endl; 
			}

			//--------------------------R�cup�ration agglomeration -------------------------
			fvalue = cgi.getElement("agglomeration"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'agglomeration est : " << **fvalue << endl; 
				aAgglo = **fvalue;
			} 
			else 
				fichier << "No text entered for agglomeration" << endl; 			
			//--------------------------R�cup�ration rue -------------------------
			fvalue = cgi.getElement("rue"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La rue est : " << **fvalue << endl; 
				aRue = **fvalue;
			} 
			else 
				fichier << "No text entered for rue" << endl; 
			//--------------------------R�cup�ration notes -------------------------
			fvalue = cgi.getElement("notes"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Les notes sont : " << **fvalue << endl; 
				aNotes = **fvalue;
			} 
			else 
				fichier << "No text entered for notes" << endl; 			
			//--------------------------R�cup�ration fluxlum -------------------------
			fvalue = cgi.getElement("fluxlum"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le fluxlum est : " << **fvalue << endl;
				aFluxLum = **fvalue; 
			} 
			else 
			{
				aFluxLum = " ";
				fichier << "No text entered for fluxlum" << endl; 
			}

			//--------------------------R�cup�ration nbImage -------------------------
			fvalue = cgi.getElement("nbImage"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le nbImage est : " << **fvalue << endl; 
				aNbImages = atoi((**fvalue).c_str()); // atoi => convertit un string en int
			} 
			else 
				fichier << "No text entered for nbImage" << endl; 
			//--------------------------R�cup�ration date -------------------------
			fvalue = cgi.getElement("date"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le date est : " << **fvalue << endl; 
				aDate = **fvalue; 
			} 
			else 
				fichier << "No text entered for date" << endl; 
                        
                        //--------------------------R�cup�ration heure -------------------------
			fvalue = cgi.getElement("heure"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le heure est : " << **fvalue << endl; 
				aHeure = **fvalue; 
			} 
			else 
				fichier << "No text entered for heure" << endl; 
			//--------------------------R�cup�ration ID -------------------------
			fvalue = cgi.getElement("ID"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'ID BDD est : " << **fvalue << endl; 
				aId = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else 
				fichier << "No text find for ID" << endl; 
			//fichier<<"\r\n" << env.getPostData(); no treated

			//Instanciation des classes Collecteur.cpp
			Collecteur* monCollecteur = new Collecteur();

			//----------------------------------------------------------------------

			//Récupération ID de la R-PI
			monCollecteur->recupererIdentifiantRaspberry();
			identifiantCollecteur = monCollecteur->getIdentifiant();
			//----------------------------------------------------------------------

			Enregistrement* enregistrement = new Enregistrement(aId, aAlbedo, aFluxLum, identifiantCollecteur, aTypeAmpoule, aTypeLampadaire, aHauteur, aLatitude,  aLongitude, aAltitude, aNbImages, aAgglo, aRue, aUlor, aDate, aHeure, aNotes, puissance);
			monCollecteur->modifier(enregistrement);

							fichier << "Record close" << endl; 
	}
}

