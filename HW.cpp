//Matthew Gutierrez


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct airport {

	char *airportName;
	char *log;
	char *lat;

};


int main (int argc, char *argv[]) {
	
	FILE *apfile;
	
	apfile = fopen("iata-icao.csv", "r");
	
	char buffer[150];
	int rows = 0;
	
	airport *airports = NULL;
	
	
	while(fgets(buffer, sizeof(buffer), apfile) != NULL) 
	{	      
	        airport *temp = (airport *)realloc(airports,(rows+1) * sizeof(airport));
	        if(temp == NULL) 
	        {
	        	printf("Memory allocation failed. 2\n");
			return 1;
		}
		airports = temp;
		
		char *delimited = strtok(buffer, ",");
		delimited =  strtok(NULL, ",");
		delimited =  strtok(NULL, ",");
		delimited =  strtok(NULL, ",");
		
		delimited = strtok(NULL,",");
		airports[rows].airportName = (char *)malloc(strlen(delimited) + 1);
		strcpy(airports[rows].airportName, delimited);
			
		if(airports[rows].airportName == NULL) 
		{
			printf("memory allocation failed. 3\n");
			return 1;
		}
		
		delimited = strtok(NULL, ",");
		airports[rows].lat = (char *)malloc(strlen(delimited) + 1);
		strcpy(airports[rows].lat, delimited);		
		if(airports[rows].lat == NULL) 
		{
			printf("memory allocation failed. 4\n");
			return 1;
		}
		
		delimited = strtok(NULL, ",");
		airports[rows].log = (char *)malloc(strlen(delimited) + 1);
		strcpy(airports[rows].log, delimited);
		if(airports[rows].log == NULL) 
		{
			printf("memory allocation failed. 5\n");
			return 1;
		}
			
	        rows++;	            				
	}
	
	fclose(apfile);
	int start = 1;
	char exit[] = "stop";
	char infl1[10];
	char infl2[10];
	
	
	while(start == 1)
	{
		scanf("%s", infl1);		
		if(strcmp(exit, infl1) == 0)
		 {	
		 	break;
		 }
		 scanf("%s", infl2);
	
		int matches = 1;
	
		for(int i = 0; i < rows; i++) 
		{
		 char *name = strtok(airports[i].airportName, "\"");
		 char *latitude = strtok(airports[i].lat, "\"");
		 char *longitude = strtok(airports[i].log, "\"");
		 
		 char temp[10];
		 strcpy(temp, latitude);
		 char temp2[10];
       		 strcpy(temp2, longitude);
	  
		 if(strcmp(strtok(infl1, "."), strtok(temp, ".")) == 0 && strcmp(strtok(infl2, "."), strtok(temp2, ".")) == 0)
		 {
		 	printf("%d) %s %s %s\n", matches, name, latitude, longitude);
		 	matches++;
		 }
		 	 	 
		}

	}
	
	for (int i = 0; i < rows; i++) 
	{
        	free(airports[i].airportName);
        	free(airports[i].lat);
        	free(airports[i].log);
    	}
    	
	free(airports);
	return 0;
}


