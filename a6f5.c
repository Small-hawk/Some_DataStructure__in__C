/*             ASKISI 6
*             FYLLADIO 5
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
int BSTDepth(BinTreePointer *root);

int main()
{
    BinTreePointer root;
    BinTreeElementType depth;



    CreateBST(&root);
    BSTInsert(&root,'P');
    BSTInsert(&root,'R');
    BSTInsert(&root,'O');
    BSTInsert(&root,'C');
    BSTInsert(&root,'E');
    BSTInsert(&root,'D');
    BSTInsert(&root,'U');
    BSTInsert(&root,'R');
    BSTInsert(&root,'E');

    depth = BSTDepth(&root);
    printf("Depth:%d \n", depth);


system("Pause");
return 0;

}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("The %c exists in DDA\n", Item);
    else {
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

 int BSTDepth(BinTreePointer *Root)
 {
     int LDepth, RDepth;


     if(*Root==NULL)
     {
         return 0;
     }
     else
     {
         LDepth = BSTDepth(&(*Root)->LChild);
         RDepth = BSTDepth(&((*Root)->RChild));

         if(LDepth > RDepth)
          return LDepth + 1;
         else
          return RDepth + 1;
     }


 }

