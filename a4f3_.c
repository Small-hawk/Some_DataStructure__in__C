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
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
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

    while (n>=QueueLimit)
    {
        printf("Give a correct Integer (Integer smaller from 20!): ");
        scanf(" %d ", &n);
        fflush(stdin);
    }
    GetNthElementA(&Queue5, n);
    TraverseQ(Queue5);
    GetNthElementB(Queue5, n);


system("Pause");
}




void CreateQ(QueueType *Queue)
{
	Queue->Front = 1;
	Queue->Rear = 1;
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



void GetNthElementA(QueueType *Queue, int N)
/* EINAI MIA DIADIKASIA POY AFAIREI APO MIA SEIRA TO N-IOSTO STOIXEIO
KAI EPISTREFEI TIN SEIRA XWRIS TO STOIXEIO AUTO*/
{
    printf("\nEKTELESH THS GetNthElementA\n"); //Den xreiazetai auti i grammi, apla enimerwnei
    int It,i;
    QueueType TempQ; //TempQ=Endiamesi seira pou DEN periexei to N stoixeio
    CreateQ(&TempQ);
    int mikos=0;
    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue,&It);


        AddQ(&TempQ,It);
        if(mikos==N)
        {
            printf("%d \n",Queue->Element[mikos]);
        }
        mikos++;


        }

        for(i=1;i<=(mikos);i++) //apokatastasi arxikis ouras XWRIS TO N-IOSTO STOIXEIO
        {
            RemoveQ(&TempQ,&It);
            AddQ(Queue,It);
        }
}


void GetNthElementB(QueueType Queue, int N)
/* EINAI MIA DIADIKASIA POY DEIXNEI SE MIA SEIRA TO N-IOSTO STOIXEIO
KAI EPISTREFEI TIN TIMI TOU STOIXEIOY AYTOY*/
{
    int p,Item;

    printf("\nEKTELESH THS GetNthElementB\n");
    p=Queue.Rear-Queue.Front; //mikos tis seiras (sto paradeigma einai 20-0)

    Item = Queue.Element[N-1];

    printf("To %do stoixeio exei timi %d\n",N,Item);
}
/*καλείτε ως:
GetNthElementB(Seira,inputN); //οπου inputN ειναι το N στοιχειο που ζηταμε με scanf
GetNthElementA(&Seira,inputN); //οπου inputN ειναι το N στοιχειο που ζηταμε με scanf*/
