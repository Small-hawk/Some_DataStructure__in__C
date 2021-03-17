#include <stdio.h>
#include <stdlib.h>


typedef int StackElementType;           /*� ����� ��� ��������� ��� �������
                                        ���������� ����� int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TransferStack(StackPointer Stack1,StackPointer *Stack2);
void TraverseStack(StackPointer Stack);

main(){
    
    StackPointer AStack, BStack;
    StackElementType AItem;
    int i, numbOfNodes;
    
    CreateStack(&AStack);
    CreateStack(&BStack);
    
    printf("Plithos komvwn: ");
    scanf("%d", &numbOfNodes);

    for(i=0; i<numbOfNodes; i++){
        printf("Eisagete to %do stoixeio: ",i+1);
        scanf("%d", &AItem);
        Push(&AStack, AItem);
    }
        //TraverseStack(AStack);
    printf("\n*** 1h Lista ***\n");
    TraverseStack(AStack);
    
    TransferStack(AStack,&BStack);
    
    printf("\n\n*** 2h Lista ***\n");
    TraverseStack(BStack);
    
    printf("\n\n");
    system("pause");
    

}

void TransferStack(StackPointer Stack1,StackPointer *Stack2)
{
    	StackPointer CurrPtr;
    	StackElementType Item;

   if (EmptyStack(Stack1))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack1;
         while ( CurrPtr!=NULL )
        {
             Pop(&CurrPtr,&Item);
      	     Push(&(*Stack2),Item);
            
        }
   }
}


void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
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
      	     printf("  %d", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

