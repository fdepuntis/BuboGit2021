/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 12 juin 2017, 08:32
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "Photo.h"
#include "Collecteur.h"

using namespace std;
using namespace cgicc;


/*
 * 
 */
int main(int argc, char** argv) {
	Cgicc cgi;
	cout<<HTTPHTMLHeader();
	form_iterator id = cgi.getElement("identifiant");
    if( !id->isEmpty() && id != cgi.getElements().end()) {  
		string identifiant(**id);
		Photo *photo = new Photo(identifiant);
		form_iterator nbPhoto = cgi.getElement("nbPhoto");
		int nb = stoi(**nbPhoto);
		for(int i = 0; i < nb; i++)
		{
			form_iterator ph = cgi.getElement("photo"+to_string(i));
			photo->ajoute(ph->getValue());


		}
	}else{
		cout << "erreur" << endl;
	}

	return 0;
}


