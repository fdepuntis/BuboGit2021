#include "Geolocalisation.h"

using namespace std;


Geolocalisation::Geolocalisation(GPS *unGPS)
{
        this->leGPS = unGPS;
}

Geolocalisation::Geolocalisation()
{

}


void Geolocalisation::calculLongitude(string leChamps[200])
{
	
	char longdegres[3];
	char longminute[8];
	float longdegre;
	float longmin;
	float resultatLongitudeF;
	string resultatLongitudeS;
	char longi[15];
	char E[2];
	strcpy(longi, leChamps[4].c_str());
	strcpy(E, leChamps[5].c_str());
	
	for(int y = 0; y<=2; y++)
		{
			longdegres[y] = longi[y];
			
		}

	//transformation de longdegres en float
		
	//utilisation de flux 
	istringstream degre(string(longdegres,3));
	degre>>longdegre;
			
		for(int y = 3; y<=9; y++)
		{
			//on utilise -3 car il faut qu'on aille au debut du tableau
			longminute[y-3] = longi[y];

		}
		
		
		//transformation de longminute en float

		//utilisation de flux 
	istringstream minutes(string(longminute,8));
	minutes>>longmin;
			
		
		//calcul de la latitude
		longmin =longmin/60;
		resultatLongitudeF = longdegre+longmin;
		if(calculEst(leChamps) == 'E')
		{
	}else{
		resultatLongitudeF = resultatLongitudeF *-1;
	}

	//resultatLongitudeS=to_string(resultatLongitudeF);
	//resultatLongitudeS.copy(longitude,resultatLongitudeS.size());		
	//if (resultatLongitudeS.size()<10) 
	//	for (int i= resultatLongitudeS.size(); i<10;i++)
	//		longitude[i]='0';	
	//sprintf(longitude, "%.6f", resultatLongitudeF);
	snprintf(longitude, 12, "%.6f",resultatLongitudeF);

}

void Geolocalisation::calculLatitude(string leChamps[200])
{
	
	char latdegres[2];
	char latminute[8];	
	double latdegreF,latminF;
	string latdegreS, resultatLatitudeS;
	double resultatLatitude;
	char lat[15];
	char N[2];
	
	strcpy(lat, leChamps[2].c_str());
	strcpy(N, leChamps[3].c_str());

	//calcul latitude
		
	for(int y = 0; y<=1; y++)
	{
		//on met les degres dans le tableau latdegres
		latdegres[y] = lat[y];
			
	}
	
	//latdegres[2]='\0';
	latdegreS = string(latdegres,2);
		
			
		//on met les minutes dans le tableau latminute
	for(int y = 2; y<=10; y++)
	{
		latminute[y-2] = lat[y];

	}
		
	//transformation de latdegre en float
		
	//utilisation de flux 
	istringstream degre(latdegreS);
	degre>>latdegreF;

	//transformation de latminute en float
	istringstream minutes(string(latminute,8));
	minutes>>latminF;


	//conversion des minutes en degr�s
	latminF =latminF/60;

	resultatLatitude = latdegreF+latminF;

	if(calculNord(leChamps) != 'N')
	{
		resultatLatitude = resultatLatitude *-1;

	}
	//resultatLatitudeS=to_string(resultatLatitude);
	//resultatLatitudeS.copy(latitude,resultatLatitudeS.size());
	//if (resultatLatitudeS.size()<10) 
	//	for (int i= resultatLatitudeS.size(); i<10;i++)
	//		latitude[i]='0';
	//sprintf(latitude, "%.6f", resultatLatitude);
	snprintf(latitude, 12, "%.6f",resultatLatitude);
}

void Geolocalisation::calculAltitude(string leChamps[200])
{
	char alti[5];
	int intalti;
	strcpy(alti, leChamps[9].c_str());
	intalti = atoi(alti);
	snprintf(altitude,5, "%d", intalti);

}

void Geolocalisation::calculSatellite(string leChamps[200])
{
	char nbreSatellite[3];
	strcpy(nbreSatellite, leChamps[7].c_str());
	intSatellite = atoi(nbreSatellite);
	snprintf(satellite,3, "%d", intSatellite);

	
}

char Geolocalisation::calculNord(string leChamps[200])
{
	char positionNord[2];
	strcpy(positionNord, leChamps[3].c_str());

	nord = positionNord[0];
	return nord;
}

char Geolocalisation::calculEst(string leChamps[200])
{
	char positionEst[2];
	strcpy(positionEst, leChamps[5].c_str());

	est = positionEst[0];
	return est;
}

char Geolocalisation::calculFixe(string leChamps[200])
{
	char resultatfixe[2];
	strcpy(resultatfixe, leChamps[6].c_str());
	fix = resultatfixe[0];
	return fix;


}

char Geolocalisation::calculHDOP(string leChamps[200])
{
	char resultatHDOP[5];
	strcpy(resultatHDOP, leChamps[8].c_str());
	for(int i=0;i<=5;i++){
		HDOP[i] = resultatHDOP[i];
	}	
}
	
int Geolocalisation::chronometer()
{
	chrono::time_point<std::chrono::system_clock> start, end; 
	chrono::duration<double> elapsed_seconds;
	start = std::chrono::system_clock::now();
	do {

		end = std::chrono::system_clock::now(); 
		elapsed_seconds = end - start; 
//		usleep(100000);
	}
	while((elapsed_seconds.count()<10)&&(vCond==false));

}

thread Geolocalisation::activerChrono(){
	return thread([this]{

		chronometer();
	vCond=true;
	this->setVCond(vCond);
	} );
}

int Geolocalisation::localiser()
{
	int erreur = OK;
	string leChamps[20]={"0"};

	intSatellite=0;
	nbrIterations=0;
	setVCond(false);
	thread leChrono = activerChrono();
	do {
		thread laRechercheGGA = leGPS->activerRechercheGGA();
		laRechercheGGA.join();
		erreur = leGPS->getErreur();
		//if (vCond) erreur=  PBFIX;

		leGPS->getChampsGGA(leChamps);
		calculLatitude(leChamps);
		calculLongitude(leChamps);
		calculAltitude(leChamps);
		calculSatellite(leChamps);
		calculFixe(leChamps);
		calculHDOP(leChamps);
		nbrIterations=nbrIterations+1;
	} while ((intSatellite<5)&&(nbrIterations<3)&&(!vCond));
		this->setVCond(true);
		leChrono.detach();
	return erreur;
}
	
void Geolocalisation::getLatitude(char alatitude[12]){
	for(int i=0 ; i<12; i++)
	{
		alatitude[i] = latitude[i];
	}
}

void Geolocalisation::getLongitude(char alongitude[12]){
	for(int i=0 ; i<12; i++)
	{
		alongitude[i] = longitude[i];
	}
}

void Geolocalisation::getAltitude(char aaltitude[5]){

	for(int i=0 ; i<5; i++)
	{
		aaltitude[i] = altitude[i];
	}
	aaltitude[4] = 0;
}
void Geolocalisation::getSatellite(char asatellite[3]){
	for(int i=0; i<=2;i++)
	{
		asatellite[i] = satellite[i];
	}
}
void Geolocalisation::getHDOP(char aHDOP[5]){
	for(int i=0 ; i<=4; i++)
	{
		aHDOP[i] = HDOP[i];
	}
}

char Geolocalisation::getFIX()
{
	return this->fix;
}

int Geolocalisation::getNbreAcquisition()
{
	return this->nbrIterations;
}

void Geolocalisation::setVCond(bool vCond){
	this->vCond=vCond;
	leGPS->setVCond(vCond);
}

void Geolocalisation::setLatitude(char aLatitude[12]){

             for (int i=0;i<12;i++)
        {
                latitude[i]=aLatitude[i];
        }
       
}
void Geolocalisation::setLongitude(char aLongitude[12]){

        for (int i=0;i<12;i++)
        {
                longitude[i]=aLongitude[i];
        }
}

void Geolocalisation::setAltitude(char aaltitude[5]){
		for (int i=0;i<4;i++)
        {
            altitude[i]=aaltitude[i];
        }
	altitude[4]=0;
}

