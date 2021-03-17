/*             ASKISI 11
*             FYLLADIO 4
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define Size 8



typedef char QueueElementType[Size];
typedef struct QueueNode *QueuePointer;



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

typedef enum
{
    FALSE, TRUE
} boolean;



boolean Search_for_Userid(char *User_Name);
boolean EmptyQ(QueueType Queue);
void CreateQ(QueueType *Queue);
void TraverseQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);



int main()
{
    QueueType Queue;
    QueuePointer Ptr;
    char Username[Size],ans;
    boolean found,log;

    CreateQ(&Queue);

    while(TRUE)
    {
        printf("USERNAME:");
        scanf("%s",Username);
        fflush(stdin);

        if(Search_for_Userid(Username)==TRUE)
        {
            found=TRUE;
            log=FALSE;
            Ptr=Queue.Front;


            while(Ptr!=NULL)
            {
                if(strcmp(Username,Ptr->Data)==0)
                {
                    printf("You have logged in to the system from another terminal.New access is forbidden\n");
                    log=TRUE;


                    while(TRUE)
                    {
                       printf("New Entry Y/N(Y=Yes,N=No)?\n");
                       scanf("%c",&ans);
                       fflush(stdin);
                       if(ans=='Y' || ans=='y' || ans=='N' || ans=='n') break;
                    }
                    break;
                }
                Ptr=Ptr->Next;
            }

            if(ans=='N' || ans=='n') break;

            if(log==FALSE)
            {
                AddQ(&Queue,Username);
                if(found==TRUE)
                {
                    while(TRUE)
                    {
                       printf("New entry Y/N(Y=Yes,N=No)?\n");
                       scanf("%c",&ans);
                       fflush(stdin);
                       if(ans=='Y' || ans=='y' || ans=='N' || ans=='n') break;
                    }

                    if(ans=='N' || ans=='n') break;
                }
            }
        }
        else
        {
            printf("Wrong user ID\n");

            while(TRUE)
            {
               printf("New entry Y/N(Y=Yes,N=No)?\n");
               scanf("%c",&ans);
               fflush(stdin);

               if(ans=='Y' || ans=='y' || ans=='N' || ans=='n') break;
            }

            if(ans=='N' || ans=='n') break;
         }
     }

     TraverseQ(Queue);




system("Pause");
return 0;
}



boolean Search_for_Userid(char *User_Name)
{
    FILE *fp;
    char str[Size];

    fp=fopen("i11f4.dat","r");
    if(fp==NULL)
            printf("Problem to opening the file\n");
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s",&str);
            if(strcmp(str,User_Name)==0)
            {
                fclose(fp);
                return TRUE;
            }
        }
    }
    fclose(fp);
    return FALSE;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
}



void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%s\n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}


void AddQ(QueueType *Queue, QueueElementType Item)
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    strcpy(TempPtr->Data,Item);
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        strcpy(TempPtr->Data,*Item);
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}



