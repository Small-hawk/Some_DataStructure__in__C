/*             ASKISI 8
*             FYLLADIO 4
*    STYLIANOS KARAKOSTAS it12146
*/

#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
}StackNode;

typedef enum
{
    FALSE, TRUE
}boolean;


void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void TraverseStack(StackPointer Stack);
void Pop(StackPointer *Stack, StackElementType *Item);
void Push(StackPointer *Stack, StackElementType Item);


int main()
{
    StackPointer AStack;
    StackElementType Item;
    int max;
    int *AnArray;
    int N,i,pos;

    CreateStack(&AStack);
    printf("Number of items in the stack: ");
    scanf("%d",&N);
    AnArray=(int*)malloc(N*sizeof(int));

    for(i=0;i<N;i++)
    {
        printf("Give the number: ");
        scanf("%d",&AnArray[i]);
    }

    max=AnArray[0];
    pos=0;
    Push(&AStack, pos);

    for(i=0;i<N;i++)
    {
        if(AnArray[i]>max)
        {
            while(!EmptyStack(AStack))
            {
                Pop(&AStack, &Item);
            }
            max=AnArray[i];
            pos=i+1;
            Push(&AStack,pos);
        }
        else if(AnArray[i]==max)
        {
            Push(&AStack,i);
        }
    }

    free(AnArray);
    printf("Max: %d\n",max);
    printf("Position: \n");
    TraverseStack(AStack);


system("Pause");
return 0;
}



void CreateStack(StackPointer *Stack)
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
{
	return (Stack==NULL);
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d\n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void Pop(StackPointer *Stack, StackElementType *Item)
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

void Push(StackPointer *Stack, StackElementType Item)
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}



