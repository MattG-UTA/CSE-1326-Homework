//Matthew Gutierrez
//ID: 1002333697
//Homework 2

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include "coordinateSystems.h"
#include "Airports.hpp"

 
void sameInts(std::vector<Airports>& someAirports, int lat, int log) 
{	
	int userLat;
	int userLog;
	double miles;
	int counter = 1;
	const double meterMile = 0.000621371; 
	
	std::vector<Airports> closeAirports; 
	
	for (Airports& element : someAirports)
	{	
		userLat = element.getLatitude();
		userLog = element.getLongitude();
		coordinateSystems::LLA userCords (lat, log, 0.0);
		coordinateSystems::LLA vecCords(userLat, userLog, 0.0);
		
	        coordinateSystems::ECF userCords2 = userCords.toECF ();
		coordinateSystems::ECF vecCords2 = vecCords.toECF ();
		
		double distance = std::sqrt (std:: abs (((userCords2.getFirstCoordinate () - vecCords2.getFirstCoordinate ()) * (userCords2.getFirstCoordinate () - vecCords2.getFirstCoordinate ())) + ((userCords2.getSecondCoordinate () - vecCords2.getSecondCoordinate()) * (userCords2.getSecondCoordinate () - vecCords2.getSecondCoordinate ()))));	

		miles = distance * meterMile;
		element.setMile(miles);
		if(miles > 0.0 && miles < 60.000000) 
		{	
			
			Airports *copy= new Airports(element);
			closeAirports.push_back(*copy);
			delete copy;
			
		}	
	}
	printf("%d \n", counter);
	counter =1;
	
	std::sort(closeAirports.begin(), closeAirports.end(), [](Airports& a, Airports& b) {
    return a.getMile() < b.getMile();
});

	for(Airports element : closeAirports) 
	{
		printf("%d) ", counter);
		element.printAirport();
		counter++;
	}
}

int main (int argc, char *argv[]) 
{
	FILE *apfile;
	
	apfile = fopen("iata-icao.csv", "r");
	
	char buffer[150];

	fgets(buffer, sizeof(buffer), apfile);
	 	
	std::vector<Airports> allAirports;
	
	while(fgets(buffer, sizeof(buffer), apfile) != NULL) 
	{
		Airports* ap = new Airports();
		ap->setCountryCode(strtok(buffer, "\",")); 
		ap->setRegionName(strtok(NULL, "\",")); 	
		ap->setIata(strtok(NULL, "\",")); 
		ap->setIcao(strtok(NULL , "\""));
		strtok(NULL, ",");
		ap->setAirport(strtok(NULL , "\",")); 	
		ap->setLatitude(atof(strtok(NULL , "\",")));
		ap->setLongitude(atof(strtok(NULL , "\","))); 
		allAirports.push_back(*ap);
		delete ap;	
	}
	fclose(apfile);
	
	size_t vectorSize = allAirports.size();
	printf("%zu entires in the list\n",vectorSize);	
	
	int i;
	int j;
	char stop1[] = "stop";
	char stop2[5];
	int start = 1;
	
	while(start == 1) 
	{
		
	 if(scanf("%d %d", &i, &j) == 2) 
	 {
	  sameInts(allAirports, i ,j);
	 }
	 else 
	 {
	 	scanf("%s", stop2);
	 	if(strcmp(stop1, stop2) == 0) 
	 	{
	 	  start = 0;
	 	  break;
	 	}
	 }
	}
		
	
	return 0;
}

 

