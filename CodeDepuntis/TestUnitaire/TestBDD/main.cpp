#include <cstdlib>
#include"Enregistrement.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "BDD.h"

#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int id = 1;
    string albedo = "";
    string fluxLum = "";
    string idRaspberry = "";
    string typeAmpoule = "";
    string typeLampadaire = "";
    string hauteur = "";
    int puissance = 12;
    double latitude = 43.23568;
    double longitude = 1.1235468;
    int altitude = 140;
    int nbImages = 12;
    string agglo = "";
    string notes = "";
    string rue = "";
    int ulor = 1;

    string date = "210352";
    string heure = "161230";

    // char heure[6] = {0}; 


    BDD*bdd = new BDD();

    //bdd->modifierEnregistrement(id, puissance, albedo, fluxLum, idRaspberry, typeAmpoule, typeLampadaire, hauteur, latitude, longitude, altitude, nbImages, agglo, rue, ulor, date, heure, notes);
  //  cout << heure << endl;
   // Enregistrement* enregistrement = new Enregistrement(albedo, fluxLum, typeAmpoule, typeLampadaire, hauteur, latitude,longitude, altitude, nbImages, agglo, rue, ulor, date, heure, notes, puissance);
    //bdd->sauvegarderDonneesEnregistrement(enregistrement, idRaspberry);
    /*  
       vector<Enregistrement*> laListeEnregistrements;
      laListeEnregistrements = bdd->obtenirListeDesEnregistrements(); 
    
    		for (std::vector<Enregistrement*>::iterator it = laListeEnregistrements.begin() ; it != laListeEnregistrements.end(); ++it)
		{
			cout<<"\n\t\t{";
			string lamp;
  			string streetlight;
			string height;
			int ULOR;
			int power;
			string  albedo;
			string fluxLum;
			int nbimages;
			char date [7];
                        char heure [7]; 
			char longitude[12];
			char latitude[12];
			char altitude[5];
			int identifiantE;
			string  town;
			string  street;
			string notes;
			identifiantE = ((Enregistrement*)*it)->getIdentifiant();
			cout<<"\n\t\t\t\"ID\":\""<<identifiantE<<"\",";
			
			((Enregistrement*)*it)->getLampadaire(streetlight,height,ULOR,albedo);
			((Enregistrement*)*it)->getAmpoule(lamp,fluxLum,power);
			cout<<"\n\t\t\t\"POWER\":\""<<power<<"\",";
			cout<<"\n\t\t\t\"ALBEDO\":\""<<albedo<<"\",";
			cout<<"\n\t\t\t\"FLUX\":\""<<fluxLum<<"\",";
			cout<<"\n\t\t\t\"BUBOID\":\""<<((Enregistrement*)*it)->getBuboID() <<"\",";
			cout<<"\n\t\t\t\"LAMP\":\""<<lamp <<"\",";
			cout<<"\n\t\t\t\"STREETLIGHT\":\""<<streetlight <<"\",";
			cout<<"\n\t\t\t\"HEIGHT\":\""<<height <<"\",";

			((Enregistrement*)*it)->getGeolocalisation(latitude,longitude, altitude);
			string laLongitude=longitude; 
			string laLatitude=latitude;
			string lAltitude=altitude;
			cout<<"\n\t\t\t\"LATITUDE\":\""<<laLatitude <<"\",";
			cout<<"\n\t\t\t\"LONGITUDE\":\""<<laLongitude <<"\",";
			cout<<"\n\t\t\t\"ALTITUDE\":\""<<lAltitude <<"\",";
			
			((Enregistrement*)*it)->getGalerie(nbimages);
			cout<<"\n\t\t\t\"NBIMAGES\":\""<<nbimages <<"\",";
			town = ((Enregistrement*)*it)->getAgglomeration();
			cout<<"\n\t\t\t\"TOWN\":\""<<town <<"\",";
			street = ((Enregistrement*)*it)->getRue();
			cout<<"\n\t\t\t\"STREET\":\""<<street <<"\",";
			cout<<"\n\t\t\t\"ULOR\":\""<<ULOR<<"\",";
			
                        ((Enregistrement*)*it)->getHorodatage(date);
			string laDate(date, 6); 
			cout<<"\n\t\t\t\"DATE\":\""<<laDate<<"\",";
                       
                        ((Enregistrement*)*it)->getHorodatage2(heure);
                        string leHeure(heure, 6); 
			cout<<"\n\t\t\t\"HEURE\":\""<<leHeure<<"\",";
                        
 			notes=((Enregistrement*)*it)->getNotes();
			cout<<"\n\t\t\t\"NOTES\":\""<<notes<<"\"";
			cout<<"\n\t\t}";
			if (!(it+1 == laListeEnregistrements.end())) cout<<",";
		}
		cout<<"\n\t]\n}";
  
    
*/

}

