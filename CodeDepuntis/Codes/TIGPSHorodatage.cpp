// compilation g++ TIGPSHorodatage.cpp Horodatage.cpp GPS.cpp ../serialib/serialib.cpp -o TIGPSHorodatage  -std=c++14 -lpthread

#include "Horodatage.h"
#include "Geolocalisation.h"
using namespace std;

int main()
{
	char latitude[15];
	char longitude[15];
	char altitude[15];
	char satellite[3];
	char HDOP[5];
	char date [6];
	char heure [6];
	bool fin;
	GPS* unGPS = new GPS();
	Horodatage* lHorodatage = new Horodatage(unGPS);
	lHorodatage->setVCond(fin);
	//test Geo et Horo
	Geolocalisation* laGeolocalisation = new Geolocalisation(unGPS);
	laGeolocalisation->setVCond(fin);
	laGeolocalisation->localiser();
	cout<<"localisation completed OK"<<endl;
	lHorodatage->dater();
	cout<<"dater completed OK"<<endl;
	laGeolocalisation->getLatitude(latitude);
	cout << latitude << endl;
	laGeolocalisation->getLongitude(longitude);
	cout << longitude << endl;
	laGeolocalisation->getAltitude(altitude);
	cout << altitude << endl;
	laGeolocalisation->getSatellite(satellite);
	cout << satellite << endl;
	laGeolocalisation->getHDOP(HDOP);
	cout << HDOP << endl;	
	lHorodatage->getHeure(heure);
	cout << heure << endl;
	lHorodatage->getDate(date);
	cout << string(date,6) << endl;
}
