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

#include <stdio.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/CgiEnvironment.h>
#include <cgicc/FormEntry.h>


#include "Geolocalisation.h"
#include "Collecteur.h"
#include "BDD.h"
#include "Enregistrement.h"
#include "Logger.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "Collecteur.h"

#include "Mail.h"
#include "GPS.h"

using namespace std;
using namespace cgicc;

int Collecteur::recupererIdentifiantRaspberry() {

    FILE * pFile;
    char buffer[1200];
    size_t result = 0, posSerial = 0;
    string match;

    pFile = fopen("/proc/cpuinfo", "r");
    if (pFile == NULL) {
        return PBACCESIDENT;
    }


    result = fread(buffer, 1, sizeof (buffer), pFile);
    if (result <= 0) {
        return PBLECTUREIDENT;
    }

    buffer[result] == '\0';

    match = string(buffer);
    posSerial = match.find("Serial");

    _identifiant = match.substr(posSerial + 10, 16);

    fclose(pFile);
    return 1;
}

string Collecteur::getIdentifiant() {
    return _identifiant;
}

Collecteur::Collecteur() {
    recupererIdentifiantRaspberry();
    BDD * laBDD = new BDD();
    listeEnregistrements = laBDD->obtenirListeDesEnregistrements();
    unGPS = new GPS();
}

Enregistrement* Collecteur::creerEnregistrement(Enregistrement *aDonnee) {
  BDD* maBDD = new BDD();
    Enregistrement* dernierEnregistrement = maBDD->sauvegarderDonneesEnregistrement(aDonnee, _identifiant);

	listeEnregistrements.insert(listeEnregistrements.begin(), dernierEnregistrement);

    //Enregistrement dans la BDD
    return dernierEnregistrement;
}

void Collecteur::creerEnregistrementVirtuel() {
    this->listeEnregistrements.push_back(new Enregistrement(unGPS));

    //Non gestion de l'identifiant--------------
    //if (!listeEnregistrements.empty()) {
    //	listeEnregistrements.back()->creerIdentifiant();
    //}
}

void Collecteur::supprimerEnregistrementVirtuel() {
    this->listeEnregistrements.pop_back();
}

void Collecteur::modifier(Enregistrement* aDonnee) {
    string lamp;
    string streetlight;
    string height;
    int ULOR;
    int power;
    string albedo;
    string fluxLum;
    int nbimages;
    char date [6];
    char heure [6];
    char longitude[12];
    char latitude[12];
    char altitude[5];
    int identifiantE;
    string town;
    string street;
    string notes;
    identifiantE = aDonnee->getIdentifiant();
    aDonnee->getLampadaire(streetlight, height, ULOR, albedo);
    aDonnee->getAmpoule(lamp, fluxLum, power);
    aDonnee->getGeolocalisation(latitude, longitude, altitude);
    string laLongitude = longitude;
    string laLatitude = latitude;
    string laAltitude = altitude;
    aDonnee->getGalerie(nbimages);
    town = aDonnee->getAgglomeration();

    aDonnee->getHorodatage(date);
    aDonnee->getHorodatage2(heure);

    string laDate(date, 6);
    string leHeure(heure, 6);
    notes = aDonnee->getNotes();
    BDD * laBDD = new BDD();
    laBDD->modifierEnregistrement(identifiantE, power, albedo, fluxLum, aDonnee->getBuboID(), lamp, streetlight,
            height, atof(latitude), atof(longitude), atoi(altitude), nbimages, town, aDonnee->getRue(), ULOR, laDate, leHeure, notes);
    if (!listeEnregistrements.empty()) {
        for (std::vector<Enregistrement*>::iterator it = listeEnregistrements.begin(); it != listeEnregistrements.end(); ++it) {
            if (identifiantE == ((Enregistrement*) * it)->getIdentifiant()) {
                this->listeEnregistrements.erase(it);
                this->listeEnregistrements.insert(it, aDonnee);
            }

        }
    }
}

bool Collecteur::supprimerEnregistrement(int ID) {
    int identifiantE;
    if (!listeEnregistrements.empty()) {
        for (std::vector<Enregistrement*>::iterator it = listeEnregistrements.begin(); it != listeEnregistrements.end(); ++it) {
            identifiantE = ((Enregistrement*) * it)->getIdentifiant();
            if (identifiantE == ID) {
                this->listeEnregistrements.erase(it);
                break;
            }
        }
        BDD * laBDD = new BDD();
        return laBDD->supprimerEnregistrement(ID);
    }
}

string Collecteur::geolocaliser() {

    char laLatitude[12] = {0};
    char laLongitude[12] = {0};
    char laAltitude[5] = {0};
    char lesSatellites[3] = {0};
    char HDOP[5] = {0};
    char laDate[6] = {0};
    char leHeure[6] = {0};
    int erreur = 0;
    string retour = "";
    if (!listeEnregistrements.empty()) {
        erreur = listeEnregistrements.back()->localiser();

        listeEnregistrements.back()->getGeolocalisation(laLatitude, laLongitude, laAltitude);
        listeEnregistrements.back()->getGeolocalisation()->getSatellite(lesSatellites);
        listeEnregistrements.back()->getGeolocalisation()->getHDOP(HDOP);
        string Longitude(laLongitude);
        //for (int i=0;i<10;i++)
        //{
        //	Longitude+=laLongitude[i];
        //}
        //Longitude=Longitude;

        string Latitude(laLatitude);
        //string Latitude="";
        //for (int i=0;i<10;i++)
        //{

        //	Latitude+=laLatitude[i];
        //}
        //Latitude = Latitude;
        string lAltitude(laAltitude);
        string erreurS = to_string(erreur);
        string nbreAcqui = to_string(listeEnregistrements.back()->getGeolocalisation()->getNbreAcquisition());

        retour = retour + "{\n\t\"LATITUDE\":\"" + Latitude + "\",\n";
        retour = retour + "\t\"LONGITUDE\":\"" + Longitude + "\",\n";
        retour = retour + "\t\"ALTITUDE\":\"" + lAltitude + "\",\n";
        retour = retour + "\t\"FIX\":\"" + listeEnregistrements.back()->getGeolocalisation()->getFIX() + "\",\n";
        retour = retour + "\t\"SATELLITES\":\"" + lesSatellites + "\",\n";
        retour = retour + "\t\"HDOP\":\"" + HDOP + "\",\n";
        retour = retour + "\t\"ACQUISITIONS\":\"" + nbreAcqui + "\",\n";
        retour = retour + "\t\"ERREUR\":\"" + erreurS + "\",\n";
      
        
        listeEnregistrements.back()->getHorodatage(laDate);
        listeEnregistrements.back()->getHorodatage2(leHeure);

        
        string date="";
		for(int i=0;i<6;i++)
 		{
			date+=laDate[i];
		}
		date=string(laDate,6);
		retour =retour +"\t\"DATE\":\""+date+"\",\n";

        
        
        string heure="";
		for(int i=0;i<6;i++)
 		{
			heure+=leHeure[i];
		}
		heure=string(leHeure,6);
		retour =retour +"\t\"HEURE\":\""+heure+"\"\n}\n";

        
        
        


    }
    return retour;

}

/***
 * A corriger car erron�, faux : onne doit pas faire listeEnregistrements.back()->localiser(); mais
 * r�cup�rer l'enregistrement dont l'identifiant est pass� en param�tre
 **/
string Collecteur::geolocaliser(int identifiant) {

    char laLatitude[10];
    char laLongitude[10];
    char laAltitude[4];
    char laDate[6];
    char leHeure[6];
    int erreur = 0;
    int identifiantE;
    string retour;
    if (!listeEnregistrements.empty()) {
        for (std::vector<Enregistrement*>::iterator it = listeEnregistrements.begin(); it != listeEnregistrements.end(); ++it) {
            identifiantE = ((Enregistrement*) * it)->getIdentifiant();
            if (identifiantE == identifiant) {
                ((Enregistrement*) * it)->localiser();


                listeEnregistrements.back()->getGeolocalisation(laLatitude, laLongitude, laAltitude);
                string Longitude = "";
                for (int i = 0; i < 10; i++) {
                    Longitude += laLongitude[i];
                }
                Longitude = Longitude;

                string Latitude = "";
                for (int i = 0; i < 10; i++) {

                    Latitude += laLatitude[i];
                }

                Latitude = Latitude;
                string Altitude = "";
                for (int i = 0; i < 10; i++) {
                    Altitude += laAltitude[i];
                }
                Altitude = Altitude;
                retour = retour + "{\n\t\"LATITUDE\":\"" + Latitude + "\",\n";
                retour = retour + "\t\"LONGITUDE\":\"" + Longitude + "\",\n";
                retour = retour + "\t\"ALTITUDE\":\"" + Altitude + "\",\n";
                //-------------------------------------------------------//
                     
                 listeEnregistrements.back()->getHorodatage(laDate);
				string date="";
				for(int i=0;i<6;i++)
 				{
					date+=laDate[i];
				}
				date=string(laDate,6);
				retour =retour +"\t\"DATE\":\""+date+"\"\n}\n";
                                
                                
                     listeEnregistrements.back()->getHorodatage(leHeure);
				string heure="";
				for(int i=0;i<6;i++)
 				{
					heure+=leHeure[i];
				}
				heure=string(leHeure,6);
				retour =retour +"\t\"HEURE\":\""+heure+"\"\n}\n";
                                
            
            }
        }
    }
    return retour;

}

string Collecteur::obtenirIntensiteLumineuse() {
    float lIntensiteLumineuse;
    int erreur = 0;
    if (!listeEnregistrements.empty()) {
        erreur = listeEnregistrements.back()->caracteriserAmpoule(lIntensiteLumineuse);
    }
    return "{\"luminosite\":\"" + to_string(lIntensiteLumineuse) + "\"}";
}

string Collecteur::obtenirIntensiteLumineuse(int identifiant) {

    return "eeeeeeeeeeeeeeeee";
}

vector<Enregistrement*> Collecteur::getlisteEnregistrements() {
    return this->listeEnregistrements;
}

vector<Enregistrement*> Collecteur::chercherEnregistrements() {

    int erreur = 0;
    char latitudeEnreg[12] = {0};
    char longitudeEnreg[12] = {0};
    char latitudeActuelle[12] = {0};
    char longitudeActuelle[12] = {0};
    char altitudeEnreg[5] = {0};
    char altitudeActuelle[5] = {0};
    int digit, i;
    bool lampProche = false;
    creerEnregistrementVirtuel();
    do {
        erreur = listeEnregistrements.back()->localiserSF();
    } while (erreur < 0);

    listeEnregistrements.back()->getGeolocalisation(latitudeActuelle, longitudeActuelle, altitudeActuelle);
    for (std::vector<Enregistrement*>::iterator it = listeEnregistrements.begin(); it != listeEnregistrements.end() - 1; ++it) {
        ((Enregistrement*) * it)->getGeolocalisation(latitudeEnreg, longitudeEnreg, altitudeEnreg);
        digit = 0;
        i = 0;
        lampProche = false;
        do {
            if (latitudeActuelle[i] == latitudeEnreg[i]) {
                digit = digit + 1;
                if (latitudeActuelle[i] == 46) digit = 0;
                i = i + 1;
                lampProche = true;
            } else lampProche = false;
            if ((digit == 3) && (latitudeEnreg[i] >= latitudeActuelle[i] - 1) && (latitudeEnreg[i] <= latitudeActuelle[i] + 1)) {
                lampProche = true;
                digit = digit + 1;
            }
        } while ((digit < 4) && (lampProche == true));
        if (lampProche == true) {
            digit = 0;
            i = 0;
            lampProche = false;
            do {
                if (longitudeActuelle[i] == longitudeEnreg[i]) {
                    digit = digit + 1;
                    if (longitudeActuelle[i] == 46) digit = 0;
                    i = i + 1;
                    lampProche = true;
                } else lampProche = false;
                if ((digit == 3) && (longitudeEnreg[i] >= longitudeActuelle[i] - 1) && (longitudeEnreg[i] <= longitudeActuelle[i] + 1)) {
                    lampProche = true;
                    digit = digit + 1;
                }

            } while ((digit < 4) && (lampProche == true));
        }

        if (lampProche == true) _lampadairesProches.push_back(((Enregistrement*) * it));

    }
    listeEnregistrements.pop_back();
    return _lampadairesProches;

}

bool Collecteur::viderTable() {
    BDD * laBDD = new BDD();
    bool result = laBDD->viderTable();

    if (result && (!listeEnregistrements.empty())) {
        listeEnregistrements.clear();
    }
    return result;
}

int Collecteur::envoyerbdd() {
    Mail * unMail = new Mail();
    int testerreur = unMail->envoimail();
    return testerreur;
}

int Collecteur::mettreCollecteurAJour() {

    /* --------- Récupération de l'heure ------------*/

    Geolocalisation*geolocalisation = new Geolocalisation(unGPS);
    Horodatage*horodatage = new Horodatage(unGPS);

  

    char tableau [6]; //création du tableau qui va stocker la date
    horodatage->dater();


    horodatage->getDate(tableau); //on récupère la date
    string date1 = "20";
    char date2 = tableau[4];
    char date3 = tableau[5];
    string date4 = "-";
    char date5 = tableau[2];
    char date6 = tableau[3];
    string date7 = "-";
    char date8 = tableau[0];
    char date9 = tableau[1];

    string date = date1 + date2 + date3 + date4 + date5 + date6 + date7 + date8 + date9;

    horodatage->getHeure(tableau); //on récupère l'heure
    string heure0 = " ";
    char heure1 = tableau[0];
    char heure2 = tableau[1];
    string heure3 = ":";
    char heure4 = tableau[2];
    char heure5 = tableau[3];
    string heure6 = ":";
    char heure7 = tableau[4];
    char heure8 = tableau[5];

    string heure = heure0 + heure1 + heure2 + heure3 + heure4 + heure5 + heure6 + heure7 + heure8;

    /* --------- ajout de la date et de l'heure dans une même variable ------------*/
    string date_heure;
    string date_heureBDD;

    string crochet = "'";
    dateHeureBDD = date + heure;
    cout << dateHeureBDD;
    string hour;
    hour = dateHeureBDD; //variable hour = à l'attribut 
    date_heure = "sudo date --set " + crochet + date + heure + crochet;
    cout << " date_heureBDD -> " << date_heureBDD << endl; //permet d'afficher date_heureBDD que je vais intégrer dans la base de données


    /* --------- conversion de date_heure en char* ------------*/

    size_t size = date_heure.size() + 1; // créer le buffer pour copier la chaîne
    char * buffer = new char[ size ];
    strncpy(buffer, date_heure.c_str(), size); // copier la chaîne 




    /* --------- mise à jour de la date et de l'heure ---------------*/
    system("sudo timedatectl set-ntp false"); // ici on désactive 

    system(buffer);
    //system("date");
    return 0;
    delete [] buffer; // libérer la mémoire 


}

string Collecteur::getdateHeureBDD() {
    return dateHeureBDD;
}

void Collecteur::setdateHeureBDD(string hour) {
    this->dateHeureBDD = hour;

}
