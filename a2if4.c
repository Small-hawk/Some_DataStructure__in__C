/*             ASKISI 2i
*             FYLLADIO 4
*    STYLIANOS KARAKOSTAS it12146
*/


#include<stdio.h>
#include<stdlib.h>
#define ListLimit 50


typedef int ListElementType;
typedef struct ListNode *ListPointer;


typedef struct ListNode
{
    ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum
{
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType item, ListPointer *PredPtr, boolean *Found);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void delete_list(ListPointer *List);
void Intesection_List(ListPointer AList, ListPointer BList, ListPointer *FinalList);


main()
{
    ListPointer AList,PredPtr,BList,FinalList;
    int i, item, num;
    CreateList(&AList);
    printf("List Size: ");
    scanf("%d",&num);
    printf("\n");

    for(i=1;i<=num;i++)
    {
        PredPtr=NULL;
        printf("the %d List Item is: ",i);
        scanf("%d",&item);
        printf("\n");
        LinkedInsert(&AList,item,PredPtr);

    }

    CreateList(&BList);

    printf("List Size :");
    scanf("%d",&num);
    printf("\n");

    for(i=1;i<=num;i++)
    {
        PredPtr=NULL;
        printf("the %d List Item is: ",i);
        scanf("%d",&item);
        printf("\n");
        LinkedInsert(&BList,item,PredPtr);

    }

    printf("First List\n");

    LinkedTraverse(AList);

    printf("\nSecond List\n");

    LinkedTraverse(BList);

    printf("\nFinal List\n");

    Intesection_List(AList,BList,&FinalList);

    LinkedTraverse(FinalList);


system("Pause");
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


void LinkedInsert(ListPointer *List, ListElementType item, ListPointer PredPtr)
{

    ListPointer TempPtr;
    TempPtr= (ListPointer)malloc(sizeof(struct ListNode));

    TempPtr->Data = item;
      if (PredPtr==NULL)
      {
          TempPtr->Next = *List;
          *List = TempPtr;
      }
      else
        {
            TempPtr->Next = PredPtr->Next; PredPtr->Next = TempPtr;
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
        while (CurrPtr!=NULL)
        {
            printf("%d", CurrPtr-> Data);
            CurrPtr = CurrPtr-> Next;
        }

        printf("\n");
    }
}

void LinearSearch(ListPointer List, ListElementType item, ListPointer *PredPtr, boolean *Found)
{
    ListPointer CurrPtr;     boolean stop;
    CurrPtr = List;
    *PredPtr = NULL;
    stop = FALSE;

    while (!stop && CurrPtr!=NULL )
    {
        if (CurrPtr->Data==item )
            stop = TRUE;
        else
        {
            *PredPtr= CurrPtr;
            CurrPtr = CurrPtr->Next;
        }
    }

    *Found=stop;
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

void delete_list(ListPointer *List)
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

void Intesection_List(ListPointer AList, ListPointer BList, ListPointer *FinalList)
{
    ListPointer TempPtr1, TempPtr2, PredPtr=NULL;
    CreateList(&(*FinalList));
    TempPtr1 = AList;

    while(TempPtr1!=NULL)
    {
        TempPtr2 = BList;
        while((TempPtr2!=NULL))
        {
            if(TempPtr1->Data==TempPtr2->Data)
             {

                 LinkedInsert(&(*FinalList),TempPtr1->Data,PredPtr);

             }
             TempPtr2=TempPtr2->Next;
        }
        TempPtr1=TempPtr1->Next;
    }
}
