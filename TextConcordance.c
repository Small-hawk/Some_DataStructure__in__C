// filename TestStack.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LPWordADT.h"

#define number 26    //������ ��������� �������� ���������

void GetAWord(FILE* TextFile, ListElementType Word, boolean *MoreWords);

main()
{
    int i;
    ListPointer AList[number], PredPtr;
    int choice;
    char Ch;
    ListElementType Word;
    boolean Found, MoreWords;
    FILE* TextFile;

    TextFile = fopen("ATEXT.TXT", "r");
    if (TextFile == NULL)
    printf("Can't open the file ATEXT.TXT\n");
    else 
    {
         for (Ch='A';Ch<='Z';Ch++) 
         {
                i=Ch-65;
            CreateList(&AList[i]);
         }

         for (Ch='A';Ch<='Z';Ch++) 
         {
            i=Ch-65;
            printf("%d List\n",i);
            LinkedTraverse(AList[i]);
         }
         GetAWord(TextFile, Word,  &MoreWords);;
         while (MoreWords) 
         {
            OrderedLimearSearch(AList[Word[0]-65], Word, &PredPtr, &Found);
            if (!Found)
                LinkedInsert(&AList[Word[0]-65], Word, PredPtr);
            GetAWord(TextFile,Word,&MoreWords);
         }

            for (Ch='A';Ch<='Z';Ch++) 
            {
                i=Ch-65;
                if (!EmptyList(AList[i]))
                {
                    printf("LEJEIS POY ARXIZOYN APO %c : ",Ch);
                    LinkedTraverse(AList[i]);
                } 
            }       
    }	
	system("PAUSE");
    return 0;
}

void GetAWord(FILE* TextFile, ListElementType Word, boolean *MoreWords)
/* �������:    ��� ������ TextFile.
   ����������: ��������� ��� ������� ���� Word ��� ������ TextFile.
   ����������: ��� ����  Word (string) ��� ���  MoreWords, ��� ����� TRUE �� 
                �������� ��� ����� ������ ��� ������ ��� FALSE �� ��� �������� �����
*/
{
  int i;
  char Ch;
  boolean more;

  more=FALSE; /*���������, ��� �� �� ���������� �� ������, ���� ��� ������
               *MoreWords */
  //��������� �� 1� ��������� ���� �����
  while ((!more) && (!feof(TextFile)))
  {
      Ch=fgetc(TextFile);
      Ch=toupper(Ch);
      if (Ch>='A' && Ch<='Z') more=TRUE;
  }
  /* �� ����� ���� ���������� �� 1� ��������� ��� string Word ��� ���� ��������� 
    ����� �� ��������� \0 */
   if (more)
   {        
      Word[0]=Ch;
      for (i=1; i<MaxWord;i++) 
        Word[i]='\0';
      i=0;

      if (!feof(TextFile)) 
      {
          Ch=getc(TextFile);
          Ch=toupper(Ch);
      }
      /*�������� ���� ���������� ���������� ��� ����� ��� �� ������ ��� ��� 
      ���������� ��� string Word*/
      while ((Ch>='A' && Ch<='Z') && (!feof(TextFile)))
      {
          i=i+1;
          Word[i]=Ch;
          Ch=getc(TextFile);
          Ch=toupper(Ch);
      }
    }    
   *MoreWords=more; 
}

