// Linked list of transport card records implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cardLL.h"
#include "cardRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    cardRecordT data;
    struct node *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;

/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity:O(1), because of that the function requires 4 primitive operations.
// Explanation: creat a dynamic linked list  and the head is point null which means the list now is NULL
List newLL() {
	List L = malloc(sizeof(ListRep));
	assert(L != NULL);
	L->head = NULL;
   return L;  /* needs to be replaced */
}

// Time complexity: O(n), because of that we need through the whole Linked List and drop all data, 
//                  therefore, the complexity increases linearly in the worst case.
// Explanation: create a function that drop the certain list.
void dropLL(List listp) {
	NodeT *cur = listp->head;
	while(cur != NULL){
		NodeT *temp = cur->next;
		free(cur);
		cur = temp;
	}
	free(listp); // free the malloc of L in newLL and added the new_node which means destroy all list
   return;  /* needs to be replaced */
}

// Time complexity: O(n) for the worst case , and O(1) for best case
// Explanation: If cardid which removed is at the end of list,then it denpend on the size of list,
//				Thus, time complexity increases linearly in relation to number of elements. 
//              If cardid at the beginning of list , it just need several operation to remove.
//              So, time complexity is O(1).
void removeLL(List listp, int cardID) {
	// check whether the head conclude the cardid or not
	if(listp->head->data.cardID == cardID){
		NodeT *temp;
		temp = listp->head;
		listp->head = listp->head->next;
		temp->next =NULL;
		printf("Card removed.\n");
		return;
	}
	// if head not contain the cardid then through the list find the cardid and remove it
	else{
		NodeT *current_n;
		NodeT *temp;
		current_n = listp->head;
		temp = listp->head->next;
		while(temp!=NULL){
		if(temp->data.cardID == cardID){
			current_n->next = temp->next;
			temp->next=NULL;
			printf("Card removed.\n");
			return;
		}
		else{
			current_n = temp;
			temp = temp->next;
		}
		
	  }
	  //free(current_n);
	  //free(temp);
	}

	printf("Card not found.\n");
   return;    /* needs to be replaced */ 
}

// Time complexity:O(1) when inserting new card into the beginning of list.The main reason is 
//						the data just add the begnning of the list , not need to through the whole list
//				   O(n) when inserting new card in ascending order and not at the beginning
//						The reason is that new cardid need find a correct position which means that it need
//						through the list and jusrfy the calue. So, the time is also depends on the number of 
//						elements in the list and it is increase linearly. 
// Explanation: there are two stages 2 and 3 insert
void insertLL(List listp, int cardID, float amount) {
	// this is stage 2 code
	/*
	NodeT *new_node = malloc(sizeof(NodeT));
	assert(new_node != NULL);
	new_node->data.cardID = cardID;
	new_node->data.balance = amount;
	new_node->next = listp->head;
	listp->head = new_node;
	// when sucssess print "Card added."
	printf("Card added. \n");
	//free(new_node);
	*/
	// this is stage 3 code
	NodeT *new_node = malloc(sizeof(NodeT));
	assert(new_node != NULL);
	new_node->data.cardID = cardID;
	new_node->data.balance = amount;
	new_node->next = NULL;
	// if new cardid is smaller than head or listp is empty
	if (listp->head==NULL || cardID<listp->head->data.cardID){
		new_node->next = listp->head;
		listp->head = new_node;
		printf("Card added. \n");
		//free(new_node);
		return;
	}
	// if new cardid is same with the head, we update balance and print the data
	else if(cardID==listp->head->data.cardID){
		listp->head->data.balance = listp->head->data.balance+amount;
		printCardData(listp->head->data);
		free(new_node);
		return;

	}
	// if new card id is larger than head and not same with head 
	// then through the list find the correct position or update the value
	else{
		NodeT *curre = listp->head;
		while(curre->next != NULL){
			//if new cardid smaller than the next of current node and larger than current,
			// then insert it between current and the next node.
			if(cardID<curre->next->data.cardID){
				new_node->next = curre->next;
				curre->next = new_node;
				printf("Card added. \n");
				return;
			}
			else if (cardID==curre->next->data.cardID){
				curre->next->data.balance = curre->next->data.balance+amount;
				printCardData(curre->next->data);
				free(new_node);
				return;	
			}
			else{
				curre = curre->next;
			}
		}
		// when the curre->next is NULL which means that in the list no element large than new cardid
		// so, insert the data at the end
		new_node->next = NULL;
		curre->next = new_node;
		printf("Card added. \n");
		return;  /* needs to be replaced */
	}
   
}

// Time complexity:O(n), the main reason is that we need look the all list and count the number of card 
// 					     and calculate the total amount. So, it is increases linearly in relation to number of elements.
// Explanation: create a function that calculate average balance of all card and the number of cards
void getAverageLL(List listp, int *n, float *balance) {
	float total_amount = 0;
	float av_amount = 0;
	int number=0;
	// create a current pointer and use it calculate the number of card and banlance
	NodeT *current = malloc(sizeof(NodeT));
	assert(current != NULL);
	current = listp->head;
	while(current!= NULL){
		number ++;
		total_amount += current->data.balance;
		current=current->next;
	}
	n = &number;
	av_amount = total_amount/number;
	balance = &av_amount;
	printf("Number of cards on file: %d\n", *n);
	//whether average balance is negative or positive number
	if(av_amount<0){
		printf("Average balance: -$%.2f\n", -1*(*balance));

	}
	else{
	printf("Average balance: $%.2f\n", *balance);
	}
	free(current);
   return;  /* needs to be replaced */
}

// Time complexity: O(n), the reason is like before, we need through the link list and output every card data.
// 						  Hence, it is increases linearly.
// Explanation: show the card data which in the data of node of link list.
void showLL(List listp) {
	NodeT *curr;
	curr = listp->head;
	while(curr != NULL){
		printCardData(curr->data);
		curr=curr->next;
	}
   return;  /* needs to be replaced */
}
