#ifndef WORKPLACE_H_INCLUDED
#define WORKPLACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define S 50
#define s 5


typedef struct prod
{
  char name[S];
  char date[S];
  char n_number[S];
  int quantity;
  double price;

  struct prod *next;
}product;



int flog;//for deleteing the first element
product *CreateAndInputProdFIFO();
void PrintProduct(product *head);
product *CreateDinamicStruct();
void printTarget(product *temp);
int AddSubstractQuantity(product *h, int *n);
void PrintExpired(product *temp);
product *Target_Delete(product *h, int target, int **n);
product *BinFileRead(product *LIFO_head, int n);
void BinFileWrite(product *temp);


#endif // WORKPLACE_H_INCLUDED
