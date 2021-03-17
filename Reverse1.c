// Filename Reverse1
/*           амтистяожг тым ваяайтгяым йеилемоу ле вягсг сулдеделемгс кистас
                   укопоигсг сумдедел╦мгс к╨стас ле пимайа 
*/

#include <stdio.h>
#include "L_ListChADT.h"

#define  EndMark '$'

main()
{
  ListPointer AList;
    NodeType Node[NumberOfNodes+1];
    ListPointer FreePtr,PredPtr;

    ListElementType AnItem;


  InitializeStoragePool(Node, &FreePtr);
  CreateLList(&AList);
  PredPtr=NilValue;
  printf("PLHKTROLOGHSE $ STO TELOS TOY KEIMENOY.\n");
  AnItem=getchar();
  while (AnItem!=EndMark) 
  {
      Insert(&AList, Node,&FreePtr, PredPtr, AnItem);
      AnItem=getchar();
  }
// H MONH ALLAGH STO L_ListChADT.c EINAI STHN TraverseLinked STHN printf %c SE SXESH ME THN L_ListADT.c !!!
  printf("TO ANASTROFO KEIMENO EINAI \n");
  TraverseLinked(AList,Node);
  printf("\n");
  system("PAUSE");
}
