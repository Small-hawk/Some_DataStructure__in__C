/************************************************************
*a1f3 
 it1132
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Queue */
#define QueueLimit 21

typedef int QueueElementType;  
                             

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
int QSizeA(QueueType val);
int QSizeB(QueueType Q);
void TraverseQ(QueueType A);

main() {
    
     QueueType oura;
     CreateQ(&oura);
     
     int i,plithosA,plithosB;
     
     printf("Quation a \n" );
     
     for(i=0;i<=20;i++){
         AddQ(&oura, i);   
    }
    TraverseQ(oura);
    plithosA = QSizeA(oura);
    plithosB = QSizeB(oura);
    printf("QSizeA : %d\n",plithosA);
    printf("QSizeB : %d\n",plithosB);
    
    printf("\nQuation b \n" );
    
    TraverseQ(oura);
    QueueElementType k;    
    for(i=0;i<10;i++){
         RemoveQ(&oura, &k);
    }
    TraverseQ(oura);
    plithosA = QSizeA(oura);
    plithosB = QSizeB(oura);
    printf("QSizeA : %d\n",plithosA);
    printf("QSizeB : %d\n",plithosB);
    
    printf("\nQuation c \n" );
    
    for(i=0;i<10;i++){
         RemoveQ(&oura, &k);
    }
    TraverseQ(oura);
    plithosA = QSizeA(oura);
    plithosB = QSizeB(oura);
    printf("QSizeA : %d\n",plithosA);
    printf("QSizeB : %d\n",plithosB);

    
    system("PAUSE");
}

int QSizeA(QueueType val){
     int plithos;
     plithos = val.Rear - val.Front;
     return plithos;
}

int QSizeB(QueueType Q){
    int plithos = 0;
    QueueElementType angel;
    while (!EmptyQ(Q)){
        RemoveQ(&Q,&angel);
        plithos++;
    }
    return plithos;      
}

void TraverseQ(QueueType A){
    printf("\n");
    QueueElementType angel;
    while (!EmptyQ(A)){
        RemoveQ(&A,&angel);
        printf("%d ",angel);
    }
    printf("\n");
}
    
void CreateQ(QueueType *Queue)

{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)

{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}
