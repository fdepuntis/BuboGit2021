#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Collecteur_h__
#define __Collecteur_h__

#include "../projetsocketV2/Enregistrement.h"

#include "../projetsocketV2/GPS.h"
/*
#include "Mail.h" 
#include "Config.h" */

#define PBACCESIDENT -1
#define PBLECTUREIDENT -2
#define IDENTNOTFIND -3

	class Collecteur
	{
		private: string _identifiant;
				 GPS *unGPS;
		private: std::vector<Enregistrement*> _lampadairesProches;
		private: std::vector<Enregistrement*> listeEnregistrements;
		public: Collecteur();
		public: int recupererIdentifiantRaspberry();

		public: void creerEnregistrementVirtuel();
				Enregistrement* creerEnregistrement(Enregistrement *aDonnee);
				void supprimerEnregistrementVirtuel();

		public: string geolocaliser();

		public: string geolocaliser(int identifiant);

		public: string obtenirIntensiteLumineuse();

		public: string obtenirIntensiteLumineuse(int identifiant);

		public: vector<Enregistrement*> chercherEnregistrements();

		public: void comparerPosition();

		public: void ajouterLampadairesProches();

		public: string getDonneesEnregistrement(char aLatitude[], char aLongitude[], char aAltitude[4]);


		public: void modifier(Enregistrement *aDonnee);

		public: bool supprimerEnregistrement(int ID);
				string getIdentifiant();
				vector<Enregistrement*> getlisteEnregistrements();
				bool viderTable();
				int envoyerbdd();
	};


#endif
