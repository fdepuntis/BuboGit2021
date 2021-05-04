#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring> 
#include <stdlib.h>

#include "../../Codes/BDD.h"

#include "../../Codes/Geolocalisation.h"
#include "../../Codes/Horodatage.h"
#include "../../Codes/Collecteur.h"

#include "../../Codes/GPS.h"
#include "../../Codes/Mail.h"


int main(int argc, char** argv) {

Collecteur* collecteur=new Collecteur(); 
BDD*bdd=new BDD(); 
collecteur->mettreCollecteurAJour(); 

//cout<<date_heureBDD<endl; 

}


