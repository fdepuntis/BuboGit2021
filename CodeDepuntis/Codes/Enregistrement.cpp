/* Sans calcul d'identifiant*/
#include <exception>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#include "Enregistrement.h"

#include "../Codes/Lampadaire.h"
#include "../Codes/Galerie.h"
#include "../Codes/Geolocalisation.h"
#include "../Codes/Ampoule.h"
#include "../Codes/Horodatage.h"
#include "../Codes/GPS.h"
#include"../Codes/Logger.h" //x
#include "../Codes/Collecteur.h"

//Logger *monLogger=new Logger();

Enregistrement::Enregistrement(string aIdRaspberry, GPS * unGPS) {
    //monLogger->saveLog("tes");
    horodatage = new Horodatage(unGPS);
    geolocalisation = new Geolocalisation(unGPS);
    ampoule = new Ampoule();
    lampadaire = new Lampadaire();
    galerie = new Galerie();
}

Enregistrement::Enregistrement(GPS * unGPS) {
    horodatage = new Horodatage(unGPS);

    geolocalisation = new Geolocalisation(unGPS);
    ampoule = new Ampoule();
    _identifiant = "";
    lampadaire = new Lampadaire();
    galerie = new Galerie();
}

Enregistrement::Enregistrement(int aId, string aAlbedo, string aFluxLum, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude, double aLongitude, int aAltitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aHeure, string aNotes, int puissance) {
    horodatage = new Horodatage();
    geolocalisation = new Geolocalisation();
    ampoule = new Ampoule();
    this->_identifiant = aIdRaspberry;
    lampadaire = new Lampadaire();
    galerie = new Galerie();


    //il faut instancier et mettre les attributs de enregistrer dans les attributs private de enregistrement.h:

    char Latitude[12] = {};
    char Longitude[12] = {};
    char Altitude[5] = {};

    ID = aId;

    lampadaire->setAlbedo(aAlbedo); //dans lampadaire.h

    lampadaire->setHauteur(aHauteur); //dans lampadaire.h

    lampadaire->setULOR(aUlor); //dans lampadaire.h

    lampadaire->setType(aTypeLampadaire); //dans lampadaire.h

    ampoule->setIntensiteLumineuse(aFluxLum); // ampoule.h

    ampoule->setType(aTypeAmpoule); //  ampoule.h

    ampoule->setPuissance(puissance); //dans ampoule.h

    int recup = sprintf(Latitude, "%f", aLatitude); //conversion du double en char*
    //cout<<"donnée de  sprintf pour la latitude : "<<recup<<endl;

    geolocalisation->setLatitude(Latitude); // dans geolocalisation.h

    int recup2 = sprintf(Longitude, "%f", aLongitude); //Conversion du double en char*
    //cout<<"donneé de sprintf pour la longitude : "<<recup2<<endl;

    geolocalisation->setLongitude(Longitude); // dans geolocalisation.h

    int recup3 = sprintf(Altitude, "%d", (int) aAltitude); //Conversion du int en char*
    //cout<<"donneé de sprintf pour l'altitude: "<<recup3<<endl;

    geolocalisation->setAltitude(Altitude); // dans geolocalisation.h




    galerie->setNbrePhotos(aNbImages); //dans galerie.h


    _agglomeration = aAgglo; // enregistrement.h

    _rue = aRue; // enregistrement.h

    const char* X; //cree la variable X de type const char *
    X = aDate.c_str(); // fait une conversion de aDate qui est de type string en const char*

    char Date[6]; // On cree un tableau "Date" de 6
    strcpy(Date, X); //on convertit X qui est de type const char * en Date qui est de type char*

    horodatage->setDate(Date); //dans horodatage.h


    const char* Y; //cree la variable X de type const char *
    Y = aHeure.c_str(); // fait une conversion de aDate qui est de type string en const char*

    char Heure[6]; // On cree un tableau "Date" de 6
    strcpy(Heure, Y); //on convertit X qui est de type const char * en Date qui est de type char*

    horodatage->setHeure(Heure); //dans horodatage.h


    _notes = aNotes; // enregistrement.h


}

Enregistrement::Enregistrement(string aAlbedo, string aFluxLum, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude, double aLongitude, int aAltitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aHeure, string aNotes, int aPuissance) {
    horodatage = new Horodatage();
    geolocalisation = new Geolocalisation();
    ampoule = new Ampoule();
    _identifiant = "";
    lampadaire = new Lampadaire();
    galerie = new Galerie();

    //il faut instancier et mettre les attributs de enregistrer dans les attributs private de enregistrement.h:

    char Latitude[12];
    char Longitude[12];
    char Altitude[5];

    lampadaire->setAlbedo(aAlbedo); //dans lampadaire.h

    lampadaire->setHauteur(aHauteur); //dans lampadaire.h

    lampadaire->setULOR(aUlor); //dans lampadaire.h

    lampadaire->setType(aTypeLampadaire); //dans lampadaire.h

    ampoule->setIntensiteLumineuse(aFluxLum); // ampoule.h

    ampoule->setType(aTypeAmpoule); //  ampoule.h

    int recup = sprintf(Latitude, "%f", aLatitude); //conversion du double en char*

    geolocalisation->setLatitude(Latitude); // dans geolocalisation.h



    int recup2 = sprintf(Longitude, "%f", aLongitude); //Conversion du double en char*

    geolocalisation->setLongitude(Longitude); // dans geolocalisation.h

    int recup3 = sprintf(Altitude, "%d", aAltitude); //conversion du double en char*

    geolocalisation->setAltitude(Altitude);

    galerie->setNbrePhotos(aNbImages); //dans galerie.h

    _agglomeration = aAgglo; // enregistrement.h

    _rue = aRue; // enregistrement.h


    const char* X; //cree la variable X de type const char *
    X = aDate.c_str(); // fait une conversion de aDate qui est de type string en const char*

    char Date[6]; // On cree un tableau "Date" de 6
    strcpy(Date, X); //on convertit X qui est de type const char * en Date qui est de type char*

    horodatage->setDate(Date); //dans horodatage.h


    const char* Y; //cree la variable X de type const char *
    Y = aHeure.c_str(); // fait une conversion de aDate qui est de type string en const char*

    char Heure[6]; // On cree un tableau "Date" de 6
    strcpy(Heure, Y); //on convertit X qui est de type const char * en Date qui est de type char*

    horodatage->setHeure(Heure); //dans horodatage.h





    _notes = aNotes; // enregistrement.h


    ampoule->setPuissance(aPuissance); //dans ampoule.h

}

void Enregistrement::getDonneesCommunes() {
    throw "Not yet implemented";
}

int Enregistrement::caracteriserAmpoule(float aIntensiteLumineuse) {
    aIntensiteLumineuse = ampoule->mesurerILux();
    return 0;
}

int Enregistrement::localiser() {

    int erreur = 1;
    bool fin;
    horodatage->setVCond(fin);
    geolocalisation->setVCond(fin);
    erreur = geolocalisation->localiser();
    horodatage->dater();
    return erreur;

}

int Enregistrement::localiserSF() {

    int erreur = 1;
    bool fin;
    horodatage->setVCond(fin);
    geolocalisation->setVCond(fin);
    erreur = geolocalisation->localiser();
    horodatage->dater();
    return erreur;

}

//int Enregistrement::localiser(char aLatitude_[10], char aLongitude[10], GPS * unGPS)
//{
//
//	geolocalisation = new Geolocalisation(unGPS);
//	return geolocalisation->localiser();
//
//}

int Enregistrement::getIdentifiant() {
    return ID;
}

void Enregistrement::setAgglomeration(string aAgglomeration) {
    this->_agglomeration = aAgglomeration;
}

string Enregistrement::getAgglomeration() {
    return this->_agglomeration;
}

void Enregistrement::setNotes(string aNotes) {
    this->_notes = aNotes;
}

string Enregistrement::getNotes() {
    return this->_notes;
}

void Enregistrement::setRue(string aRue) {
    this->_rue = aRue;
}

string Enregistrement::getRue() {
    return this->_rue;
}

void Enregistrement::setAmpoule(string type, string intensiteLumineuse, int puissance) {
    ampoule->setIntensiteLumineuse(intensiteLumineuse);
    ampoule->setPuissance(puissance);
    ampoule->setType(type);
}

void Enregistrement::setLampadaire(string type, string hauteur, int ulor, string albedo) {
    lampadaire->setType(type);
    lampadaire->setHauteur(hauteur);
    lampadaire->setULOR(ulor);
    lampadaire->setAlbedo(albedo);
}

void Enregistrement::setGalerie(int nbrePhotos) {
    galerie->setNbrePhotos(nbrePhotos);
}

void Enregistrement::setHorodatage(char date[6]) {
    horodatage->setDate(date);


}

void Enregistrement::setHorodatage2(char heure[6]) {
    horodatage->setHeure(heure);


}

void Enregistrement::setGeolocalisation(char aLatitude_[12], char aLongitude[12], char aAltitude[5]) {
    geolocalisation->setLatitude(aLatitude_);
    geolocalisation->setLongitude(aLongitude);
    geolocalisation->setAltitude(aAltitude);
}
/////////////////////////get Compos�s//////////////////////////////

void Enregistrement::getAmpoule(string &type, string &intensiteLumineuse, int &puissance) {
    type = this->ampoule->getType();
    intensiteLumineuse = this->ampoule->getIntensiteLumineuse();
    puissance = this->ampoule->getPuissance();
}

void Enregistrement::getLampadaire(string &type, string &hauteur, int &ulor, string &albedo) {
    type = this->lampadaire->getType();
    hauteur = this->lampadaire->getHauteur();
    ulor = this->lampadaire->getULOR();
    albedo = this->lampadaire->getAlbedo();
}

void Enregistrement::getGalerie(int &nbrePhotos) {
    nbrePhotos = this->galerie->getNbrePhotos();
}

void Enregistrement::getHorodatage(char date[6]) {
    this->horodatage->getDate(date);

}

void Enregistrement::getHorodatage2(char heure[6]) {
    this->horodatage->getHeure(heure);
}

void Enregistrement::getGeolocalisation(char aLatitude_[12], char aLongitude[12], char aAltitude[5]) {

    this->geolocalisation->getLatitude(aLatitude_);
    this->geolocalisation->getLongitude(aLongitude);
    this->geolocalisation->getAltitude(aAltitude);

}

string Enregistrement::getBuboID() {
    return this->_identifiant;
}

Geolocalisation * Enregistrement::getGeolocalisation() {
    return geolocalisation;
}
