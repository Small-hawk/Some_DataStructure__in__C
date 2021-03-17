/*             ASKISI 8
*             FYLLADIO 2
*    STYLIANOS KARAKOSTAS it12146
*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 50


typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

main(){

int Stackarray[256];
int pointC=0,correct=0, Number=0,Remainder,i;
StackType StackOfRemainders;
int Response, item;

  CreateStack(&StackOfRemainders);

    printf(" Enter string: \n ");

    while (item!=13)
        {
            item=getch();
            if(item!=13)
                {
                    Number=Number+1;
                    Stackarray[Number]=item;
                    putch(Stackarray[Number]);
                    printf(" \n ");
                }
        }

    for(i=1;i<=Number;i++)
        {
            if(Stackarray[i]=='C')
             {pointC=i;}
        }


    for(i=1;i<pointC;i++)
        {
            Push(&StackOfRemainders,Stackarray[i]);
        }


        /* ELEGXOS */


    for (i=(pointC+1);i<=Number;i++)
        {
            Pop(&StackOfRemainders,&Response);
            item=Stackarray[i];
            if(Response==item)
                {correct=correct+1;}
        }

    if (correct==((Number-1)/2))
        {
            printf("\n TRUE \n");
        }
    else
        {
            printf("\n FALSE \n");
        }


system("Pause");
return 0;

}



void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}



void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack))
        {
            Stack -> Top++;
            Stack -> Element[Stack -> Top] = Item;
        }
        else
            printf("Full Stack...");
}


boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}


void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack))
    {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    }
    else
        printf("Empty Stack...");
}


boolean FullStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}
