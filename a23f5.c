#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define  MaxElements 10          //το μέγιστο πλήθος των στοιχείων του σωρού

typedef int  HeapElementType;    //ο τύπος δεδομένων των στοιχείων του σωρού
typedef  struct {
     int key;
     HeapElementType Data;
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);


void menu(int *choice);
void PrintHeap(HeapType Heap);

main()
{

   int choice ;
   char ch;
   HeapType AHeap;
   HeapNode AnItem;

   CreateMinHeap(&AHeap);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	do
            {
   	            printf("Enter a number : ");
                scanf("%d", &AnItem);
                InsertMinHeap(&AHeap, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2:	if (EmptyHeap(AHeap))
                        printf("Empty Heap\n");
                    else
                        printf("Not an Empty Heap\n");
         			break;
         case 3:    if (EmptyHeap(AHeap))
                        printf("Empty Heap\n");
                    else
                    {
                        DeleteMinHeap(&AHeap, &AnItem);
         			    printf("Dleted Item is %d \n",AnItem);
                    }
         			break;
        case 4:    if (EmptyHeap(AHeap))
                        printf("Empty Heap\n");
                    else PrintHeap(AHeap);
         			break;
		}
   } while (choice!=5);

	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Insert an element to the Heap\n");
    printf("2. Check if Heap is empty\n");
    printf("3. Delete an element from  Heap\n");
    printf("4. Print Heap\n");
    printf("5. Telos\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>5);
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("%d \n",Heap.Size);
     printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%d, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%d, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%d \n",Heap.Element[r].key);
         else printf(" \n");
     }
}



void CreateMinHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ελέγχει αν ο σωρός είναι κενός.
   Επιστρέφει: TRUE αν ο σωρός είναι κενός, FALSE διαφορετικά
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό.
   Λειτουργία: Ελέγχει αν ο σωρός είναι γεμάτος.
   Επιστρέφει: TRUE αν ο σωρός είναι γεμάτος, FALSE διαφορετικά
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
/*  Δέχεται:    Ένα σωρό Heap και ένα στοιχείο δεδομένου Item .
    Λειτουργία: Εισάγει το στοιχείο Item στο σωρό, αν ο σωρός δεν είναι γεμάτος.
    Επιστρέφει: Τον τροποποιημένο σωρό.
    Έξοδος:     Μήνυμα γεμάτου σωρού αν ο σωρός είναι γεμάτος
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key < Heap->Element[hole/2].key)// monh allagh
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        (*Item)=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)   //oxi allagh. to child elegxei an exoume 
                                                //3eperasei twn arithmo twn komvwn 
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key) //1h allagh. mas endiaferei na anevei pros ta panw to mikrotero paidi
                    child++;
            if (last.key <= (*Heap).Element[child].key) //2h allagh. prepei na einai last<child gt to last exei metafer8ei sthn riza
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}
