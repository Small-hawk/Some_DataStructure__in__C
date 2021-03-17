#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);

void delete_list_every_second_element(ListPointer *List);

int main()
{
    ListPointer AList,PredPtr;
    ListElementType Item;

    CreateList(&AList);
    PredPtr=NULL;
    int n, i;
    printf("Number of items in the list:");
    scanf("%d",&n);
    CreateList(&AList);
    for(i=0;i<n;i++)
    {
        printf("Give the number: ");
        scanf("%d",&Item);
        LinkedInsert(&AList, Item, PredPtr);
    }
    LinkedTraverse(AList);
    delete_list_every_second_element(&AList);
    LinkedTraverse(AList);
    system("PAUSE");
    return 0;


}

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
             printf("%d\n",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void delete_list_every_second_element(ListPointer *List)
{
    ListPointer TempPtr, PredPtr;
    int count;

    if(!EmptyList(*List))
    {
        TempPtr=*List;
        PredPtr=NULL;
        count=1;
        while(TempPtr!=NULL)
        {
            if(count%2==0)
            {
                LinkedDelete(&(*List), PredPtr);
                TempPtr=PredPtr->Next;
            }
            else
            {
                PredPtr=TempPtr;
                TempPtr=TempPtr->Next;
            }
            count++;
        }

    }
}


