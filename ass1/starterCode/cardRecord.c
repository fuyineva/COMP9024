// Transport card record implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include "cardRecord.h"

#define LINE_LENGTH 1024
#define NO_NUMBER -999

// scan input line for a positive integer, ignores the rest, returns NO_NUMBER if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return NO_NUMBER;
   else
      return n;
}

// scan input for a floating point number, ignores the rest, returns NO_NUMBER if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if (sscanf(line, "%f", &f) != 1)
      return NO_NUMBER;
   else
      return f;
}

// Justify  whether or not the card_ID is 8 digital number
int readValidID(void) {
	int card_ID;
	printf("Enter card ID: ");
	while(scanf("%d", &card_ID)!=1 || (card_ID<10000000) || (card_ID>99999999)) {
		printf("Not valid. Enter a valid value: ");
		while(getchar()!='\n');
	}
	return card_ID;  /* needs to be replaced */
}

// Justify  whether or not the the amount is float and between -2.35 and 250
float readValidAmount(void) {
	float amount;
	printf("Enter amount: ");
	while(scanf("%f", &amount)!=1 || (amount<-2.35) || (amount>250)) {
		printf("Not valid. Enter a valid value: ");
		while(getchar()!='\n');
	}
	return amount;  /* needs to be replaced */
}

// To illustrate the output
void printCardData(cardRecordT card){
	printf("-----------------\n");
	printf("Card ID: %d\n", card.cardID);
	// if balance is negative number then need change outcome formate
	if (card.balance<0){
		printf("Balance: -$%.2f\n", -1*card.balance);
		
	}
	else{
		printf("Balance: $%.2f\n", card.balance);
	}
	// if balance smaller than 5 dollar, then print low banlance
	if (card.balance<5.00){
		printf("Low balance\n");
	}
	printf("-----------------\n");
   return;  /* needs to be replaced */
}
