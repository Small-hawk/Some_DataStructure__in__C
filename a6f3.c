#include <stdio.h>

#define QueueLimit 11 

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear, Count;//count metritis gematwn thesewn
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue,QueueElementType Item);


main()
{
    int i;
    QueueType AQueue;
    QueueElementType AnItem;
    
    AnItem=0;
    CreateQ(&AQueue);
    for(i=0;i<QueueLimit;i++)
    {
        AnItem++;
        AddQ(&AQueue,AnItem);
    }
    printf("---a---\n");
    TraverseQ(AQueue,-1);
    
    printf("---b---\n");
    AddQ(&AQueue, 2);
    TraverseQ(AQueue,-1);
    
    printf("---c---\n");
    RemoveQ(&AQueue,&AnItem);
    TraverseQ(AQueue,AnItem);
    
    printf("---d---\n");
    AddQ(&AQueue, 25);
    TraverseQ(AQueue,-1);
    
    printf("---e---\n");
    AddQ(&AQueue, 25);
    TraverseQ(AQueue,-1);
    
    system("pause");
}




void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	(*Queue).Count= 0;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.Count == QueueLimit-1);
}


void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		(*Queue).Count--;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
		(*Queue).Count++;
	}
	else
		printf("Full Queue");
}

void TraverseQ(QueueType Queue,QueueElementType Item) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	if(Item>-1)
	   printf("\nRemoved Item = %d",Item);
    printf("\nFront=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);
}
