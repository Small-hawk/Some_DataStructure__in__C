#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//typedef char QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct {
    char userName[8];
	char fileName[12];
}QueueElementType;


typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

main()
{
    FILE* infile;
    QueueType AQueue, BQueue;
    QueueElementType AItem;
    int nscan;
    char termch;
    
    
    char User[]="USER";
    char Fort[]="FORT";
    
    CreateQ(&AQueue);
    CreateQ(&BQueue);

    infile = fopen("I13F4.dat", "r");
    
    if (infile == NULL)
        printf("Can't open %s\n", "I13F4.dat");
    else {
        while (TRUE)
        {
            nscan = fscanf(infile, "%8[^\n]%c", AItem.userName , &termch);
            if ( nscan == EOF ) break;
            if ( nscan != 2 || termch != '\n' ) {
                printf("Improper file format\n");
                break;
                }
            nscan = fscanf(infile, "%12[^\n]%c", AItem.fileName , &termch);
            if ( nscan == EOF ) break;
            if ( nscan != 2 || termch != '\n' ) {
                printf("Improper file format\n");
                break;
                }
            if( strncmp(User,AItem.userName,4)==0 || strncmp(Fort,AItem.userName,4)==0 )
               AddQ(&AQueue,AItem);   
            else
                AddQ(&BQueue,AItem);
        }
    }
    
    printf("Printing professors' jobs..\n");
    while(!EmptyQ(BQueue)){
        RemoveQ(&BQueue,&AItem);
        printf("\nPrinting the job of %s, %s\n", AItem.userName,AItem.fileName);
        system("pause");
    }
    printf("\nThere are no more jobs in this queue, proceeding with the next queue..\n");
    while(!EmptyQ(AQueue)){
        RemoveQ(&AQueue,&AItem);
        printf("\nPrinting the job of %s, %s\n",AItem.userName,AItem.fileName);
        system("pause");
    }

    printf("\nJob's done!\n");
    system("pause");
}

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

    
