#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
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

Collecteur* collecteur=new Collecteur(); 
BDD*bdd=new BDD(); 

collecteur->mettreCollecteurAJour(); 
cout << collecteur ->getdateHeureBDD()<<endl; 
//Enregistrement* creerEnregistrement = collecteur ->creerEnregistrement(Enregistrement* aDonnee);



//collecteur->getdateHeureBDD();


}


