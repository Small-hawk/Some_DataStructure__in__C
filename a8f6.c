// a8f6.c

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define HMax 5          
#define VMax 30             
#define EndOfList -1       
                               
typedef int ListElementType; 
                           

typedef struct {
	int RecKey;
	ListElementType Data;
	char Name[20];
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax+1];   
    int Size;          
	int SubListPtr;          
    int StackPtr;           
	ListElm List[VMax+1];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
void HashKey(int Key,int *HValue);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,int DelKey);
void Print_HashList(HashListType HList);
void menu(int *choice);
void PrintPinakes(HashListType HList);

main(){
    
    int choice, ch;
    HashListType HList;
    ListElm AnItem;
    int AKey;
    int Loc, Pred;    
    do
    {
    menu(&choice);
    switch(choice)
    {
    case 1: printf("Dimiourgia hash list...");
            CreateHashList(&HList);
            printf("Etoimh!");
            break;
    
    case 2: do
            {
                int code;
   	            printf("Dwse ton kwdiko tou xrhsth: ");
                scanf("%d", &code);
                AnItem.RecKey = (code % 10) + 1;                
                printf("Dwse tin idiotita tou xrhsth[1-4]: ");
                scanf("%d", &AnItem.Data);
                printf("Dwse to onoma tou xrhsth: ");
                scanf("%s", &AnItem.Name);            
                AnItem.Link=EndOfList;
                AddRec(&HList, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');  
            break;   
     
     case 3: do
            {
               int code; 
               printf("Dwse ton kwdiko tou xrhsth pou theleis na diagrapseis:  ");
               scanf("%d", &code);
               AKey = (code % 10) + 1;
               DeleteRec(&HList, AKey);              
         	do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;    
            
      case 4: do
            {    
                
                int code;
                printf("Dwse to kwdiko tou xrhsth pros anazhthsh: ");
                scanf("%d", &code);
                AKey = (code % 10) + 1;
                SearchHashList( HList,AKey,&Loc,&Pred);
                char idiotita[20];
                if(HList.List[Loc].Data == 1){strcpy(idiotita,"Student");}
                if(HList.List[Loc].Data == 2){strcpy(idiotita,"Postgraduate Student");}
                if(HList.List[Loc].Data == 3){strcpy(idiotita,"Teacher");}
                if(HList.List[Loc].Data == 4){strcpy(idiotita,"Visitor");}
         		if ( Loc != 0)
                   printf("[%d, %s, %s]\n",code,HList.List[Loc].Name, idiotita);
                else
                   printf("There is no user with code %d\n", code);
         		break;
                
            do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;           
               
       case 5:      PrintPinakes(HList);
     
         			break;        
    }
    } while (choice!=6);
    return 0;
}
void HashKey(int Key,int *HValue)

{
	*HValue=Key%HMax + 1;
}

void CreateHashList(HashListType *HList)

{
	int index;

	HList->Size=0;           
	HList->StackPtr=1;      

    index=1;
	while (index<=HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

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
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
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
void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
          for (i=1; i<=HMax;i++)
              printf("%d ",HList.HashTable[i]);
          printf("\n");

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=1; i<=HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}

void menu(int *choice)
{
    printf("                  Menu                 \n");
    printf("-------------------------------------------------\n");
    printf("1. Create HashList\n");
    printf("2. Insert new user\n");
    printf("3. Delete a user\n");
    printf("4. Search for a user\n");
    printf("5. Print list of all users\n");
    printf("6. Quit\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}


void PrintPinakes(HashListType HList)
{
    int i;
	printf("Users:\n");
	char idiotita[20];
    for (i=1;i<=HList.Size;i++)   
    {
       if(HList.List[i].Data == 1){strcpy(idiotita,"Student");}   
       if(HList.List[i].Data == 2){strcpy(idiotita,"Postgraduate Student");}
       if(HList.List[i].Data == 3){strcpy(idiotita,"Teacher");}
       if(HList.List[i].Data == 4){strcpy(idiotita,"Visitor");}
	   printf("%d %s %d \n",HList.List[i].RecKey,HList.List[i].Name,HList.List[i].Data);	
    }   
    
	printf("\n");
}
    
