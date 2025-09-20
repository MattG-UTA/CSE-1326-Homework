class Airports
{
	public:
	char countryCode[7];
	char regionName[13];
	char iata[8];
	char icao[8];
	char airPort[80];	
	double longitude; 
	double latitude;
	double mile;
	
	Airports();
	
	Airports(const Airports& hardCopy);
	
	void setCountryCode(char userCountry[7]);
		
	void setRegionName(char userRegion[13]);
	
	void setIata(char userIata[8]);
	
	void setIcao(char userIcao[8]);
	
	void setAirport(char Airport[80]);
	
	void setLongitude (double userLongitude);
	
	double getLongitude(); 
	
	void setLatitude (double userLatitude);
	
	double getLatitude();
	
	void setMile(double userMile);
	
	double getMile();
	
	
	char printAirport();	

};

