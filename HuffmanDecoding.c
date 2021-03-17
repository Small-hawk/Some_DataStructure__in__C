//                  (*APOKWDIKOPOIHSH KWDIKWN Huffman*)

// filename : HuffmanDecoding;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char BinTreeElementType;        /*тупос дедолемым поу апохгйеуомтаи стоуР
                                            йолбоус тоу демдяоу Huffman */
typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void AddToTree(char ch, char code[10], int codelen, BinTreePointer *Root);
void BuildDecodingTree(BinTreePointer *Root,   FILE  *CodeFile);
void Decode(BinTreePointer Root, FILE* MessageFile);
void PrintTree(FILE *t, BinTreePointer Root, int indent);

main()
{
    FILE *t, *CodeFile, *MessageFile;
    BinTreePointer Root;

    BuildDecodingTree(&Root, CodeFile);
    t = fopen("HUFF.TXT", "w+");
    if (t == NULL)
        printf("Can't open HUFF.TXT\n");
    else
    {
        PrintTree(t, Root, 8);
        Decode(Root, MessageFile);
    }
    system("PAUSE");
}

void AddToTree(char ch, char code[10], int codelen, BinTreePointer *Root)
/* деветаи: ема ваяайтгяа ch, ема string code, ема айеяаио codelen (лгйос тоу
            string code) йаи то деийтг Root поу деивмеи тг яифа тоу демдяоу Huffman
  кеитоуяциа: дглиоуяцеи емам йолбо ле пеяиеволемо то ваяайтгяа ch
                тоу опоиоу о йыдийос еимаи code лгйоус codelen йаи том 
                пяосхетеи сто демдяо Huffman
  епистяежеи: то тяопопоиглемо демдяо Huffman, поу деийтодотеитаи апо то деийтг Root
*/
{
  int i;
  BinTreePointer TempPtr,p;
  i =0;
  p =*Root;
  while (i<codelen)

    if (code[i]=='0')
    {
        if (p->LChild==NULL)
        {
            TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
            TempPtr->Data='*';
            TempPtr->LChild=NULL;
            TempPtr->RChild=NULL;
            p->LChild=TempPtr;
        }
        i=i+1;
        p=p->LChild;
    }
    else
      if (code[i]='1')
      {
          if (p->RChild==NULL)
          {
              TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
              TempPtr->Data='*';
              TempPtr->LChild=NULL;
              TempPtr->RChild=NULL;
              p->RChild=TempPtr;
          }
          i=i+1;
          p=p->RChild;
      }
      p->Data=ch;
}
    

void BuildDecodingTree(BinTreePointer *Root, FILE  *CodeFile)
/* деветаи:    то аявеио CodeFile
   кеитоуяцха: диабафеи тоус ваяайтгяес йаи тоус йыдийоус тоус апо то аявеио
                CodeFile йаи йатасйеуафеи то демдяо Huffman.
   епистяежеи: то деийтг Root поу деивмеи стг яифа тоу демдяоу Huffman.
*/
{
  char  ch,termch, blank;
  char code[80];
    int nscan;

    
    (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
    (*Root)->Data='*';
    (*Root)->LChild=NULL;
    (*Root)->RChild=NULL;
    CodeFile = fopen("CODES.TXT", "r");
    if (CodeFile == NULL) 
        printf("Can't open CODES.TXT\n");
    else 
    {
            while (TRUE) 
            { "%15[^,], %2[^,], %d, %lf%c",
                nscan = fscanf(CodeFile, "%c %10[^\n]%c",&ch, code,&termch);
                if (nscan == EOF) break;
                if (nscan != 3 || termch != '\n') 
                {
                    printf("Improper file format\n");
                    break;
                }
                else  
                    AddToTree(ch, code, strlen(code), &(*Root));
            }
    }
}

void Decode(BinTreePointer Root, FILE* MessageFile)
/* дщВЕТАИ: ╦МА ДщМТЯО Huffman ЙАИ ЛИА АЙОКОУХъА АПЭ bits ПОУ АМАПАЯИСТэ щМА ЛчМУЛА, 
            ТО ОПОъО щВЕИ ЙЫДИЙОПОГХЕъ ЛЕ ВЯчСГ ТОУ ДщМТЯОУ Huffman. 
  кЕИТОУЯЦъА:  аПОЙЫДИЙОПОИЕъ ТО ЛчМУЛА. 
  еПИСТЯщЖЕИ: тО АПОЙЫДИЙОПОИГЛщМО ЛчМУЛА.*) 
*/
{
  char bit;
  BinTreePointer p;

    MessageFile = fopen("MESSAGES.TXT", "r");
    if (MessageFile == NULL)
        printf("Can't open MESSAGES.TXT\n");
    else
    {
        while (bit != EOF)
        {
            p=Root;
            while (p->LChild!=NULL || p->RChild!=NULL)  
            {
                bit=fgetc(MessageFile);
                if (bit != EOF) 
                {
                    printf("%c",bit);
                    if (bit=='0') 
                        p=p->LChild;
                    else
                        if (bit=='1') 
                            p=p->RChild;
                        else
                            if (bit!='\n')
                                printf("MH APODEKTO bit: \n", bit); 
                }
                else break;           
            }
             if (bit != EOF) printf("---%c\n",p->Data);
        }
    }
}

void PrintTree(FILE *t, BinTreePointer Root, int indent)
/* сведиафеи сто аявеио HUFF.TXT то демдяо Huffman
*/
{
  int i;
  if (Root!=NULL) 
  {
      PrintTree(t, Root->RChild, indent+8);
      for (i=1;i<=indent;i++) fprintf(t," ");
      fprintf(t,"%c\n", Root->Data);
      PrintTree(t, Root->LChild, indent+8);
  }
}

