// Transport card record header file ... Assignment 1 COMP9024 18s2
// DO NOT CHANGE

typedef struct {
   int   cardID;
   float balance;
} cardRecordT;

int   readValidID(void);
float readValidAmount(void);
void  printCardData(cardRecordT);
