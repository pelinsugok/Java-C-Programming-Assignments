#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menu(void);
int number(void);
int equal(int x, int y);
int input(void);
void swap(int a, int b, int c, int d);

int main (void)
{
	srand(time(NULL));
	int current_point=20, m;
	int digit1, digit2, digit3, digit4, i;
	int computer, attempt=1, guessing;
	int guess, guess1, guess2, guess3, guess4, counter=0, counter1=0, counter2=0, counter3=0, counter4=0;
	
	for(i=0; ; i++)
	{
		m=menu();
		
		if(m==2)
		{
			printf("2-Digit Game!\n");
			
			digit1=input();
			digit2=input();
			digit3=input();
			digit4=input();
			
			
			
			if(equal(digit1,digit2)==1 || equal(digit1,digit3)==1 || equal(digit1,digit4)==1)
			{
				printf("\nCannot enter the same digit twice!\nPlease enter another integer!\n");
				digit1=input();
			}

			if(equal(digit2,digit3)==1 || equal(digit2,digit4)==1)
			{
				printf("\nCannot enter the same digit twice!\nPlease enter another integer!\n");
				digit2=input();
			}

			if(equal(digit3,digit4)==1)
			{
				printf("\nCannot enter the same digit twice!\nPlease enter another integer!\n");
				digit3=input();
			}
			
			printf("Input 4 integers: %d %d %d %d", digit1, digit2, digit3, digit4);


				while(current_point>=0 && counter<=4)
				{
					printf("\nAttempt %d:\n", attempt);
					
					computer=number();
					printf("Computer guesses: %d\n", computer);
					
					if(counter1==0){
					if(equal(digit1, computer)==1)
					{
						printf("Correct!\n");
						current_point=current_point+5;
						guess1=digit1;
						counter=counter+1;
						counter1++;
						
					}
				}
					if(counter2==0){
					if(equal(digit2, computer)==1)
					{
						printf("Correct!\n");
						current_point=current_point+5;
						guess2=digit2;
						counter=counter+1;
						counter2++;
						
					}
					}
					if(counter3==0){
					if(equal(digit3, computer)==1)
					{
						printf("Correct!\n");
						current_point=current_point+5;
						guess3=digit3;
						counter=counter+1;
						counter3++;
						
					}
				}
					if(counter4==0){
					if(equal(digit4, computer)==1) 
					{
						printf("Correct!\n");
						current_point=current_point+5;
						guess4=digit4;
						counter=counter+1;
						counter4++;
			
					}	
					}
					if(equal(digit1, computer)==0 && equal(digit2, computer)==0 && equal(digit3, computer)==0 && equal(digit4, computer)==0)
					{
						printf("Incorrect!\n");
						current_point=current_point-4;
					}


					printf("Current score: %d\n", current_point);
					attempt=attempt+1;
					
				}
				
				printf("\nGame ended after %d attemtpts.\n", attempt);
				
				if(counter1==1 && counter2==1 && counter3==1 && counter4==1)
				{
					
				swap(guess1, guess3, guess2, guess4);
									
				for(guessing=1; guessing<=4; guessing++){
					printf("\n%d. order guess: %d %d %d %d", guessing, guess1, guess2, guess3, guess4);
					
					if(guess1==digit1 && guess2==digit2 && guess3==digit3 && guess4==digit4)
					{
						printf("\nCorrect!\n");
						printf("After %d guesses computer guessed the order correctly.\n", guessing);
						current_point=current_point+10;
						break;
					}
					else{
						printf("Incorrect!\n");						
						current_point=current_point-5;
					}
			}
			}	
			

		}
	}
	
	
	return 0;
}

int menu(void)
{
	int m;
	printf("\n1-Play Card Matching.\n2-Play Digit Game.\n3-Quit!\n");
	scanf("%d", &m);

	while(m!=1 && m!=2 && m!=3)
	{
		printf("\nInvalid choice! Please enter 1, 2 or 3!\n");
		printf("\n1-Play Card Matching.\n2-Play Digit Game.\n3-Quit!\n");
		scanf("%d", &m);		
	}	
		return m;	
}


int number(void)
{
	return (rand()%10);	
}

int equal(int x, int y)
{
	if(x==y)
		return 1;
	else 
		return 0;
}

int input(void)
{
	int digit;
	scanf("%d", &digit);
	
	while(digit/10>0)
	{
		printf("\nInvalid input! Please enter a 1-digit integer!\n");
		scanf("%d", &digit);
	}
	
	return digit;
}

void swap(int a, int b, int c, int d)
{
	int temp;
	
	temp=a;
	a=b;
	b=c;
	c=d;
	d=temp;
}
