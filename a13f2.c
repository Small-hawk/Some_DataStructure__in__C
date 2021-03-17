/*             ASKISI 13
*             FYLLADIO  2
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 100


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
void TraverseStack(StackType Stack);




main()
{

int num1,num2,oper, i, item;
StackType NumberStack;
StackType OperationStack;

  CreateStack(&NumberStack);
  CreateStack(&OperationStack);

  while(item!=113)
    {
        printf("\nDiathesimes leitourgies: \n");
        printf("+,-,*,/,c (Clear), s (show results), q (quit),u (undo)\n");
        printf("Operation:");

        item=getch();


        if(item==43) /* prosthesi */
            {
                if(EmptyStack(NumberStack))
                 {
                     printf("\nNumber1: ");
                     scanf("%d", &num1);
                     Push(&NumberStack,num1);
                 }
                 else
                 {
                     Pop(&NumberStack,&i);
                     num1=i;
                     Push(&NumberStack,i);
                 }

                 printf("\nNumber2: ");
                 scanf("%d", &num2 );
                 Push(&NumberStack,num2);
                 Push(&NumberStack,(num1+num2));
                 Push(&OperationStack,item);
            }

        if(item==45) /* afairesi */
            {
                if(EmptyStack(NumberStack))
                 {
                     printf("\nNumber1: ");
                     scanf("%d", &num1);
                     Push(&NumberStack,num1);
                 }
                 else
                 {
                     Pop(&NumberStack,&i);
                     num1=i;
                     Push(&NumberStack,i);
                 }

                 printf("\nNumber2: ");
                 scanf("%d", &num2 );
                 Push(&NumberStack,num2);
                 Push(&NumberStack,(num1-num2));
                 Push(&OperationStack,item);
            }

        if(item==42) /* pollaplasiasmos */
            {
                if(EmptyStack(NumberStack))
                 {
                     printf("\nNumber1: ");
                     scanf("%d", &num1);
                     Push(&NumberStack,num1);
                 }
                 else
                 {
                     Pop(&NumberStack,&i);
                     num1=i;
                     Push(&NumberStack,i);
                 }

                 printf("\nNumber2: ");
                 scanf("%d", &num2 );
                 Push(&NumberStack,num2);
                 Push(&NumberStack,(num1*num2));
                 Push(&OperationStack,item);
            }

        if(item==47) /* diairesi */
            {
                if(EmptyStack(NumberStack))
                 {
                     printf("\nNumber1: ");
                     scanf("%d", &num1);
                     Push(&NumberStack,num1);
                 }
                 else
                 {
                     Pop(&NumberStack,&i);
                     num1=i;
                     Push(&NumberStack,i);
                 }

                 printf("\nNumber2: ");
                 scanf("%d", &num2 );
                 Push(&NumberStack,num2);
                 Push(&NumberStack,(num1/num2));
                 Push(&OperationStack,item);
            }


        if(item==99) /* clear */
            {
                while(!EmptyStack(NumberStack))
                  {
                      Pop(&NumberStack,&i);
                  }
                while(!EmptyStack(OperationStack))
                    {
                        Pop(&OperationStack,&i);
                    }
                printf("\nClear complete\n");
            }


        if(item==115) /* show results */
            {
                if(!EmptyStack(NumberStack))
                    {
                        Pop(&NumberStack,&i);
                        printf("\nResult: %d",i);
                        Push(&NumberStack,i);
                    }

                if(!EmptyStack(OperationStack))
                    {
                        Pop(&OperationStack,&oper);
                        printf(" (last operation: '%c' )\n",oper);
                        Push(&OperationStack,oper);
                    }
            }

         if(item==117) /* undo */
            {
                num1=0;num2=0;oper=32;
                if(!EmptyStack(NumberStack))
                    {
                       Pop(&NumberStack,&num1);
                    }
                if(!EmptyStack(NumberStack))
                    {
                        Pop(&NumberStack,&num2);
                    }
                if(!EmptyStack(NumberStack))
                    {
                        Pop(&OperationStack,&oper);
                    }
                if((num1==0)&&(num2==0)&&(oper==32))
                    {
                        printf("\nDen uparxei kati allo na anairethei\n");
                    }
                else
                    {
                        printf("\nMolis anerethikan oi arithmoi ");
                        printf("%d kai %d me tin praksi %c",num1,num2,oper);
                    }

             }


    }
  printf("\n");
  TraverseStack(NumberStack);
  TraverseStack(OperationStack);


system("Pause");
return 0;
}



void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}


void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}


boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}


void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}


void TraverseStack(StackType Stack)
{
    int i;
    printf("\nArithmos stoixeiwn stin stoiva %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}







