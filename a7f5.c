/*             ASKISI 7
*             FYLLADIO 5
*    STYLIANOS KARAKOSTAS it12146
*/

#include<stdio.h>
#include<stdlib.h>

typedef char BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};


 typedef enum
 {
     FALSE,TRUE
 }boolean;


void CreateBST(BinTreePointer *Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
BinTreeElementType maxBSTValue(BinTreePointer Root);
BinTreeElementType minBSTValue(BinTreePointer Root);


main()
{
    BinTreeElementType max,min;
    BinTreePointer ARoot;
    CreateBST(&ARoot);

    BSTInsert(&ARoot,'P');
    BSTInsert(&ARoot,'R');
    BSTInsert(&ARoot,'O');
    BSTInsert(&ARoot,'C');
    BSTInsert(&ARoot,'E');
    BSTInsert(&ARoot,'D');
    BSTInsert(&ARoot,'U');
    BSTInsert(&ARoot,'R');
    BSTInsert(&ARoot,'E');


    if(ARoot!=NULL)
    {
        max=maxBSTValue(ARoot);
        min=minBSTValue(ARoot);
    }

    printf("The max in this binary tree is: %c \n",max);
    printf("The min in this binary tree is: %c \n",min);


system("Pause");
return 0;
}


void CreateBST(BinTreePointer *Root)
{
   *Root=NULL;
}


void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;
    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL)
    {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("The %c already exists in DDA\n", Item);
    else
    {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}


BinTreeElementType maxBSTValue(BinTreePointer Root)
{
   BinTreePointer current;
   current=Root;
   while(current->RChild!=NULL)
   {
       current=current->RChild;
   }
   return (current->Data);
}


BinTreeElementType minBSTValue(BinTreePointer Root)
{
   BinTreePointer current;
   current=Root;
   while(current->LChild!=NULL)
   {
       current=current->LChild;
   }
   return (current->Data);
}


