/* 
 *
 * Created on 20 Φεβρουάριος 2012, 10:39 μμ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// * Filename: setADT.h

#define megisto_plithos 255          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos+1];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

// ----- EOF: setADT.h -------

typos_synolou CharacterSet, DigitSet, LetterSet;

int main(void) {
    
    boolean isValidInteger();
    boolean isValidIdentifier();
    char str[255];
    char choice;   
    
    //Dimiourgia twn synolwn
    Dimiourgia(CharacterSet);
    Dimiourgia(DigitSet);
    Dimiourgia(LetterSet);
    
    //Eisagwgi stoixeiwn sto CharacterSet
    Eisagogi(43, CharacterSet);
    Eisagogi(45, CharacterSet);
    //Eisagwgi stoixeiwn sto DigitSet
    stoixeio_synolou i;
    for (i=48; i<=57; i++) {
        Eisagogi(i, DigitSet);
    }
    //Eisagwgi stoixeiwn sto LetterSet
    for (i=65;i<=90;i++) {
        Eisagogi(i, LetterSet);
    }
    for (i=97;i<=122;i++) {
        Eisagogi(i, LetterSet);
    }    
   
    //Eisodos Alpharithmitikou
    printf("Alfari8mitiko: ");
    getchar();
    scanf("%s",str);
    printf("\n");
    
    //Eksodos Apotelesmatos
    if (isValidInteger(str))
        printf("Valid integer.\n");
    else
        printf("Not a valid integer.\n");
    
    if (isValidIdentifier(str))
        printf("Valid identifier.\n");
    else
        printf("Not a valid identifier.\n");
    
    printf("\n");

    
    printf("Synexeia (Y/N): ");
    getchar();
    scanf("%c",&choice);

    while (toupper(choice) == 'Y') {
        printf("-----------------\n");
        printf("Alfari8mitiko: ");
        getchar();
        scanf("%s",str);
    
        printf("\n");
    
        if (isValidInteger(str))
             printf("Valid integer.\n");
        else
             printf("Not a valid integer.\n");
    
        if (isValidIdentifier(str))
             printf("Valid identifier.\n");
        else
             printf("Not a valid identifier.\n");
    
        printf("\n");
        printf("Synexeia (Y/N): ");
        getchar();
        scanf("%c",&choice);
        
    }
    return 0;
}

boolean isValidInteger(char str[255])
{
    int l;
    l = strlen(str);
    int temp;
    temp = str[0];
    if (Melos(temp,CharacterSet) == FALSE) {
        int i;
        for (i=0;i<=l-1;i++) {
            temp = str[i];
            if(Melos(temp, DigitSet) == FALSE)
                return FALSE;
        }
    }else{
        int i;
        for (i=1;i<=l-1;i++) {
            temp = str[i];
            if(Melos(temp, DigitSet) == FALSE)
            return FALSE;
        }
    }
    return TRUE;
}


boolean isValidIdentifier(char str[255])
{
    int l = strlen(str);
    int temp;
    temp = str[0];
    if (Melos(temp,LetterSet) == FALSE) 
        return FALSE;
    int i;
    for (i=1;i<=l-1;i++) {
        temp = str[i];
        if (Melos(temp, LetterSet) == FALSE) {
                if (Melos(temp, DigitSet) == FALSE){
                    if (str[i]!='_'){
                        return FALSE;
                    }
                }
        }
    }
    return TRUE;
}

// * Filename: setADT.c

void Dimiourgia(typos_synolou synolo) 
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο. 
   Επιστρέφει: Το κενό σύνολο 
*/
{
    stoixeio_synolou i;

    for (i = 1; i <= megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo) 
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο. 
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο. 
   Επιστρέφει: Το τροποποιημένο σύνολο 
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo) 
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο. 
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου. 
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά 
*/
{
    return synolo[stoixeio];
}
// ----- EOF: setADT.c -------