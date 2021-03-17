//                    (* YPOLOGISMOS RPN EKFRASEWN *)
// filename EvalRPN;

//filename: EvalRPN.c

#include <stdio.h>
#include <stdlib.h>
#include "StFloatADT.h"

float telestis(char token, float Operand1, float Operand2);

main()
{
  StackType AStack;
  StackElementType AnItem;  
  float result,operand1,operand2;
  char token, answer, expression[256];
  int i;

  do
  {
    fflush(stdin);
    CreateStack(&AStack); 
    expression[0]='\0';
    i=0;
    printf("DWSE TH META8EMATIKH EKFRASH\n");   
    printf("META TON TELEYTAIO XARAKTHRA THS EKFRASHS PLHKTROGHSTE enter.\n");

    while ((token=getchar())!='\n')
    {
        expression[i]=token;
        i++;
        if (token!=' ') 
            if (token>='0' && token<='9')
            {
                result=(float)(token-'0');
                Push(&AStack,result);
            }
            else
            {
                Pop(&AStack,&operand2);
                Pop(&AStack,&operand1);
                result=telestis(token,operand1,operand2);
                Push(&AStack, result); 
             }
    }
    expression[i]='\0';
    Pop(&AStack,&result);
    printf("expression= %s\n",expression);
    printf("%5.2f\n",result);
    printf("Continue? (Y/N) ");
    scanf("%c",&answer);
    } while (answer=='Y' || answer=='y');
    system("PAUSE");
}

float telestis(char token, float Operand1, float Operand2)
{
    switch(token)
    {
        case '+' : return (Operand1+Operand2);
                    break;
        case '-' : return (Operand1-Operand2);
                    break;  
        case '*' : return (Operand1*Operand2);
                    break;          
        case '/' : return (Operand1/Operand2);
                    break; 
        default  : printf("Not a valid operator\n");
                    break;
    }                                    
}
