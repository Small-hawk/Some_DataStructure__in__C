/*             ASKISI 4
*             FYLLADIO 3
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 21



typedef int QueueElementType;


typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void GetNthElementA(QueueType *Queue, int N);
void GetNthElementB(QueueType Queue, int N);



main()
{
    int i, n;

    QueueType Queue5;
    QueueElementType Item;
    CreateQ(&Queue5);

    for (i=5; i<=100; i=i+5)
    {
        Item=i;
        AddQ(&Queue5, Item);
    }

    TraverseQ(Queue5);
    printf("Give an Integer: ");
    scanf("%d", &n);
    fflush(stdin);

    while(n>=QueueLimit || n<=0)
    {
        printf("Give a correct Integer (Integer smaller from 20!): ");
        scanf("%d", &n);
        fflush(stdin);
    }

    GetNthElementA(&Queue5, n-1);
    GetNthElementB(Queue5, n-1);



system("Pause");
return 0;

}



void CreateQ(QueueType *Queue)
{
	Queue->Front=0;
	Queue->Rear=0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Front)==((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item=Queue->Element[Queue->Front];
		Queue->Front=(Queue->Front +1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear=(Queue->Rear+1)%QueueLimit;
		Queue->Element[Queue ->Rear]=Item;
		Queue->Rear=NewRear;
	}
	else
		printf("Full Queue");

}

void TraverseQ(QueueType Queue)
{
	int current;

	current=Queue.Front;
	printf("Our Queue is: ");

	while (current!=Queue.Rear)
        {
            printf("%d ",Queue.Element[current]);
		    current=(current+1)%QueueLimit;
        }

    printf("\n");
}



void GetNthElementA(QueueType *Queue, int N)
{
    int It,i;
    int thesi=0;
    QueueType TempQ;
    CreateQ(&TempQ);

    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue,&It);
        AddQ(&TempQ,It);
        if(thesi==N)
        {
            printf("The %d item with the GetNthElementA has the value: %d \n",N+1,Queue->Element[thesi]);
        }
        thesi++;
     }

     for(i=1;i<=(thesi);i++)
        {
            RemoveQ(&TempQ,&It);
            AddQ(Queue,It);
        }
}


void GetNthElementB(QueueType Queue, int N)
{
    int p, Item;

    p=Queue.Rear-Queue.Front;

    Item = Queue.Element[N-1];
    printf("The %d item with the GetNthElementB has the value: %d\n",N+1,Item);
}
