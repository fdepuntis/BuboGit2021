/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g1
 *
 * Created on 31 mars 2021, 12:40
 */

#include <cstdlib>
#include"Enregistrement.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "GPS.h"
#include"Logger.h"
#include "Collecteur.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        int id =1; 
        string albedo="";
	string fluxLum="";
	string aIdRaspberry="";
	string lamp="";
	string streetlight="";
	string height="";
	int power=12;
	double aLatitude= 43.23568;
	double aLongitude=1.1235468;
	int aAltitude = 140;
	int aNbImages=12;
	string town="";
	string aNotes="";
	string street="";
	int ULOR=1;
    
	string aDate="210352";
	string aHeure="161230"; 
     
        char heure[6] = {0}; 
      

   
    cout<<"Test pour Modifier : "<<endl; 
    Enregistrement* enregistrement = new Enregistrement(id, albedo, fluxLum, aIdRaspberry, lamp, streetlight, height, aLatitude, aLongitude, aAltitude, aNbImages, town, street, ULOR, aDate, aHeure, aNotes, power);
    cout<<endl; 
    
    enregistrement->getHorodatage2(heure);
    cout<<"getHorodatage2 : "<<heure<<endl; 
    cout<<endl; 
    enregistrement->setHorodatage2(heure);
    cout<<"setHorodatage2 : "<<heure<<endl;
    cout<<endl; 
    
    cout<<"Test pour enregister : "<<endl; 
    Enregistrement* enregistrement2 = new Enregistrement(albedo, fluxLum, lamp, streetlight,height, aLatitude, aLongitude, aAltitude, aNbImages, town,  street,  ULOR, aDate, aHeure, aNotes, power);
}

