#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void) {
	
	int menu, round, card1, card2, i;																		//card1 and card2 are random cards drawn by players.
	int score1=0, score2=0;																					//Points that players earn based on the card they draw.
	int counter1=0, counter2=0;																				//I used this counter to loop in case the player draws 3 cards.
	int sum1, sum2;																							//Total points earned by players at the end of the game.							
	
	srand(time(NULL));																						//I assigned a seed value for the srand function.
	

		for(i=0; ;i++) {																					//I created a loop to output the menu to the screen without any limitations.					
			printf("\n1- Start a New Game\n2- Display Rules\n3- Quit\n");
			scanf("%d", &menu);
		
		if(menu==1) {
			
			printf("Start a New Game!\n");
			sum1=0;																							//I assigned 0 to the total value to reset the total value when we restart the game.																		
			sum2=0;
		
			for(round=1; round<=5; round++) {																//I created a loop for up to 5 rounds of repetition of the game.													
				printf("\nRound %d:\n", round);
				card1=rand()%12+1;																			//I used the rand function to assign a random value to the card1 variable and limited it to 1 to 12.
				printf("Player 1 draws %d\n", card1);
				
				if(card1==3) {																				//I used the for loop to draw cards 3 times and outputted the cards that the player draw on the screen.																	
					printf("Player 1 draws");
					for(counter1=0; counter1<3; counter1++){
					card1=rand()%12+1;																
					printf(" %d ",card1);}
			
					if(card1==9){																			//Because the score depends on if one of the 3 cards drawn is 9, I checked if any of the cards drawn with the if structure are 9.
						score1=9;
						printf("\nPlayer 1 gets 9 points.\n");
					}
					else {
						score1=0;
						printf("\nPlayer 1 gets 0 points.\n");
					}
				}
				
				else if(card1==5){																			//I set up a loop that draws cards until 9 is drawn, and I defined a counter to find how many cards were drawn until 9 is drawn with this counter.
					counter1=0;
					printf("Player 1 draws");
					while(card1!=9){
						card1=rand()%12+1;
						printf(" %d ", card1);
						counter1++;
					}
					if(card1==9){
					printf("\nPlayer 1 gets %d points.\n", counter1); }
										
					score1=counter1;
				}
				
				else if(card1==9) {																			//I drew 2 cards separately and assigned their totals to a variable called sum1 to find the sum of the cards the player draw.
					printf("Player 1 draws");
					card1=rand()%12+1;
					printf(" %d ", card1);
					score1=card1;
						
					card1=rand()%12+1;
					printf(" %d ", card1);
					score1+=card1;
							
					printf("\nPlayer 1 gets %d points.\n", score1);
				}
					
				else if (card1==1 || card1==7 || card1==11) {												//I calculated that if the cards drawn were 1, 7, 11, the player gets as many points as the cards they have drawn.
					score1=card1;
					printf("Player 1 gets %d points.\n", score1);
				}
				
				else if(card1%2==0 && card1!=12) {															//Because even numbers other than 12 are 3 points, I checked if the number is even or not and found a situation where it is not 12 with the if structure.
					score1=3;
					printf("Player 1 gets %d points.\n", score1);
				}
				
				else if(card1==12) {																		//A situation where the drawn card is 12.
					score1=12;
					printf("Player 1 gets %d points.\n", score1);
				}					

				card2=rand()%12+1;																			//I repeated the steps of Player1 for Player 2.
				printf("Player 2 draws %d\n", card2);
				
								
				if(card2==3) {
					printf("Player 2 draws");
					for(counter2=0; counter2<3; counter2++){
					card2=rand()%12+1;
					printf(" %d ",card2);}
					if(card2==9){
						score2=9;
						printf("\nPlayer 2 gets 9 points.\n");
					}
					else {
						score2=0;
						printf("\nPlayer 2 gets 0 points.\n");
					}
				}
							
				else if(card2==5){
					counter2=0;
					printf("Player 2 draws");
					while(card2!=9){
						card2=rand()%12+1;
						printf(" %d ", card2);
						counter2++;
					}
					if(card2==9) {
					printf("\nPlayer 2 gets %d points.\n", counter2); }

					score2=counter2;
				}
		
					
					
				else if(card2==9) {
					printf("Player 2 draws");
					card2=rand()%12+1;
					printf(" %d ", card2);
					score2=card2;
						
					card2=rand()%12+1;
					printf(" %d ", card2);
					score2+=card2;
			
					printf("\nPlayer 2 gets %d points.\n", score2);
				}
					
				else if (card2==1 || card2==7 || card2==11) {
					score2=card2;
					printf("Player 2 gets %d points.\n", score2);
				}
				
				
				
				else if(card2%2==0 && card2!=12) {
					score2=3;
					printf("Player 2 gets %d points.\n", score2);
				}	
				 

				
				else if(card2==12) {
					score2=12;
					printf("Player 2 gets %d points.\n", score2);
				}
			

				sum1=sum1+score1;																				//I collected the points that players earned in a total variable called sum1 and sum2.
				sum2=sum2+score2;
				
				printf("Player1: %d\tPlayer 2: %d\n", sum1, sum2);												//At the end of each round, I outputted out the points that the players gets.
				
				if(sum1>=30 || sum2>=30 || round==5)															//I used the break command to end the loop if any of the players passed 30 points or if the round reached 5.
					break;
			}

		
			if(sum1>sum2)																						//The situation in which Player1 won the game.
				printf("\nGame Over!\nPlayer 1 wins with %d points, and the game lasted for %d rounds.\n", sum1, round);
			else if(sum2>sum1)																					//The situation in which Player2 won the game.
				printf("\nGame Over!\nPlayer 2 wins with %d points, and the game lasted for %d rounds.\n", sum2, round);
			else if(sum1==sum2 && round==5)																		//Both players could not pass 30 points and both players gets equal points at the end of the 5th round, it's an equality situation.
				printf("\nGame Over!\nIt's a tie! Both player has %d points at the end of 5th round.\n", sum1);
			else if(round!=5 && sum1==sum2 && sum1>=30)															//Both players passes 30 points and both player gets equal points before the 5th round, it's an equality situation.
				printf("\nGame Over!\nIt's a tie! Both player has %d points, and the game lasted for %d rounds.\n", sum1, round);				
							
		}																										//End of if(menu==1).
		
		else if(menu==2)
			printf("All even-numbered cards are worth 3 points except for 12, which is worth 12 points.\nIf a player draws 3, they draw 3 more cards. If one of them is equal to 9, they get 9 points; otherwise, they do not get any points.\nIf a player draws 5, they draw cards until they draw a 9. They get as many points as the number of cards they have drawn after the 5.\nIf a player draws 9, they draw 2 cards, and the number of points they get is equal to the sum of those 2 cards.\nIf the card player draws is not one of the above, they get as many points as the card they draw.\n");
		else if(menu==3){
			printf("Quit!\n");
			break;}
		else if (menu!=1 && menu!=2 && menu!=3)
			printf("\nInvalid choice! Please enter 1, 2 or 3!\n");
			
		}																										//End of the first for loop.
	
	return 0;
}																												//End of the int main function.
