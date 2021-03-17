#include <stdio.h>
#include <stdlib.h>


#define StackLimit 20  // �� ���� �������� ��� �������, ���������� ��� �� 50


typedef int StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
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
void TraverseStack(StackType *Stack);

main()
{
    int i;
    StackType Stack1, Stack2, Stack3;
    StackElementType Item;

    CreateStack(&Stack1);
    Push(&Stack1,'P');
    Push(&Stack1,'A');
    Push(&Stack1,'S');
    Push(&Stack1,'C');
    Push(&Stack1,'A');
    Push(&Stack1,'L');
    printf("Stack1\n");
    TraverseStack(&Stack1);


    CreateStack(&Stack2);
    for(i=0;i<i<=Stack1.Top;i++)
    {
       Pop(&Stack1,&Item);
       Push(&Stack2,Item);
    }
    printf("Stack2\n");
    TraverseStack(&Stack2);

    CreateStack(&Stack3);
    for(i=0;i<i<=Stack2.Top;i++)
    {
       Pop(&Stack2,&Item);
       Push(&Stack3,Item);
    }
    printf("Stack3\n");
    TraverseStack(&Stack3);

    for(i=0;i<i<=Stack3.Top;i++)
    {
       Pop(&Stack3,&Item);
       Push(&Stack1,Item);
    }
    printf("Stack1\n");
    TraverseStack(&Stack1);

    system("PAUSE");
}


void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType *Stack)
{
    int i;

    printf("\nplithos sto stack %d\n",(*Stack).Top+1);
    for(i=0;i<(*Stack).Top+1;i++)
       printf("%c, ",(*Stack).Element[i]);
    printf("\n");
    printf("\n");
}
