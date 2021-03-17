/*             ASKISI 11
*             FYLLADIO 5
*    STYLIANOS KARAKOSTAS it12146
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define s 16

typedef char BinTreeElementType[s];

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum
{ FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
void CreateDictionary(BinTreePointer *Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void SpellingCheck(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);


main()
{

    BinTreePointer Root;
    CreateBST(&Root);
    CreateDictionary(&Root);
    SpellingCheck(&Root);



system("pause");
return 0;
}



void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}


void CreateDictionary(BinTreePointer *Root)
{
    FILE *fp;
    char word[s];

    fp = fopen("I112F5.TXT","r");
    if(fp == NULL)
        printf("Can't open %s\n", "I112F5.TXT");
    else
    {
        while(TRUE)
        {
            if(fgets(word, s, fp) == NULL)
                break;
            BSTInsert(Root, word);
        }
    }

    fclose(fp);
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
        if (strcmp(Item,LocPtr->Data)==-1)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item,LocPtr->Data)==1)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("The %c already exists in DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent->Data)==-1)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue,(*LocPtr)->Data)==-1)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue,(*LocPtr)->Data)==1)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}


void SpellingCheck(BinTreePointer *Root)
{
    FILE *fp;
    BinTreePointer LocPtr;
    char word[s];
    boolean found;

    fp = fopen("I111F5.TXT", "r");

    if(fp == NULL)
        printf("Can't open %s\n", "I111F5.TXT");
    else
    {
        while(TRUE)
        {
            if(fgets(word, s, fp) == NULL)
                break;
            BSTSearch(*Root,word, &found, &LocPtr);
            if(found == FALSE)
                printf("%s\n\n", word);

        }
    }

    fclose(fp);
}


boolean EmptyBST(BinTreePointer Root)
{
    return (Root == NULL);
}
