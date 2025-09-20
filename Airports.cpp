#include "Airports.hpp"
#include <stdio.h>
#include <string.h>
#include <cstring>

Airports::Airports()
{
 
}

/*
char countryCode[7];
	char regionName[13];
	char iata[8];
	char icao[8];
	char airPort[80];	
	double longitude; 
	double latitude;
*/

Airports::Airports(const Airports& hardCopy)
    : longitude(hardCopy.longitude),
      latitude(hardCopy.latitude),
      mile(hardCopy.mile)
{
    strcpy(regionName, hardCopy.regionName);
    strcpy(iata, hardCopy.iata);
    strcpy(icao, hardCopy.icao);
    strcpy(airPort, hardCopy.airPort);
}




   

void Airports::setCountryCode(char userCountry[7]) 
{
	strcpy(countryCode, userCountry);
};
	
void Airports::setRegionName(char userRegion[13]) 
{
	strcpy(regionName, userRegion);
};

void Airports::setIata(char userIata[8]) 
{
	strcpy(iata, userIata);
};

void Airports::setIcao(char userIcao[8]) 
{
	strcpy(icao, userIcao);
};

void Airports::setAirport(char Airport[80]) 
{
	strcpy(airPort, Airport);
};

void Airports::setLongitude (double userLongitude) 
{
	longitude = userLongitude;
};

double Airports::getLongitude() 
{
	return longitude;
}

void Airports::setLatitude (double userLatitude) 
{
	latitude = userLatitude;
};

double Airports::getLatitude () 
{
	return latitude;
}

void Airports::setMile(double userMile) 
{
	mile = userMile;
}

double Airports::getMile() 
{
	return mile;
}

char Airports::printAirport() 
{
	return printf("%s %lf %lf (miles) %lf \n", airPort, latitude, longitude, mile);
};	

