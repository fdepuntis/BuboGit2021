#ifndef PHOTO_H
#define PHOTO_H
#define IMG_EXT

#include <string>
#include <cstdio>
#include <dirent.h>
#include <string>
#include <fstream>
#include <cstdio> 
#include "base64.h"

class Photo {
public:
    Photo(std::string l);
    ~Photo();
    int supprime(std::string nom);
    int ajoute(std::string valeurPhoto);
    std::string IMG_EXTENSION = ".jpg";
private:
    std::string photoRepertoire;
	std::string identifiant;

	int getNbPhoto(std::string directory);
    

};

#endif /* PHOTO_H */

