/*             ASKISI 5
*             FYLLADIO 3
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 20
#define StackLimit 50

typedef int StackElementType;
typedef int QueueElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void ReverseQ(QueueType *Queue);



main()
{
    QueueType AQueue;
    int i,addn;

    CreateQ(&AQueue);

    for(i=1; i<16; i++)
    {
        addn=i;
        AddQ(&AQueue, (2*addn));
    }

    TraverseQ(AQueue);
    ReverseQ(&AQueue);
    TraverseQ(AQueue);

system("Pause");
return 0;

}



void CreateStack(StackType *Stack)
{
    Stack->Top=-1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top==-1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top==(StackLimit -1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack))
    {
        Stack->Top++;
        Stack->Element[Stack->Top]=Item;
    }
    else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack))
    {
        *Item=Stack->Element[Stack->Top];
        Stack->Top--;
    }
    else
        printf("Empty Stack");
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
	return ((Queue.Front)==((Queue.Rear+1)%QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue->Element[Queue->Front];
		Queue->Front=(Queue->Front+1)%QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear=(Queue ->Rear+1)%QueueLimit;
		Queue->Element[Queue->Rear]=Item;
		Queue->Rear = NewRear;
	}
	else
		printf("Full Queue");
}

void TraverseQ(QueueType Queue)
{
	int current;

	current=Queue.Front;
	while (current!=Queue.Rear)
    {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}

	printf("\n");
}


void ReverseQ(QueueType *Queue)
{
    int Item;

    StackType Stack;
    CreateStack(&Stack);

    Item=Queue->Front;

    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue, &Item);
        Push(&Stack, Item);
        Item=Queue->Element[Queue->Front-1];
    }

    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &Item );
        AddQ(Queue, Item);
    }
}



