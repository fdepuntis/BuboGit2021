#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sqlite3.h>
#include <ctype.h>
#include <chrono>
#include <thread>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "Collecteur.h"
using namespace std;
using namespace cgicc;

int main()
{
	cout << HTTPHTMLHeader(); 
	Collecteur *leCollecteur= new Collecteur();
	int testerreur=leCollecteur->envoyerbdd();
	cout <<"{\n\t\"ERREUR\":\""+ to_string(testerreur)+"\"\n}\n";

}