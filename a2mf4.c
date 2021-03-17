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


int CountSum(ListPointer *List);

main()
{
    ListPointer AList,CurrPtr, PredPtr;
    ListElementType AItem;
    int sum ;
    char ch;
    
    PredPtr=Null;
    do {
        printf("Dwse ena arithmo gia eisagwgh sthn lista: "); 
        scanf("%d", &AItem);
        LinkedInsert(&AList, AItem, PredPtr);
        
        printf("\nContinue Y/N: ");
        do
        {
      	     scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');
    
    printf("\nList: ");
    //printf("\n%d",AList->Data);
    LinkedTraverse(AList);
    sum=CountSum(&AList);
    printf("\nTo athroisma twn stoixeiwn einai: %d\n", sum);
    
    system("pause");
    
}

int CountSum(ListPointer *List)
{
    int sum;
    ListPointer CurrPtr;
    
    sum=0;
    CurrPtr=*List;
    printf("%d",sum);
    while(TRUE){
        printf("%d",sum);
        sum+=(*CurrPtr).Data;
        CurrPtr=(*CurrPtr).Next;
        if(CurrPtr==Null) break;
    }
    printf("%d",sum);
    return sum;
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
