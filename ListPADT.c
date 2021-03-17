// ListPADT.c
/*              ��������� ������������ ������ �������� - �� ������� 
                �� �������� ��� ������ ����� ����� int */
            
#include <stdio.h>
#include <stdlib.h>
#include "ListPADT.h"

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����. 
  ����������:  ��� �������� ������ List 
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����. 
  ����������: ������� �� � ����������� ����� ����� ����. 
  ����������: True �� � ����� ����� ���� ��� false ����������� 
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����, 
                ��� �������� ��������� Item ��� ���� ������ PredPtr. 
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� ����� 
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr 
                � ���� ����  ��� ������������ ������, 
                �� � PredPtr ����� ���������(NULL). 
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ��� 
                �� �������������� ��� ��� List. 
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   printf("Insert &List %7d, List %7d,  &(*List) %7d, (*List) %7d, TempPtr %7d\n",
   &List, List,  &(*List), (*List), TempPtr);
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
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� ����� ���
                 ��� ���� ������ PredPtr. 
   ����������: ��������� ��� �� ����������� ����� ��� ����� ��� ���� 
                ��� ����������� ��� ����� ���� ����� ������� � PredPtr 
                � ��������� ��� ����� �����, �� � PredPtr ����� ���������, 
                ����� ��� �� � ����� ����� ����. 
   ����������: ��� ������������� ����������� ����� �� ��� ����� ����� 
                �� �������������� ��� ��� List. 
   ������:     ��� ������ ����� ������ �� � ����������� ����� ���� ���� .
*/
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
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����. 
   ����������: ��������� �� ����������� ����� ��� 
                ������������� ���� �������� ������� ��� ����. 
   ����������: ��������� ��� �� ����� ��� ������������.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	    printf("%7s, %7s, %7s, %12s, %12s\n","&List","List","&(*List)","(*List).Data","(*List).Next");
   	    printf("%7d, %7d, %8d, %12d, %12d\n",&List, List, &(*List),(*List).Data, (*List).Next);
         printf("\n");
         printf("%7s, %10s\n","&CurrPtr", "&(*CurrPtr)");
         while ( CurrPtr!=NULL )
        {
      	     printf("%8d, %11d\n",&CurrPtr, &(*CurrPtr));
             printf("%21d, %d, %d\n",CurrPtr, (*CurrPtr).Data, (*CurrPtr).Next);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����. 
  ����������: ������� ��� �������� ��������� ���� �� ������������ ����������� 
              ����� ��� ���� ����� ��� �� �������� �� �������� Item. 
  ����������: �� � ��������� ����� �������� � Found ����� true, � CurrPtr �������
                ���� ����� ��� �������� �� Item ��� � PredPtr ���� ����������� ��� 
                � ����� nil �� ��� ������� ������������. 
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean stop;
   
   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:    ��� �������� Item ��� ��� ������������ ����������� �����, 
                ��� �������� �������� ��������� �� ������� ������� ��� ���� ����� 
                � ������� List ������� ���� �����  �����. 
   ����������: ������� �������� ��������� ��� ������������ ������������� ������ 
                ��� ��� ����� ����� ��� �������� �� �������� Item � ��� ��� ����
                ��� �� ������� ��� ��� ����� ��� �� �������� �� �������� Item. 
   ����������: �� � ��������� ����� �������� � Found ����� true, 
                � CurrPtr ������� ���� ����� ��� �������� �� Item ��� 
                � PredPtr ���� ����������� ��� � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}


