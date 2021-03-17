#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define Null 0

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
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


CopyLists(ListPointer List, ListPointer *FinalList);


main()
{
   ListPointer PredPtr, CurrPtr1;
    ListElementType AItem ;
    ListPointer AList,FinalList;
    int numberNodes, i;

    CreateList(&AList);
    CreateList(&FinalList);

    printf("Dwse to plh8os to komvwn: ");
    scanf("%d",&numberNodes);

    for(i=0;i<numberNodes;i++)
    {
        printf("Dwse to stoixeio gia eisagwgh(%do komvo): ",i+1);
        scanf("%d", &AItem);
        LinkedInsert(&AList,AItem,Null);
    }
    printf("\n**arxikh lista**\n");
    LinkedTraverse(AList);

    
    
    printf("\n**telikh lista**\n");
    CopyLists(AList,&FinalList);
    
    LinkedTraverse(FinalList);

    

    system("pause");
}  
    
    
    


CopyLists(ListPointer List, ListPointer *FinalList){
    
    ListPointer CurrPtr1, CurrPtr2;
    ListPointer TempPtr;
    
    CreateList(&TempPtr);
    
    CurrPtr1=List;
   
    while( CurrPtr1!=Null){
        LinkedInsert(&TempPtr,(*CurrPtr1).Data,Null);
        
        CurrPtr1= (*CurrPtr1).Next;
    }
    
    while(TempPtr!=Null){
        LinkedInsert(&(*FinalList),(*TempPtr).Data,Null);
        
        TempPtr= (*TempPtr).Next;
        
    }
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
   //printf("Insert &List %7d, List %7d,  &(*List) %7d, (*List) %7d, TempPtr %7d\n",
   //&List, List,  &(*List), (*List), TempPtr);
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
   	     //printf("\n");
         
         while ( CurrPtr!=NULL )
        {
      	     
             printf(" %d",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}
