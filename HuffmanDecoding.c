//                  (*APOKWDIKOPOIHSH KWDIKWN Huffman*)

// filename : HuffmanDecoding;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char BinTreeElementType;        /*����� ��������� ��� ������������� �����
                                            ������� ��� ������� Huffman */
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
/* �������: ��� ��������� ch, ��� string code, ��� ������� codelen (����� ���
            string code) ��� �� ������ Root ��� ������� �� ���� ��� ������� Huffman
  ����������: ���������� ���� ����� �� ����������� �� ��������� ch
                ��� ������ � ������� ����� code ������ codelen ��� ��� 
                ��������� ��� ������ Huffman
  ����������: �� ������������� ������ Huffman, ��� �������������� ��� �� ������ Root
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
/* �������:    �� ������ CodeFile
   ����������: �������� ���� ���������� ��� ���� �������� ���� ��� �� ������
                CodeFile ��� ������������ �� ������ Huffman.
   ����������: �� ������ Root ��� ������� ��� ���� ��� ������� Huffman.
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
/* �������: ��� ������ Huffman ��� ��� ��������� ��� bits ��� ���������� ��� ������, 
            �� ����� ���� ������������ �� ����� ��� ������� Huffman. 
  ����������:  �������������� �� ������. 
  ����������: �� ����������������� ������.*) 
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
/* ��������� ��� ������ HUFF.TXT �� ������ Huffman
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

