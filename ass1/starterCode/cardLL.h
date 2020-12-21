// Linked list of transport card records header file ... Assignment 1 COMP9024 18s2
// DO NOT CHANGE

typedef struct ListRep *List;

List newLL();              // set up empty list
void dropLL(List);         // remove unwanted list
void showLL(List);         // display all card records in list
void removeLL(List, int);  // find and remove card record

// given cardID and amount ...
// ... Stage 2: insert new record at the beginning of the list
// ... Stage 3: insert in ascending order (if cardID new) else update card balance
void insertLL(List, int, float);

// get average balance: #cards, average balance
void getAverageLL(List, int *, float *);
