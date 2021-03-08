#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../Codes/Geolocalisation.h"
#include "../../Codes/GPS.h"
#include "../../Codes/Horodatage.h"
#include <string>
#include <cstring> 
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    cout <<"Mise à l'heure de la Raspberry en cours ..."<<endl; 
    system("sleep 45");
    /* --------- Récupération de l'heure ------------*/
    GPS*gps = new GPS();
    Geolocalisation*geolocalisation = new Geolocalisation(gps);
    Horodatage*horodatage = new Horodatage(gps);

    char tableau [6];
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
    string crochet="'";
    date_heure = "sudo date --set "+crochet +date + heure+ crochet;
    cout << date_heure << endl;
    
    /* --------- conversion de date_heure en char* ------------*/
 
    size_t size = date_heure.size() + 1;     // créer le buffer pour copier la chaîne
    char * buffer = new char[ size ];
      strncpy(buffer, date_heure.c_str(), size);  // copier la chaîne 
      
    //cout << "ce qu'il y a dans le buffer : " << buffer<<endl; //pour vérifier ce qu'il y a dans le buffer
    
    /* --------- mise à jour de la date et de l'heure ---------------*/
    system("sudo timedatectl set-ntp false"); // ici on désactive 
 
    system(buffer);
    //system("date");
    return 0;
    delete [] buffer; // libérer la mémoire 
}
