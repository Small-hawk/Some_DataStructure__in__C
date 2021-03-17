//filename : HashList.c

#include <stdio.h>
#include "HashList.h"

void HashKey(int Key,int *HValue)
/* Δέχεται:    Την τιμή Key ενός κλειδιού. 
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key. 
   Επιστρέφει: Την τιμή κατακερματισμού HValue 
*/
{
	*HValue=Key%HMax + 1;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList. 
   Επιστρέφει: Την δομή HList 
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=1;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ
	
    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ 
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
    index=1;
	while (index<=HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }
    
     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList
    index=1;
	while(index < VMax)
	{
		HList->List[index].Link=index+1;
		HList->List[index].Data=0;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
	
	for (index=1;index<=HMax;index++)
	   printf("%d, %d, \n",index,HList->HashTable[index]);
	
	for (index=1;index<=VMax;index++)
	   printf("%d, %d, \n",index,HList->List[index].Link);
}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList. 
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη. 
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά. 
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg. 
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων. 
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης 
                εγγραφής στην υπολίστα 
*/
{
	int Next;
	Next=HList.SubListPtr;
	int L1, P1;
	*Loc=0;
	*Pred=0;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;	
		}
	}
}
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg. 
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList. 
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της 
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει. 
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=0 
*/
{
	int HVal;
	HashKey(KeyArg,&HVal);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=0;
		*Loc=0;
	}
	else 
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec. 
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη, 
                και ενημερώνει τη δομή HList. 
   Επιστρέφει: Την τροποποιημένη δομή HList. 
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά, 
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί, 
                εμφάνιση αντίστοιχου μηνύματος 
*/
{
	int Loc, Pred, New, HVal;
    
    New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=0;
		Pred=0;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==0) 
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==0)
			{
			    HashKey(InRec.RecKey,&HVal);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else 
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else 
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,int DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=0)
	{
		if(Pred!=0)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HashKey(DelKey,&HVal);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}

