#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring> 
#include <stdlib.h>
#include "../BDD.h"
#include "../Geolocalisation.h"
#include "../Horodatage.h"
#include "../Collecteur.h"
#include "../Enregistrement.h"
#include "../GPS.h"
#include "../Mail.h"

int main(int argc, char** argv) {
//system("sudo su"); 
 
Collecteur* collecteur=new Collecteur(); 
BDD*bdd=new BDD(); 

collecteur->mettreCollecteurAJour(); 
string hour;
cout <<hour <<collecteur ->getdateHeureBDD()<< " <- Ce qu'il y a dans getdateHeureBDD()"<<endl;
hour=collecteur->getdateHeureBDD(); 
cout <<hour<<" <-ce qu'il y a dans hour"<<endl; 
collecteur ->setdateHeureBDD(hour); 
cout<<collecteur->getdateHeureBDD() <<" <-Ce qu'il y a a présent dans dateHeureBDD"<<endl; 

collecteur->creerEnregistrementVirtuel(); //créer un enregistrement virtuel pour géolocaliser ! 
cout<<collecteur->geolocaliser()<<endl; 
collecteur->supprimerEnregistrementVirtuel();

}


