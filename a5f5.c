// File name: a5f5.c

#include <stdio.h>
#include <stdlib.h>

typedef char BinTreeElementType;       

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTLevel(BinTreePointer Root, BinTreeElementType Item, int Level);

main()
{
    BinTreePointer ARoot;
    int Level;
    
    CreateBST(&ARoot);
    BSTInsert(&ARoot, 'P');
    BSTInsert(&ARoot, 'R');
    BSTInsert(&ARoot, 'O');
    BSTInsert(&ARoot, 'C');
    BSTInsert(&ARoot, 'E');
    BSTInsert(&ARoot, 'D');
    BSTInsert(&ARoot, 'U');
    BSTInsert(&ARoot, 'R');
    BSTInsert(&ARoot, 'E');
    
    BSTLevel(ARoot, 'P', Level);
    BSTLevel(ARoot, 'O', Level);
    BSTLevel(ARoot, 'C', Level);
    BSTLevel(ARoot, 'E', Level);
    BSTLevel(ARoot, 'D', Level);
    
    system("PAUSE");
}

void BSTLevel(BinTreePointer Root, BinTreeElementType Item, int Level)
{
    BinTreePointer LocPtr;
    boolean Found;
    
    LocPtr = Root;
    Found = FALSE;
    Level = 1;
    
    while (!Found && LocPtr != NULL)
    {
        if (Item < (LocPtr)->Data)
        {
            (LocPtr) = (LocPtr)->LChild;
             Level++;
        }else if (Item > (LocPtr)->Data){
                (LocPtr) = (LocPtr)->RChild;
                 Level++;
        }else 
            Found = TRUE;
    }
    if(!Found)
       Level = -1;
       
    printf("Level of %c: ",Item);
    printf("%d\n",Level);
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
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
        printf("To %c EINAI HDH STO DDA\n", Item);
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
