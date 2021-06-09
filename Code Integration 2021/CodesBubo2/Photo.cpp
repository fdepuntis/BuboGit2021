
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Photo.cpp
 * Author: eleve
 * 
 * Created on 14 mars 2017, 11:11
 */

#include "Photo.h"
#include <iostream>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

using namespace std;
//using namespace cgicc;
Photo::Photo(string identifiant) {
    this->photoRepertoire = "/home/pi/photos/";
	this->identifiant = identifiant;
}


Photo::~Photo() {
}

int Photo::getNbPhoto(string directory){
	DIR* dir = opendir(directory.c_str());
           dirent* entre = readdir(dir);
	int count = 0;
        while(entre){
		if(entre->d_type == DT_REG){
			string nomfichier = entre->d_name;
			if(nomfichier.find(".jpg", (nomfichier.length() - 4)) != string::npos)
				count++;
 
 
		}
	entre = readdir(dir);
	}
		return count;

}

int Photo::ajoute(string imgval)
{
 	
int d = mkdir((photoRepertoire+identifiant).c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        string lien = photoRepertoire+identifiant+"/" + identifiant+"_"+to_string(getNbPhoto(photoRepertoire+identifiant)+1)+ IMG_EXTENSION;

    	ofstream fichier(lien, ios::binary);
    	if(fichier.is_open()){
		imgval.replace(imgval.find("data:image/jpeg;base64,"),string("data:image/jpeg;base64,").size(), "");
		//cout << imgval << endl;
        	fichier << base64_decode(imgval);
		fichier.flush(); 
       		fichier.close();
        	return 1;
    	}else{
        	printf("Erreur : %s", strerror(errno)); 
    	}
    	return 0;
}

int Photo::supprime(string nom){
    string lien = photoRepertoire + nom;
    if(remove(lien.c_str()) != 0){
        //cout << "ERREUR : SUPRESSION FILE" << endl;
        return false;
    }
    return true;
}
