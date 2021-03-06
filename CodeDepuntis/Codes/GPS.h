#ifndef DEF_GPS
#define DEF_GPS

#include <stdio.h>
#include "../serialib/serialib.h"
#include <iostream>
#include <iomanip>
#include <sstream> 
#include <string>
#include <vector>
#include <cstring>
#include <thread>
#include <condition_variable>
using namespace std;
#define DEVICE_PORT0     "/dev/ttyUSB0"
#define DEVICE_PORT1     "/dev/ttyUSB1"
#define DEVICE_PORT2     "/dev/ttyUSB2"
#define DEVICE_PORT3     "/dev/ttyUSB3"

#define SPEED    9600
#define ERREURACCESPORT -2
#define ERREURCHECK -3
#define GGANOTFIND -4
#define RMCNOTFIND -5
#define PBFIX -1
#define OK 1


class GPS
{
	
public : 
	GPS();

	int lirePosition();
	int lireHeure();
	thread activerRechercheGGA();
	thread activerRechercheRMC();

	void getChampsGGA(string champsGGA[200]);
	void getChampsRMC(string champsRMC[200]);
	
	void setVCond(bool vCond);
	int getErreur();

private :
	
	char fix[2];
	int erreur;
	string champsGGA[20];
	string champsRMC[20];
	bool vCond;
	bool verifierCheksum(char Buffer[500]);
	

};

#endif