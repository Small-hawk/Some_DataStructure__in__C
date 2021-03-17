/*             ASKISI 8
*             FYLLADIO 2
*    STYLIANOS KARAKOSTAS it12146
*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 50


typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

main(){

int Stackarray[256];
int pointC=0,correct=0, Number=0,Remainder,i;
StackType StackOfRemainders;
int Response, item;

  CreateStack(&StackOfRemainders);

    printf(" Enter string: \n ");

    while (item!=13)
        {
            item=getch();
            if(item!=13)
                {
                    Number=Number+1;
                    Stackarray[Number]=item;
                    putch(Stackarray[Number]);
                    printf(" \n ");
                }
        }

    for(i=1;i<=Number;i++)
        {
            if(Stackarray[i]=='C')
             {pointC=i;}
        }


    for(i=1;i<pointC;i++)
        {
            Push(&StackOfRemainders,Stackarray[i]);
        }


        /* ELEGXOS */


    for (i=(pointC+1);i<=Number;i++)
        {
            Pop(&StackOfRemainders,&Response);
            item=Stackarray[i];
            if(Response==item)
                {correct=correct+1;}
        }

    if (correct==((Number-1)/2))
        {
            printf("\n TRUE \n");
        }
    else
        {
            printf("\n FALSE \n");
        }


system("Pause");
return 0;

}



void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}



void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack))
        {
            Stack -> Top++;
            Stack -> Element[Stack -> Top] = Item;
        }
        else
            printf("Full Stack...");
}


boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}


void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack))
    {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    }
    else
        printf("Empty Stack...");
}


boolean FullStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}
