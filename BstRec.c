/* 
 * File:   BstRec.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType Item, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

void menu(int *choice);

main()
{
 
   int choice, ch;
   BinTreePointer ARoot, LocPtr;
   BinTreeElementType AnItem;
   boolean Found;

   CreateBST(&ARoot);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	do
            {
   	            printf("Enter a number for insertion in the Tree: "); 
                scanf("%d", &AnItem);
                RecBSTInsert(&ARoot, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2:	if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else 
                        RecBSTInorder(ARoot);
                    getch();
         			break;
         case 3:    if (BSTEmpty(ARoot))
                        printf("Empty tree\n");
                    else { 
                        printf("Enter a number for searching in the Tree: ");
                        scanf("%d", &AnItem);
                        RecBSTSearch(ARoot, AnItem, &Found, &LocPtr);
         			    if (Found==FALSE)
         			        printf("Item %d not in tree \n",AnItem);
         			    else 
         			        printf("Item %d is in tree \n",AnItem);
                    }
                    getch();
         			break;
        case 4:    if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else {
                        printf("Enter a number for deleting in the Tree: ");
                        scanf("%d", &AnItem);
                        RecBSTDelete(&ARoot, AnItem);
                    }
                    getch();
         			break;
        case 5:	if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else
                        RecBSTPreorder(ARoot);
                    getch();
         			break;
		case 6:	if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else
                        RecBSTPostorder(ARoot);
                    getch();
         			break;
		}
   } while (choice!=7);

	return 0;
}

void menu(int *choice)
{
    //clrscr();
    printf("\n                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Insert an element to Binary Tree\n");
    printf("2. Inoder traverse of Binary TreeA\n");
    printf("3. Search for a element in Binary Tree\n");
    printf("4. Delete an element of Binary Tree\n");
    printf("5. Preoder traverse of Binary TreeA\n");
    printf("6. Postoder traverse of Binary TreeA\n");
    printf("7. Telos\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void CreateBST(BinTreePointer *Root) {
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item) 
{
    if (BSTEmpty(*Root)) {
        (*Root) = malloc(sizeof (BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else    
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item); 
        else
            printf("To %d EINAI HDH STO DDA\n", Item);     
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType Item, boolean *Found, BinTreePointer *LocPtr)
{
    boolean stop;
    BinTreePointer TempLoc;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else 
        if (Item < Root->Data)
            RecBSTSearch(Root->LChild, Item, &(*Found), &(*LocPtr));
        else
            if (Item > Root->Data)
                RecBSTSearch(Root->RChild, Item, &(*Found), &(*LocPtr)); 
            else 
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType Item)
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO Item EINAI STOIXEIO TOY DDA *)

    if ((*Root) == NULL)          //* ADEIO DENDRO - TO Item DEN 8A BRE8EI *)
        printf("to %d DeN BRE8HKe STO DDA\n", Item);
     else
         //* ANADROMIKH ANAZHTHSH GIA TON KOMBO POY PERIEXEI TO Item KAI DIAGRAFH AYTOY 
          if (Item < (*Root)->Data)  
             RecBSTDelete(&((*Root)->LChild), Item);       //* ARISTERO YPODENDRO *)
          else 
            if (Item > (*Root)->Data) 
                  RecBSTDelete(&((*Root)->RChild), Item);   //* DEJI  YPODENDRO *)
            else                                       //* TO Item BRE8HKE DIAGRAFH TOY KOMBOY *)
                if ((*Root)->LChild ==NULL)   
                 {
                      TempPtr = (*Root)->RChild;      //* DEN EXEI ARISTERO PAIDI *)
                      free(Root);
                      *Root = TempPtr;
                 }
                else if ((*Root)->RChild == NULL) 
                   {
                        TempPtr = (*Root)->LChild;      //* EXEI ARISTERO PAIDI, ALLA OXI DEJI *)
                        free(Root);
                        *Root = TempPtr;
                   }
                   else                               //* EXEI 2 PAIDIA *)
                   {
                        //* EYReSH TOY inorder APOGONOY *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL) 
                              TempPtr = TempPtr->LChild;
                        /* METAKINHSH TOY APOGONOY THS RIZAS TOY YPODENDROY
                        POY EJETAZETAI KAI DIAGRAFH TOY APOGONOY KOMBOY */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("L");
        RecBSTInorder(Root->LChild);
        printf("/%d ",Root->Data,"/");
        printf("R");
        RecBSTInorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("/%d ",Root->Data,"/");
        printf("L");
        RecBSTPreorder(Root->LChild);
        printf("R");
        RecBSTPreorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("L");
        RecBSTPostorder(Root->LChild);
        printf("R");
        RecBSTPostorder(Root->RChild);
        printf("/%d ",Root->Data,"/");        
    }
    printf("U");
}




