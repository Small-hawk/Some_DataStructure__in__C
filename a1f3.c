/*             ASKISI 1
*             FYLLADIO 3
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 21



typedef int QueueElementType;

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;




void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
int QSizeA(QueueType Queue);
int QSizeB(QueueType *Queue);



main()
{
    int i=0, a=0, b=0;

    QueueType AQueue;
    QueueElementType AnItem;
    CreateQ(&AQueue);



    printf("Question a \n");
    while(i<QueueLimit)
    {
        AnItem=i;
        AddQ(&AQueue, AnItem);
        i++;
    }

    printf("Queue \n");
    TraverseQ(AQueue);

    a=QSizeA(AQueue);
    printf("<QSizeA> size of queue %d \n",a);

    b=QSizeB(&AQueue);
    printf("<QSizeB> size of queue %d \n \n",b);



    printf("Question b \n");
    i=0;
    while(i<QueueLimit)
    {
        AnItem=i;
        AddQ(&AQueue, AnItem);
        i++;
    }

    printf("Queue \n");
    TraverseQ(AQueue);

    i=0;
    while(i<10)
    {
        AnItem=i;
        RemoveQ(&AQueue,&AnItem);
        i++;
    }
    printf("Queue \n");
    TraverseQ(AQueue);

    a=QSizeA(AQueue);
    printf("<QSizeA> size of queue %d \n",a);

    b=QSizeB(&AQueue);
    printf("<QSizeB> size of queue %d \n \n",b);



    printf("Queation c");
    TraverseQ(AQueue);

    a=QSizeA(AQueue);
    printf("<QSizeA> size of queue %d \n",a);

    b=QSizeB(&AQueue);
    printf("<QSizeB> size of queue %d \n",b);



system("Pause");
return 0;
}




int QSizeA(QueueType Queue)
{
    int k;
    k= Queue.Rear- Queue.Front;

    return k;
}


int QSizeB(QueueType *Queue)
{
    int k=0, Item;
    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue,&Item);
        k++;
    }

    return k;
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
		printf("Full Queue \n");
}


void TraverseQ(QueueType Queue)
{
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
