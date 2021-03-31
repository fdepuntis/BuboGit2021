// compilation g++ main_Geolocalisation.cpp Geolocalisation.cpp GPS.cpp ../serialib/serialib.cpp -o main_Geolocalisation  -std=c++14 -lpthread

#include "Geolocalisation.h"
using namespace std;

int main()
{
	char latitude[15];
	char longitude[15];
	char altitude[15];
	char satellite[3];
	char HDOP[5];
	bool *fin;
	GPS* unGPS = new GPS();
	Geolocalisation* leGPS = new Geolocalisation(unGPS);
	leGPS->setVCond(fin);
	//thread laLocalisation= leGPS->activerLocalisation();
	//laLocalisation.join();
	leGPS->localiser();
	leGPS->getLatitude(latitude);
	cout << latitude << endl;
	leGPS->getLongitude(longitude);
	cout << longitude << endl;
	leGPS->getAltitude(altitude);
	cout << altitude << endl;
	leGPS->getSatellite(satellite);
	cout << satellite << endl;
	leGPS->getHDOP(HDOP);
	cout << HDOP << endl;
	
}
