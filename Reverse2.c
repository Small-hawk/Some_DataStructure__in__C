// Filename Reverse2
/*           ���������� ��� ���������� �������� �� ����� ������������ ������
                   ��������� �������̸��� ˺���� ��������, �� �������
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LPChADT.h"

#define  EndMark '$'

main()
{
    ListPointer AList, PredPtr;
    ListElementType AnItem;

  CreateList(&AList);
  PredPtr=NULL;
  printf("PLHKTROLOGHSE $ STO TELOS TOY KEIMENOY.\n");
  AnItem=getchar();
  while (AnItem!=EndMark) 
  {
      LinkedInsert(&AList,AnItem,PredPtr);
      AnItem=getchar();
  }

  printf("TO ANASTROFO KEIMENO EINAI \n");
  LinkedTraverse(AList);
  printf("\n");
  system("PAUSE");
}
