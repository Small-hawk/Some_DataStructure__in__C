#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 5                          
#define NilValue 0       

typedef int ListElementType;
                             
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
}NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, boolean *found, ListPointer *PredPtr);
void InitializeStoragePool(NodeType Node[NumberOfNodes], ListPointer *FreePtr);
void CreateLList(ListPointer *List);
boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[NumberOfNodes]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[NumberOfNodes],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[NumberOfNodes], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[NumberOfNodes]);
void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

main()
{
    ListPointer AList, FreePtr, PredPtr;
    NodeType Node[NumberOfNodes+1];
    ListElementType AnItem;
    int choice, i;
    char ch;
    boolean found;

   InitializeStoragePool(Node, &FreePtr);
   printAll(AList, FreePtr, Node);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	  case 1: CreateLList(&AList);          //DHMIOYRGIA LISTAS
      	             break;
          case 2:	do
                    {
   	                    printf("FreePtr=%d\n",FreePtr);
                        printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
                        scanf("%d", &AnItem);
                        /*OTAN DIAGRAFW DIADOXIKA PANTA TO 1o STOIXEIO 8A PREPEI
                        NA EPANAFERW TH LISTA KENH  & ARXIKOPOIHMENH*/
                        if (AList==0 & FreePtr!=1) {
                            InitializeStoragePool(Node, &FreePtr);
                            CreateLList(&AList);
                        }
                        PredPtr=FreePtr-1;
                        if(!EmptyLList(AList))
                            Search(FreePtr, AList, Node, AnItem, &found, &PredPtr);
                        Insert(&AList, Node, &FreePtr, PredPtr, AnItem); //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
                        printf("AList=%d\n",AList);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &ch);
                        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                    } while (toupper(ch)!='N');
                    printAll(AList, FreePtr, Node);
                    break;
          case 3:	printf("FreePtr=%d\n",FreePtr);
                    TraverseLinked(AList, Node);      //DIASXISH LISTAS
         			break;
          case 4:   if (EmptyLList(AList))
      	                 printf("Empty List\n");
      	            else
      	            {
                        printAll(AList, FreePtr, Node);
                        printf("DWSE T0 STOIXEIO GIA DIAGRAFH: ");
                        scanf("%d", &AnItem);
                        Search(FreePtr, AList, Node, AnItem, &found, &PredPtr);
                        if(found)
                            Delete(&AList, Node, &FreePtr, PredPtr);  //DIAGRAFH STOIXEIOY 
                        else
                            printf("DEN YPARXEI AYTO TO STOIXEIO\n");
                        printAll(AList, FreePtr, Node);
                    }
         			break;
          case 5:   if (EmptyLList(AList))
      	                 printf("Empty List\n");
      	            else printf("Not an Empty List\n");
      	            break;
      	case 6:   if (FullLList(FreePtr))
      	                 printf("Full List\n");
      	            else printf("Not a Full List\n");
      	            break;
      	 case 7:	printAll(AList, FreePtr, Node);     //EMFANISH STORAGE POOL
         			break;
	  }
   } while (choice!=8);

	return 0;
}



void InitializeStoragePool(NodeType Node[NumberOfNodes], ListPointer *FreePtr)
{
   int i;

    for (i=1; i<NumberOfNodes;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes].Next=0;
    Node[NumberOfNodes].Data=0;
    *FreePtr=1;
}

void CreateLList(ListPointer *List)
{
  *List=NilValue;
}

boolean EmptyLList(ListPointer List)
{
  return (List==NilValue);
}

boolean FullLList(ListPointer FreePtr)
{
  return (FreePtr == 0);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[NumberOfNodes])
{
  *P = *FreePtr;
  if (*FreePtr!=0)
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr)
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1;
  
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[NumberOfNodes],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[NumberOfNodes], ListPointer *FreePtr, ListPointer PredPtr)
{
  ListPointer TempPtr ;

  if (!EmptyLList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[NumberOfNodes])
{
  ListPointer CurrPtr;

  if (!EmptyLList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d,%d,%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Check if List is full\n");
    printf("7. Print storage pool\n");
    printf("8. Telos\n");
    printf("\nChoice 1-8 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=1;i<=NumberOfNodes;i++)
        printf("(%d,%d,%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}

void Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, boolean *found, ListPointer *PredPtr)
{
    ListPointer CurrPtr;

    *found = FALSE;
    *PredPtr = NilValue;
    CurrPtr = List;

    while(!*found && (CurrPtr!=FreePtr))
    {
        if(Item<=Node[CurrPtr].Data)
        {
            if(Item==Node[CurrPtr].Data)
                *found = TRUE;
            else
                CurrPtr = FreePtr;
        }else{
            *PredPtr = CurrPtr;
            CurrPtr = Node[CurrPtr].Next;
        }
    }
}
