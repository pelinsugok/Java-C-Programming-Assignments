#include<stdio.h>
#include<stdlib.h>

void printStocks(int flowerMarket[][10]);
void inputFlowerAmount(int flowerMarket[][10]);
void stockControlWithIDs(int flowerID, int storeID, int flowerMarket[][10]);
void listAllFlowersOfStore(int storeID, int flowerArray[][10]);
void listFlowersDiffer(int firstStoreID, int secondStoreID, int firstStoreArray[], int secondStoreArray[], int firstStoreArraySize, int secondStoreArraySize);
void listFlowersCommon(int firstStoreID, int secondStoreID, int firstStoreArray[], int secondStoreArray[], int firstStoreArraySize, int secondStoreArraySize);
void listFlowerSortedByStock(int flowerMarket[][10], int rowSize, int sortedFlowerID[], int sortedFlowerAmount[]);
int storeHasLargestFlowerAmount(int flowerID, int flowerArray[]);
void updateStock(int storeID, int flowerID, int newStock, int flowerMarket[][10], int rowSize);
void hasAllFlowers(int flowerMarket[][10], int rowSize);

int main (void)
{
	int menuSelection, subMenuSelection, secondMenuSelection, arrayOfStoreN[10], arrayOfStoreM[10], sizeOfStoreN = 10, sizeOfStoreM = 10, newStock;
	int abcFlowerMarket[10][10] = {}, flowerID, storeID, storeIDofM, storeIDofN, i, j, stockOfSelectedFlower[10], sortedFlowerID[10], sortedFlowerAmount[10], storeHasMaxFlowers;

	/*Variable Definitions:
		menuSelection is for main menu selection
		subMenuSelection is for menu selection for Listing flowers
		secondMenuSelection is for menu selection for asking user to continue or not
		flowerID and storeID is inputted by user
		storeIDofM and storeIDofN is inputted by user for List flowers that exist in store n and store m and List flowers that exist in both store n and store m
		i and j are for loops
		storeHasMaxFlowers is for Find store having the largest amount of a flower
	*/
		
	srand(time(NULL));
	
	//For initializing the flower amounts randomly between 0-100
	
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
			abcFlowerMarket[i][j] = rand() % 100;
	}
	
	do {
		//Menu declaration		
		printf("\nMain menu: \n--------------------\n0-Print Stocks\n1-Input Flower Amount of a Store\n2-Stock Control with Flower ID and Store ID\n3-List Flowers\n4-Update Stock\n5-Find Stores Which Have All of the Flowers In Stock\n6-Quit\n--------------------\n");
		printf("\nSelect Your Operation: ");
		scanf("%d", &menuSelection);
		
		//Check whether the input is valid or invalid, if input is invalid outputs an error message and inputs menuSelection again	
		while(menuSelection < 0 || menuSelection > 6)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter 0-6: ");
			scanf("%d", &menuSelection);
		}
		
		//For printing stocks	
		if(menuSelection == 0)
		{
			printf("\n0-Print Stocks: \n");
			
			//Calls function with array
			printStocks(abcFlowerMarket);
			
		}
	
		//For inputting flower amount for a store
		else if(menuSelection == 1)
		{
			printf("\n1-Input Flower Amount of a Store: \n");
			
			//Calls function with array
			inputFlowerAmount(abcFlowerMarket);
		}
		
		//For stock control with flower ID and store ID
		else if(menuSelection == 2)
		{
			printf("\n2-Stock Control with Flower ID and Store ID: \n");
			
			//Calls function with flowerID, storeID and array
			stockControlWithIDs(flowerID, storeID, abcFlowerMarket);
		}
		
		//For listing flowers
		else if(menuSelection == 3)
		{
			printf("\nList Flowers: \n");
			do {
				//Sub-menu declaration
				printf("\n1-List All Flowers of Store n\n2-List Flowers that Exist in Store n but not in Store m\n3-List Flowers that Exist in Both Store n and Store m\n4-List Sorted Flower by Stock\n5-Find Store Having the Largest Amount of a Flower\n6-Back to the Main Menu!\n");
				printf("Select your operation: ");
				scanf("%d", &subMenuSelection);
				
				if(subMenuSelection == 1)
				{
					printf("\nList All Flowers of Store n: \n");
					do
					{
						printf("Input Store ID: ");
						scanf("%d", &storeID);
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID again
						while (storeID < 1 || storeID > 10)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter the Store ID Between 1-10: ");
							scanf("%d", &storeID);
						}
						
						//Calls function with storeID and array
						listAllFlowersOfStore(storeID, abcFlowerMarket);
						printf("\n");
						
						//Asks user to continue or not
						printf("\n1-Continue\n2-Return to List Menu\nSelection: ");
						scanf("%d", &secondMenuSelection);
						
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs secondMenuSelection again		
						while(secondMenuSelection <= 0 || secondMenuSelection > 2)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter 1 or 2: ");
							scanf("%d", &secondMenuSelection);
						}
		
						if(secondMenuSelection == 2)
							break;
					
					//If user inputs 2 program returns to the menu of listing flowers	
					} while(secondMenuSelection != 2);
				}
				
				else if(subMenuSelection == 2)
				{
					printf("\nList Flowers that Exist in Store n but not Store m: \n");
					do{
						printf("Select Two Stores to Compare: ");
						
						//Gets two store IDs from user
						scanf("%d %d", &storeIDofN, &storeIDofM);
						
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID of n again
						while(storeIDofN < 1 || storeIDofN > 10)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter the Store ID Between 1-10: ");
							scanf("%d", &storeIDofN);
						}
						
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID of m again
						while (storeIDofM < 1 || storeIDofM > 10)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter the Store ID Between 1-10: ");
							scanf("%d", &storeIDofM);
						}
						
						//Stores amounts of stores into two 1D arrays
						//Used -1 because user input between 1-10
						for(i=0; i<10; i++)
						{
							arrayOfStoreN[i] = abcFlowerMarket[storeIDofN-1][i];
							arrayOfStoreM[i] = abcFlowerMarket[storeIDofM-1][i];
						}
						
						//Calls function with storeID of the first store, second store and their 1D arrays and its sizes
						listFlowersDiffer(storeIDofN, storeIDofM, arrayOfStoreN, arrayOfStoreM, 10, 10);
						
						//Asks user to continue or not
						printf("\n1-Continue\n2-Return to List Menu\nSelection: ");
						scanf("%d", &secondMenuSelection);
						
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs secondMenuSelection again
						while(secondMenuSelection <= 0 || secondMenuSelection > 2)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter 1 or 2: ");
							scanf("%d", &secondMenuSelection);
						}
		
						if(secondMenuSelection == 2)
							break;
							
					//If user inputs 2 program returns to the menu of listing flowers		
					} while(secondMenuSelection != 2);
					
					
				}
				
				else if(subMenuSelection == 3)
				{
					printf("\nList Flowers that Exist in both Store n and Store m: \n");
					do {
						printf("Select Two Stores: ");
						
						//Gets two store IDs from user
						scanf("%d %d", &storeIDofN, &storeIDofM);
						
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID of n again
						while (storeIDofN < 1 || storeIDofN > 10)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter the Store ID Between 1-10: ");
							scanf("%d", &storeIDofN);
						}
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID of m again
						while (storeIDofM < 1 || storeIDofM > 10)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter the Store ID Between 1-10: ");
							scanf("%d", &storeIDofM);
						}
						
						//Stores amounts of stores into two 1D arrays
						//Used -1 because user input between 1-10
						for(i=0; i<10; i++)
						{
							arrayOfStoreN[i] = abcFlowerMarket[storeIDofN-1][i];
							arrayOfStoreM[i] = abcFlowerMarket[storeIDofM-1][i];
						}
						
						//Calls function with storeID of the first store, second store and their 1D arrays and its sizes
						listFlowersCommon(storeIDofN, storeIDofM, arrayOfStoreN, arrayOfStoreM, sizeOfStoreN, sizeOfStoreM);
						
						//Asks user to continue or not
						printf("\n1-Continue\n2-Return to List Menu\nSelection: ");
						scanf("%d", &secondMenuSelection);
						
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs secondMenuSelection again
						while(secondMenuSelection <= 0 || secondMenuSelection > 2)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter 1 or 2: ");
							scanf("%d", &secondMenuSelection);
						}
		
						if(secondMenuSelection == 2)
							break;
					
					//If user inputs 2 program returns to the menu of listing flowers	
					} while(secondMenuSelection != 2);
				}
				
				else if(subMenuSelection == 4)
				{
					printf("\nList Sorted Flower by Stock: \n");
					
					//Calls function with array and its size sortedFlowerID array and sortedFlowerAmount array
					listFlowerSortedByStock(abcFlowerMarket, 10, sortedFlowerID, sortedFlowerAmount);
					printf("\n\nFlower: ");
					
					//For printing the IDs of flowers
					for(i=0; i<10; i++)
						printf(" %d     ", sortedFlowerID[i]+1);
					
					printf("\nAmount: ");
					//For printing the amounts of flowers
					for(j=0; j<10; j++)
						printf(" %d   ", sortedFlowerAmount[j]);
					printf("\n");
				}
				
				else if(subMenuSelection == 5)
				{
					printf("Find Store Having the Largest Amount of a Flower: \n");
					
					do {
						
						printf("Input Flower ID: ");
						scanf("%d", &flowerID);
						
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs flowerID
						while (flowerID < 1 || flowerID > 10)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter the Store ID Between 1-10: ");
							scanf("%d", &flowerID);
						}
						
						//For printing stocks of selected flower
						for(i=0; i<10; i++)
							stockOfSelectedFlower[i] = abcFlowerMarket[i][flowerID-1];
						
						//Calls function with flowerID and inputted stock ID
						storeHasMaxFlowers = storeHasLargestFlowerAmount(flowerID, stockOfSelectedFlower);
						
						//Printing the result
						printf("Store %d has the largest stock of %d flowers of type %d\n", storeHasMaxFlowers+1, abcFlowerMarket[storeHasMaxFlowers][flowerID-1], flowerID);
						
						//Asks user to continue or not
						printf("\n1-Continue\n2-Return to List Menu\nSelection: ");
						scanf("%d", &secondMenuSelection);
					
						//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs secondMenuSelection again
						while(secondMenuSelection <= 0 || secondMenuSelection > 2)
						{
							printf("\n!!!Invalid Input!!!\n\n");
							printf("Please Enter 1 or 2: ");
							scanf("%d", &secondMenuSelection);
						}
		
						if(secondMenuSelection == 2)
							break;
					
					//If user inputs 2 program returns to the menu of listing flowers				
					} while(secondMenuSelection != 2);		
					
				}
				
				//For returning to the main menu
				else if(subMenuSelection == 6)
				{	
					printf("\nBack to the Main Menu!: \n");
					break;
				}
				
				//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs subMenuSelection again
				while(subMenuSelection < 1 || subMenuSelection > 6)
				{
					printf("\n!!!Invalid Input!!!\n\n");
					printf("Please Enter 1-6: ");
					scanf("%d", &subMenuSelection);
				}
			
				//If user inputs 6 program returns to the main menu
			} while(subMenuSelection != 6);
			
		} 
		
		else if(menuSelection == 4)
		{
			//For updating stocks
			printf("\n4-Update Stock: \n");
			
			do {
				
				printf("Select Store: ");
				scanf("%d", &storeID);
				
				//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID again
				while (storeID < 1 || storeID > 10)
				{
					printf("\n!!!Invalid Input!!!\n\n");
					printf("Please Enter the Store ID Between 1-10: ");
					scanf("%d", &storeID);
				}
				
				printf("Enter Flower ID: ");
				scanf("%d", &flowerID);
				
				//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs flowerID again
				while (flowerID < 1 || flowerID > 10)
				{
					printf("\n!!!Invalid Input!!!\n\n");
					printf("Please Enter the Store ID Between 1-10: ");
					scanf("%d", &flowerID);
				}
				
				//Used -1 because user input between 1-10
				printf("Current Stock of Flower %d in Store %d: %d\n", flowerID, storeID, abcFlowerMarket[storeID-1][flowerID-1]);
				
				//Inputs new stock
				printf("Enter new stock: ");
				scanf("%d", &newStock);
				
				//Calls function with storeID, flowerID, newStock, array and its size
				updateStock(storeID, flowerID, newStock, abcFlowerMarket, 10);
			
				//Asks user to continue or not
				printf("\n1-Continue\n2-Return to Main Menu\nSelection: ");
					scanf("%d", &secondMenuSelection);
				
				//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs secondMenuSelection again		
					while(secondMenuSelection <= 0 || secondMenuSelection > 2)
					{
						printf("\n!!!Invalid Input!!!\n\n");
						printf("Please Enter 1 or 2: ");
						scanf("%d", &secondMenuSelection);
					}
		
					if(secondMenuSelection == 2)
						break;
			
				//If user inputs 2 program returns to the main menu
			} while(secondMenuSelection != 2);	 
			
		}
		
		//For finding stores which have all of the flowers in stock
		else if(menuSelection == 5)
		{
			printf("\n5-Find Stores Which Have All of the Flowers In Stock: \n");
			//Calls function with array and its size
			hasAllFlowers(abcFlowerMarket, 10);
		}
		
		//Terminating the program
		else if(menuSelection == 6)
		{
			printf("\nBYE!\n");
			break;
		}

	//If user inputs 6 program terminates
	}while (menuSelection != 6);
	


	return 0;
}

//Print stocks

void printStocks(int flowerMarket[][10])
{
	int i, j, k;
			
		for(k=0; k<10; k++)
			printf("\t   Flower %d", k+1);
		
		printf("\n");
		
		for(i=0; i<10; i++)
		{
			printf("Store %d:", i+1);	
		
			for(j=0; j<10; j++)
			{
				printf("\t%d       ", flowerMarket[i][j]);
			}
			printf("\n");
		}
	
}


//Input flower amount for a store

void inputFlowerAmount(int flowerMarket[][10])
{
	int storeID, flowerID, flowerAmount, subMenuSelection;
	
	do {
		
		printf("\nEnter a Flower ID: ");
		scanf("%d", &flowerID);
		
		//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs flowerID
		while (flowerID < 1 || flowerID > 10)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter the Flower ID Between 1-10: ");
			scanf("%d", &flowerID);
		}
		printf("Enter a Store ID: ");
		scanf("%d", &storeID);
		
		//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID
		while (storeID < 1 || storeID > 10)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter the Store ID Between 1-10: ");
			scanf("%d", &storeID);
		}
		printf("Enter Amount: ");
		scanf("%d", &flowerAmount);
		
		//Assigns inputted amount to inputted flowers and stores amount
		//Used -1 because user input between 1-10
		flowerMarket[storeID-1][flowerID-1] = flowerAmount;
		
		//Asks user to continue or not
		printf("\n1-Continue\n2-Return to Main Menu\nSelection: ");
		scanf("%d", &subMenuSelection);
	
		//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs subMenuSelection again
		while(subMenuSelection <= 0 || subMenuSelection > 2)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter 1 or 2: ");
			scanf("%d", &subMenuSelection);
		}
		
		if(subMenuSelection == 2)
			break;
			
		//If user inputs 2 program returns to the main menu	
	} while (subMenuSelection != 2);
	
}

//Stock control with flower ID and store ID

void stockControlWithIDs(int flowerID, int storeID, int flowerMarket[][10])
{
	int subMenuSelection;
	
	do {
		
		printf("\nEnter a Flower ID: ");
		scanf("%d", &flowerID);
		
		//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs flowerID
		while (flowerID < 1 || flowerID > 10)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter the Flower ID Between 1-10: ");
			scanf("%d", &flowerID);
		}
		printf("Enter a Store ID: ");
		scanf("%d", &storeID);
		
		//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs storeID
		while (storeID < 1 || storeID > 10)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter the Store ID Between 1-10: ");
			scanf("%d", &storeID);
		}
		
		//If its amount is different from zero output the result
		//Used -1 because user input between 1-10
		if(flowerMarket[storeID-1][flowerID-1] != 0)
			printf("Store %d: Flower %d Amount: %d\n", storeID, flowerID, flowerMarket[storeID-1][flowerID-1]);
		
		//If its amount is zero output error message
		else
			printf("There are no flower %d in store %d!!!\n", flowerID, storeID);
		
		
		//Asks user to continue or not
		printf("\n1-Continue\n2-Return to Main Menu\nSelection: ");
		scanf("%d", &subMenuSelection);
		
		
		//Checks whether the input is valid or invalid, if input is invalid outputs an error message and inputs subMenuSelection again
		while(subMenuSelection <= 0 || subMenuSelection > 2)
		{
			printf("\n!!!Invalid Input!!!\n\n");
			printf("Please Enter 1 or 2: ");
			scanf("%d", &subMenuSelection);
		}
		
		if(subMenuSelection == 2)
			break;
		
		//If user inputs 2 program returns to the main menu		
	} while (subMenuSelection != 2);
}

//List all flowers of store n

void listAllFlowersOfStore(int storeID, int flowerArray[][10])
{
	int i, j, subMenuSelection;

		printf("Store %d:\n", storeID);

		printf("Flower  ");
		for(i=0; i<10; i++)
			printf("%d   ", i+1);
		printf("\n");
		
		printf("Stock   ");
		for(i=0; i<10; i++)
			//Used -1 because user input between 1-10
			printf("%d  ", flowerArray[storeID-1][i]);
		printf("\n");

}

//List flowers exist in store n but not store m

void listFlowersDiffer(int firstStoreID, int secondStoreID, int firstStoreArray[], int secondStoreArray[], int firstStoreArraySize, int secondStoreArraySize)
{
	int i, same = 1;
	//Same variable is for cheking if both stores has the same flower types or not
	printf("\nFlowers that Exist in Store %d and not in Store %d: \n", firstStoreID, secondStoreID);
	
	for(i=0; i<firstStoreArraySize; i++)
	{
		if(firstStoreArray[i] >0 && secondStoreArray[i] == 0)
		{
			printf("Flower\t%d", i+1);
			printf("\nAmount\t%d\n", firstStoreArray[i]);
			same = 0;
		}
	}
	
	if(same == 1)
		printf("\nStore n and Store m has all the same flowers!");
	
}


//List flowers which exist in both store n and store m

void listFlowersCommon(int firstStoreID, int secondStoreID, int firstStoreArray[], int secondStoreArray[], int firstStoreArraySize, int secondStoreArraySize)
{
	int i, same = 0, counter = 0;
	//Same variable is for cheking if both stores has the same flower types or not
	//Counter variable is for understanding if we checked all of the array or not
	
	printf("Flowers Available Both Store %d and Store %d: \n", firstStoreID, secondStoreID);
	
	printf("Flower\t");
	
	for(i=0; i<firstStoreArraySize; i++)
	{
	
		if(firstStoreArray[i] != 0 && secondStoreArray[i] != 0)
		{
			same = 1;
			printf("%d\t", i+1);
			
		}	
		
		else 
		{
			same = 0;
			counter++;
		}	
			
	}
	
	printf("\nAmount\t");
	for(i=0; i<firstStoreArraySize; i++)
	{
	
		if(firstStoreArray[i] != 0 && secondStoreArray[i] != 0)
		{
			same = 1;
			printf("%d\t", firstStoreArray[i]);
			
		}	
		
		else 
		{
			same = 0;
			counter++;
		}		
	}
	
	if(same == 0 && counter == 10)
		printf("Store %d and Store %d does not have same flowers!\n", firstStoreID, secondStoreID);
}

//List flowers sorted by stock

void listFlowerSortedByStock(int flowerMarket[][10], int rowSize, int sortedFlowerID[], int sortedFlowerAmount[])
{
	int i, j, k=0, temp, indexTemp, amount = 0;
	//temp variable is for sorting the amounts of flowers
	//indexTemp variable is for holding the index value(flowerID)
	//amount variable is for sum up stores flower amounts
	
	for(i=0; i<10; i++)
	{		
		for(j=0; j<rowSize; j++)
		{
			amount += flowerMarket[j][i];
		}
		
		sortedFlowerID[i] = i;
		sortedFlowerAmount[i] = amount;
		amount = 0;
	}

	for(i=0; i<9; i++)
	{		
		for(j=i+1; j<10; j++)
		{
			if(sortedFlowerAmount[i] > sortedFlowerAmount[j])
			{
				//Sorting the flower amounts
				temp = sortedFlowerAmount[i];
				sortedFlowerAmount[i] = sortedFlowerAmount[j];
				sortedFlowerAmount[j] = temp;
				
				//Sorting flower IDs according to flower amounts
				indexTemp = sortedFlowerID[i];
				sortedFlowerID[i] = sortedFlowerID[j];
				sortedFlowerID[j] = indexTemp;
			}
			
		}
	}

}

//Find store having the largest amount of a flower

int storeHasLargestFlowerAmount(int flowerID, int flowerArray[])
{
	int i, maxFlowerAmount = 0, index;
	//maxFlowerAmount variable is for storing the maximum flower amount
	//index variable is for storing the storeID has most flowers
	
	for(i=0; i<10; i++)
	{
		if(flowerArray[i] > maxFlowerAmount)
		{
			maxFlowerAmount = flowerArray[i];
			index = i;
		}
	}
	
	return index;
}

//Update stock

void updateStock(int storeID, int flowerID, int newStock, int flowerMarket[][10], int rowSize)
{	
	//Used -1 because user input between 1-10	
	flowerMarket[storeID-1][flowerID-1] = newStock;
	
	if(newStock == 0)
		printf("Flower %d is out of stock in store %d\n", flowerID, storeID);
	
	printf("Done!\n");
}

//Find stores which have all of the flowers in stock

void hasAllFlowers(int flowerMarket[][10], int rowSize)
{
	int i, j, check = 0, counter = 0;
	//check variable is for understanding if we checked all the array or not
	//Counter variable is for how many flowers did we control

	printf("\nStores that have all of the Flowers in Stock: \n");
	
	
	for(i=0; i<rowSize; i++)
	{
		for(j=0; j<10; j++)
		{
			if(flowerMarket[i][j] >= 10)
				check = 1;
			
			else
			{
				check = 0;
				counter++;
				break;
			}
		}
		
		if(check == 1)
			printf("Store %d\n", i+1);
	}
			
	if(check == 0 && counter == 10)
		printf("\nNone of the Stores has all of the Flowers!\n");

}