/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "cardRecord.h"
#include "cardLL.h"

void printHelp();
void CardLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
      /*** Insert your code for stage 1 here ***/

      // create varibal n to get the n transport card records from user input
      int n;
      n = atoi(argv[1]);
      // allocate dynamic array to store n records on the heap
      cardRecordT *cardp = malloc(n*sizeof(cardRecordT));
      assert(cardp != NULL);

      // store input value
      for (int i=0; i<n; i++) {
         int card_ID = readValidID();
         cardp[i].cardID = card_ID;
         float amount = readValidAmount();
         cardp[i].balance = amount;
      }
      // caculate the Average balance
      float total_balance=0;
      float av_balance=0;
      for (int i=0; i<n; i++) {

         printCardData(cardp[i]);
         total_balance += cardp[i].balance;
      }
      av_balance = total_balance/n;
      printf("Number of cards on file: %d\n", n);
      printf("Average balance: $%.2f\n", av_balance);
      // free the dynamically allocated memory
      free(cardp);
      
   } else {
      CardLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;

   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':{
            int card_iD = readValidID();
            float a_mount = readValidAmount();
            insertLL(list, card_iD, a_mount);
            while(getchar()!='\n');
            /*** Insert your code for adding a card record ***/
	    break;
       }

         case 'g':
         case 'G':{
            int *N = malloc(sizeof(int)); //malloc 2 pointers for funtion getAverageLL() and set the initial value NULL
            float *am_ount = malloc(sizeof(float));
            getAverageLL(list,N,am_ount);
            free(N);
            free(am_ount);
            /*** Insert your code for getting average balance ***/
	    break;
	    }
         case 'h':
         case 'H':{
            printHelp();
         
	    break;
	    }
         case 'p':
         case 'P':{
            showLL(list);
            /*** Insert your code for printing all card records ***/

	    break;
       }
         case 'r':
         case 'R':{
            int card_ID = readValidID();
            removeLL(list, card_ID);
            while(getchar()!='\n');
            /*** Insert your code for removing a card record ***/
	    break;
       }
	      case 'q':
         case 'Q':{
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
       }
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}
