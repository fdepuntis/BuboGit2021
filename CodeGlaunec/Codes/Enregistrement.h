#include <exception>
#include <string>
#include "../Codes/Lampadaire.h"
#include "../Codes/Ampoule.h"
#include "../Codes/Galerie.h"
#include "../Codes/Geolocalisation.h"
#include "../Codes/Horodatage.h"
#include "GPS.h"
using namespace std;

#ifndef __Enregistrement_h__
#define __Enregistrement_h__


	class Enregistrement
	{
		/**
		 * identifiant d'enregistrement bas� sur l'instant exact de mesure
		 */
		private: string _identifiant;
		private: string _agglomeration;
		private: string _rue;
		private: string _notes;
				 int ID;
		private: Lampadaire* lampadaire;
		private: Galerie* galerie;
		private: Geolocalisation* geolocalisation;
		private: Ampoule* ampoule;
		private: Horodatage* horodatage;

		public: Enregistrement(string aIdRaspberry, GPS * unGPS) ;
				Enregistrement( GPS * unGPS);
				Enregistrement(int aId, string aAlbedo, string aFluxLum, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude,  double aLongitude, int aAltitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aHeure, string aNotes, int puissance);

				Enregistrement(string aAlbedo, string aFluxLum,string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude, double aLongitude, int aAltitude , int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aHeure, string aNotes,int aPuissance);

		/// <summary>
		/// Cette m�thode permet de r�cup�rer les donn�es r�utilisables pour un nouvel enregistrement.
		/// </summary>
		public: void getDonneesCommunes();

		//public: void calculerIdentifiant(char heure[6],char date[6]);

		//public: string creerIdentifiant();

		public: int caracteriserAmpoule(float aIntensiteLumineuse);

		/// <summary>
		/// Cette m�thode permet d'extraire la latitude et la longitude sous la forme d'un tableau de 10 caract�res ASCII. Elles seront exprim�es en degr�s
		/// (avec 6 chiffres apr�s la virgule) et issues d'un filtrage sur 3 valeurs si nombre satellites <5
		/// Exemple d'une adresse dans la ville de Plougastel-Daoulas :
		/// Latitude = 48.347487�
		/// Longitude = -4.465502�
		/// Altitude = 110 m
		/// Le symbole � n'est pas contenu dans le tableau.
		/// <returns> Valeurs de retour :
		/// PBFIX = -1 : Signifie que le GPS n'�tait pas pr�t (Le fix n'est pas obtenu).</returns> 
		/// </summary>
		public: int localiser() ;

		/// <summary>
		/// Cette m�thode permet d'extraire la latitude, la longitude et l'altitude sous la forme d'un tableau de 10 et 4 caract�res ASCII. 
		///	Elles seront exprim�es en degr�s (avec 6 chiffres apr�s la virgule) et en m�tres. 
		/// Exemple d'une adresse dans la ville de Plougastel-Daoulas :
		/// Latitude = 48.347487�
		/// Longitude = -4.465502�
		/// Altitude = 110 m
		/// Le symbole � n'est pas contenu dans le tableau.
		/// <returns> Valeurs de retour :
		/// PBFIX = -1 : Signifie que le GPS n'�tait pas pr�t (Le fix n'est pas obtenu).</returns> 
		/// </summary>
		public: int localiserSF() ;

		//public: int localiser(char aLatitude_[10], char aLongitude[10], GPS * unGPS) ;

		public: int getIdentifiant();
		public: string getBuboID();
		public: void setAgglomeration(string aAgglomeration);

		public: string getAgglomeration();

		public: void setNotes(string aNotes);

		public: string getNotes();

		public: void setRue(string aRue);

		public: string getRue();

		void setLampadaire(string type, string hauteur, int ulor,string albedo);
		void setGalerie(int nbrePhotos);
		void setGeolocalisation(char aLatitude_[10], char aLongitude[10], char aAltitude[5]);
		void setHorodatage(char date[6]);
		void setHorodatage2(char heure[6]);
		void setAmpoule(string type,string intensiteLumineuse,int puissance);
		void getAmpoule(string &type, string  &intensiteLumineuse, int &puissance);

		void getLampadaire(string &type, string &hauteur, int &ulor, string  &albedo);
		void getGalerie(int &nbrePhotos);

		void getHorodatage(char date[6]);
                void getHorodatage2 (char heure[6]);

		/// <summary>
		/// Cette m�thode permet de r�cup�rer les coordonn�es d'un enregistrement.
		///	Les informations sont alors retourn�es dans les deux param�tres : 
		/// <param> premier param�tre = latitude</param>
		/// <param> second param�tre = longitude </param>
		/// <param> troisi�me param�tre = altitude </param>
		/// </summary>		
				void getGeolocalisation(char aLatitude_[10], char aLongitude[10], char aAltitude[5]);
				///Accesseur Geolocalisation classique
				Geolocalisation * getGeolocalisation();


	};


#endif
