#include<stdio.h>

struct cityInformation {
	char cityName[50];
	double lowestTemp, highestTemp;
};


struct cityInformation inputCityInformation();
int highestTemperature(struct cityInformation cityArray[]);
int largestDifference(struct cityInformation cityArray[]);
void updateTemperatures(struct cityInformation city, double *lowestTemp, double *highestTemp);
void printInformation(struct cityInformation city);

int main(void)
{
	
	struct cityInformation cities[10];
	//selection index is used for getting input for updating temperatures function
	//selection is used for get the user input for if they want to continue to update temperatures or not
	int i, highestTempIndex, highestTempDifferenceIndex, selectionIndex, selection;
	
	//Gets user inputs for 10 cities	
	for(i=0; i<10; i++)
	{
		printf("Please input %d. city information: \n", i+1);
		cities[i] = inputCityInformation();
		printf("\n");
	}
	
	//Finding and printing the city which has highest temperature
	highestTempIndex = highestTemperature(cities);
	printf("City having the highest temperature is %s city with %5.2lf degree.\n", cities[highestTempIndex].cityName, cities[highestTempIndex].highestTemp);
	
	
	//Finding and printing the city which has the largest difference between temperatures
	highestTempDifferenceIndex = largestDifference(cities);
	printf("\nThe city which has the largest difference between lowest and highest temperature is: \n");
	printInformation(cities[highestTempDifferenceIndex]);
	
	//For updating temperatures of choosen city
	do {
		printf("\n\nPlease choose a city number to update its temperatures:(Please input between 1-10) ");
		scanf("%d", &selectionIndex);
	
		//Prints out an error message and gets input again if user inputs wrong value
		while (selectionIndex < 0 || selectionIndex > 10)
		{
			printf("Invalid input!\nPlease choose between 1-10: ");
			scanf("%d", &selectionIndex);	
		}
		
		//-1 because number of cities starts from 1
		updateTemperatures(cities[selectionIndex-1], &cities[selectionIndex-1].lowestTemp, &cities[selectionIndex-1].highestTemp);
		printInformation(cities[selectionIndex-1]);
		
		//Ask user if they want to continue updating temperatures or not
		printf("\n1-Continue\n2-Quit!\nPlease choose: ");
		scanf("%d", &selection);
		
		//Prints out an error message and gets input again if user inputs wrong value
		while (selection < 0 || selection > 2)
		{
			printf("Invalid input!\nPlease choose 1 or 2: ");
			scanf("%d", &selection);
			
		}
		
	//If user inputs 2(Quit!) break out of loop and terminate the program
	} while (selection != 2);
	
	return 0;
	
}

//Inputs city information into a structure and returns the structure
struct cityInformation inputCityInformation()
{
	struct cityInformation city;
	printf("Please input name of the city: ");
	scanf("%s", &city.cityName);
	printf("Please input lowest temperature of the city: ");
	scanf("%lf", &city.lowestTemp);
	printf("Please input highest temperature of the city: ");
	scanf("%lf", &city.highestTemp);
	
	//Checks if the user input highest temperature or not(It can be smaller than lowest temperature)
	while(city.highestTemp < city.lowestTemp)
	{
		printf("Invalid input!\nPlease input higher value than lowest temperature(%5.2lf): ", city.lowestTemp);
		scanf("%lf", &city.highestTemp);
	}
	
	return city;
}

//Recieves an array of city structure, it finds and returns the city having the highest temperature.
int highestTemperature(struct cityInformation cityArray[])
{
	int highestIndex, i;
	//-999.9 is temporary
	double highest = -999.9;
	//-1 is temporary
	highestIndex = -1;
	
	//Ended loop at 10 because in main user inputs 10 cities
	for(i=0; i<10; i++)
	{
		if(cityArray[i].highestTemp > highest)
		{
			highestIndex = i;
			highest = cityArray[i].highestTemp;
		}
		
	}
	
	return highestIndex;
}

//Recieves an array of city structure, it finds and returns the city which has the largest difference between lowest and highest temperature
int largestDifference(struct cityInformation cityArray[])
{
	int i, maxDifferenceIndex;
	double maxDifference, difference;
	
	maxDifference = cityArray[0].highestTemp - cityArray[0].lowestTemp;
	
	//Ended loop at 10 because in main user inputs 10 cities
	for(i=0; i<10; i++)
	{
		difference = cityArray[i].highestTemp - cityArray[i].lowestTemp;
		
		if(difference > maxDifference)
		{
			maxDifference = difference;
			maxDifferenceIndex = i;
		}
	}
	
	return maxDifferenceIndex;
}
//Recieves a city structure inputs and updates highest and lowest temperatures of the structure and returns it through a parameter.
void updateTemperatures(struct cityInformation city, double *lowestTemp, double *highestTemp)
{
	double low, high;
	
	printf("Choosen city name: %s\n", city.cityName);
	printf("Please input the new value of lowest temperature(Current value is %5.2lf): ", city.lowestTemp);
	scanf("%lf", &low);
	printf("Please input the new value of highest temperature(Current value is %5.2lf): ", city.highestTemp);
	scanf("%lf", &high);
	
	//Checks if the user input highest temperature or not(It can be smaller than lowest temperature)
	//It compares it with newest/updated input
	if(high < low)
	{
		printf("Invalid input!\nPlease input higher value than lowest temperature(%5.2lf): ", low);
		scanf("%lf", &high);
	}
	
	*lowestTemp = low;
	*highestTemp = high;
}

//Prints out city informations
void printInformation(struct cityInformation city)
{
	printf("City Name: %s\n", city.cityName);
	printf("Lowest Temperature: %5.2lf\n", city.lowestTemp);
	printf("Highest Temperature: %5.2lf\n", city.highestTemp);
}
