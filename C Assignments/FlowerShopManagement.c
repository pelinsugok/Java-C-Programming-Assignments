#include<stdio.h>

void printMainMenu(void);																	//A function for printing the menu
void printStockInformation(void);															//A function for printing the stock information
void printProductPrices(void);																//A function for printing the product prices
void printProducts(void);																	//A function for printing the products
void printCashInformation(void);															//A function for printing the cash information
int stockControl(int productStockInfo, int numberOfRequested);								//A function for checking the stocks
void updateStocks(void);																	//A function for updating the stocks
void updatePrices(void);																	//A function for updating the prices
void sell(int productPrice, int numberOfRequested);											
int calculateBill(int productPrice, int numberOfRequested);
int addMoney(void);

int redRose=0, pinkRose=0, whiteRose=0, yellowRose=0, blackRose=0;							//I initialize the stocks to zero
int priceRed=5, pricePink=6, priceWhite=7, priceYellow=8, priceBlack=20;					//I initialize the prices of the roses 
int cash=0, bill=0;

int main (void) {																			//Beginning of the main function
	
	int menu, a, selection1, selection2;													
	do{																						//I used a do-while loop for menu to return until user chooses to quit
	
		printMainMenu();
		printf("\nSelect your operation: ");
		scanf("%d", &menu);
		
		if(menu==1)
			printStockInformation();
		else if(menu==2)
		{
			printStockInformation();
			updateStocks();
		}
		else if(menu==3)
		{
			printProductPrices();
			updatePrices();
		}
		else if(menu==4)
		{
			sell(selection1, selection2);													//Since every price and stock information is different for every color, i used an arbitrary integer variable for this functions parameter	
		}
		else if(menu==5)
			printCashInformation();
			
		else
			printf("\nInvalid input!\n");
			
 }while (menu!=6);
 	printf("\nGoodbye!");
 	
	return 0;
}																							//End of the main function

void printMainMenu(void)
{
	printf("\nOPERATIONS:\n\n1. Stock Info\n2. Update Stocks\n3. Update Prices\n4. Sell\n5. Current Cash Info\n6. Quit\n");
}

void printStockInformation(void)
{
	printf("\nCurrent Stock Information:\n1. Red Rose: %d\n2. Pink Rose: %d\n3. White Rose: %d\n4. Yellow Rose: %d\n5. Black Rose: %d\n", redRose, pinkRose, whiteRose, yellowRose, blackRose);
}

void printProductPrices(void)
{
	printf("\nPrices :\n1. Red Rose : %d TL\n2. Pink Rose : %d TL\n3. White Rose : %d TL\n4. Yellow Rose : %d TL\n5. Black Rose : %d TL\n", priceRed, pricePink, priceWhite, priceYellow, priceBlack);
}

void printProducts(void)
{
	printf("\nProducts :\n1. Red Rose - %d TL - (%d)\n2. Pink Rose - %d TL - (%d)\n3. White Rose - %d TL - (%d)\n4. Yellow Rose - %d TL - (%d)\n5. Black Rose - %d TL - (%d)\n", priceRed, redRose, pricePink, pinkRose, priceWhite, whiteRose, priceYellow, yellowRose, priceBlack, blackRose);
}

void printCashInformation(void)
{
	printf("\nCurrent Cash Information: %d TL\n", cash);
}

int stockControl(int productStockInfo, int numberOfRequested)									//I checked if the requested number of items is equal or less then the stock of the product
{
	if(productStockInfo>=numberOfRequested)
		return 1;
	else
		return 0;
}

void updateStocks(void)																			
{
	int number, menuChoice;
	do 																							////I used loop for user to update as many items as they wanted, until user chooses to quit
	{
		printf("\nSelect product: ");														
		scanf("%d", &number);
		if (number==1)
		{
			printf("\nEnter stock for 'Red Rose' product: ");										//I used global variables for stock informations so i update the variables due to users request, for all the colors
			scanf("%d", &redRose);
		}	
		else if (number==2)
		{
			printf("\nEnter stock for 'Pink Rose' product: ");
			scanf("%d", &pinkRose);
		}
		else if (number==3)
		{
			printf("\nEnter stock for 'White Rose' product: ");
			scanf("%d", &whiteRose);
		}
		else if (number==4)
		{
			printf("\nEnter stock for 'Yellow Rose' product: ");
			scanf("%d", &yellowRose);
		}
		else if (number==5)
		{
			printf("Enter stock for 'Black Rose' product: ");
			scanf("%d", &blackRose);
		}
		else
			printf("\nInvalid input!\n");		
	
	printStockInformation();
	
	printf("\nOPERATIONS:\n\n1. Continue update stocks\n2. Return main menu\n\nSelect your operation: ");
	scanf("%d", &menuChoice);
	
	} while(menuChoice==1);
}

void updatePrices(void)																			
{
	int choice, menuChoice;
	do																							//I used loop for user to update as many items as they wanted, until user chooses to quit
	{
		printf("\nSelect product: ");
		scanf("%d", &choice);
		if (choice==1)																			//I used global variables for prices so i update the variables due to users request, for all the colors
		{
			printf("\nEnter new price for 'Red Rose' product: ");
			scanf("%d", &priceRed);
		}	
		else if (choice==2)
		{
			printf("\nEnter new price for 'Pink Rose' product: ");
			scanf("%d", &pricePink);
		}
		else if (choice==3)
		{
			printf("\nEnter new price for 'White Rose' product: ");
			scanf("%d", &priceWhite);
		}
		else if (choice==4)
		{
			printf("\nEnter new price for 'Yellow Rose' product: ");
			scanf("%d", &priceYellow);
		}
		else if (choice==5)
		{
			printf("\nEnter new price for 'Black Rose' product: ");
			scanf("%d", &priceBlack);
		}
		else
			printf("\nInvalid input!\n");
		
		printProductPrices();
		
		printf("\nOPERATIONS:\n\n1. Continue update prices\n2. Return main menu\n\nSelect your operation: ");
		scanf("%d", &menuChoice);
		
	} while(menuChoice==1);
	
}

void sell(int productPrice, int numberOfRequested)												//Since every price and stock information is different for every color, i used an arbitrary variable for this functions parameter
{
	int choice, menuChoice, total;
	do																							//I used loop for user to update as many items as they wanted, until user chooses to quit
	{
		printProducts();
		printf("\nSelect product: ");
		scanf("%d", &choice);
		
		if(choice==1)
		{
			printf("\nEnter how many 'Red Rose' products are requested: ");
			scanf("%d", &numberOfRequested);
			if(stockControl(redRose, numberOfRequested)==1)
			{
				total=calculateBill(priceRed, numberOfRequested);								//For each purchase I updated the total money in the register
				redRose=redRose-numberOfRequested;
				printProducts();												//For each purchase I updated the stock information 
			}
			else
				printf("\nSORRY... 'Red Rose' product is out of stock!\n");
					 				
		}
		if(choice==2)
		{
			printf("\nEnter how many 'Pink Rose' products are requested: ");
			scanf("%d", &numberOfRequested);
			if(stockControl(pinkRose, numberOfRequested)==1)
			{
				total=calculateBill(pricePink, numberOfRequested);
				pinkRose=pinkRose-numberOfRequested;
				printProducts();
			}
			else
				printf("\nSORRY... 'Pink Rose' product is out of stock!\n");					 				
		}
		if(choice==3)
		{
			printf("\nEnter how many 'White Rose' products are requested: ");
			scanf("%d", &numberOfRequested);
			if(stockControl(whiteRose, numberOfRequested)==1)
			{
				total=calculateBill(priceWhite, numberOfRequested);
				whiteRose=whiteRose-numberOfRequested;
				printProducts();
			}
			else
				printf("\nSORRY... 'White Rose' product is out of stock!\n");
					 				
		}
		if(choice==4)
		{
			printf("\nEnter how many 'Yellow Rose' products are requested: ");
			scanf("%d", &numberOfRequested);
			if(stockControl(yellowRose, numberOfRequested)==1)
			{
				total=calculateBill(priceYellow, numberOfRequested);
				yellowRose=yellowRose-numberOfRequested;
				printProducts();
			}
			else
				printf("\nSORRY... 'Yellow Rose' product is out of stock!\n");					 				
		}
		if(choice==5)
		{
			printf("\nEnter how many 'Black Rose' products are requested: ");
			scanf("%d", &numberOfRequested);
			if(stockControl(blackRose, numberOfRequested)==1)
			{
				total=calculateBill(priceBlack, numberOfRequested);
				blackRose=blackRose-numberOfRequested;
				printProducts();
			}
			else
				printf("\nSORRY... 'Black Rose' product is out of stock!\n");					 				
		}
		
		printf("\nOPERATIONS:\n1. Continue selling\n2. Return main menu\n\nSelect your operation: ");
		scanf("%d", &menuChoice);		
		
	} while(menuChoice==1);
	
}

int calculateBill(int productPrice, int numberOfRequested)
{
	int resultant;
	
	bill=numberOfRequested*productPrice;
	printf("\n%dx%d=%d", numberOfRequested, productPrice, bill);
	resultant=addMoney();
		
	return bill;
}

int addMoney(void)
{
	printf("\nAdd %d TL to cash register\n", bill);
	cash+=bill;
	
	return bill;
}