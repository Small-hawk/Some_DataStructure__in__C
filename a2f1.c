/*             ASKISI 2
*             FYLLADIO 1
*    STYLIANOS KARAKOSTAS it12146
*/


#include <stdio.h>
#include <stdlib.h>
#define max_size 127

typedef int stoixeio_synolou;

  typedef enum {
     FALSE, TRUE
     } boolean;

typedef boolean typos_synolou[max_size];



void Dimiourgia(typos_synolou synolo);

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isValidInteger (char Data[100],boolean Character[127],boolean Digit[127]);

boolean isValidIdentifier(char Data[100],boolean Letter[127]);


int main()
{

   boolean CharacterSet[127];

   boolean DigitSet[127];

   boolean Letterset[127];

   char Data[100];

   int i;

   char answer1[2];

   char answer2[2];


         Dimiourgia(CharacterSet);
         Dimiourgia(DigitSet);
         Dimiourgia(Letterset);
         Eisagogi(43,CharacterSet);
         Eisagogi(45,CharacterSet);

         for(i=48;i<=57;i++)
         {
             Eisagogi(i,DigitSet);
         }

         for(i=65;i<=90;i++)
         {
             Eisagogi(i,Letterset);
         }

         for(i=97;i<=122;i++)
         {
            Eisagogi(i,Letterset);
         }

         Eisagogi(95,Letterset);



     answer1[0]='Y';

       while(answer1[0]=='Y' || answer1[0]=='y')
        {
            printf("Give an Integer: ");
              gets(Data);

            if (isValidInteger(Data,CharacterSet,DigitSet)==TRUE)
               printf("Valid Integer \n");

            else
               printf("Not valid Integer\n");


            printf("Do you want to continue; For Yes press 'Y', for No press 'N': ");
              gets(answer1);
        }

     answer2[0]='Y';

       while( answer2[0]=='Y' || answer2[0]=='y')
        {
            printf("Give an Identifier: ");
              gets(Data);

            if (isValidIdentifier(Data,Letterset)==TRUE)
               printf("Valid Identifier \n");

            else
               printf("Not valid Identifier \n");

            printf("Do you want to continue; For Yes press 'Y', for No press 'N': ");
              gets(answer2);
        }


   system("PAUSE");
   return 0;
}


void Dimiourgia(typos_synolou synolo)
{
     stoixeio_synolou i;

        for (i = 1; i <= max_size; i++)
        {
            synolo[i] = FALSE;
        }

}


void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
     synolo[stoixeio] = TRUE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
  return synolo[stoixeio];
}


boolean isValidInteger (char Data[100],boolean Letterset[127],boolean Digit[127])
{
     boolean result;
     result=FALSE;
     int i;
     for(i=1;i<100;i++)
      {
          if(Melos(Data[0],Letterset) || Melos(Data[i],Digit))
            result=TRUE;
      }

  return result;
}


boolean isValidIdentifier(char Data[100],boolean Letter[127])
{
    boolean result;
    result=FALSE;
    int i;

      for(i=1;i<100;i++)
       {
           if (Melos(Data[0],Letter)&& Data[i]!=' ')
            result=TRUE;
       }


  return result;
}
