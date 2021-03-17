#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 125

typedef struct {
    char Surname[20];
    char Name[20];
    int Code;
}BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
void RecBSTInorder(BinTreePointer Root);
void menu(int *choice);

main(){//m_S
   int choice, ch;
   BinTreePointer ARoot,Ypalilloi,Ergates,Antiproswpoi, LocPtr;
   BinTreeElementType AnItem;
   boolean Found;
   FILE* TextFile;
   CreateBST(&ARoot);
   CreateBST(&Ypalilloi);
   CreateBST(&Ergates);
   CreateBST(&Antiproswpoi);
   
   TextFile = fopen("I13F5.txt", "r");
   char line[20];
   
 do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:  printf("Importing from file...");
      	         while ( fgets ( line, sizeof line, TextFile ) != NULL )
                  {
                     BinTreeElementType Temp;  
                     char T_sur[20];
                     char T_name[20];
                     int T_code;
                     int i,part = 0,sur_p = 0,name_p = 0;
                     
                     for(i = 0;i <= sizeof line;i++)
                     {
                           
                        if(line[i] == 32)
                        {
                            part++;                          
                            continue;
                        }    
                                                                             
                        if(part == 0)
                        {
                            T_sur[sur_p] = line[i];                            
                            sur_p++;
                            continue;
                        }
                        else if(part == 1)
                        {
                            T_name[name_p] = line[i];
                            name_p++;
                            continue;
                        }
                        else if(part == 2)
                        {
                           
                            if(line[i] == '1'){T_code = 1;}
                            if(line[i] == '2'){T_code = 2;}
                            if(line[i] == '3'){T_code = 3;}                                
                            continue;             
                        }
                        else if(part == 3)
                        {                            
                            break;
                        }   
                                              
                     }                  
                     strcpy(Temp.Surname, T_sur);                    
                     strcpy(Temp.Name, T_name);                                        
                     if(T_code == 1){
                         Temp.Code = T_code;   
                         RecBSTInsert(&Ypalilloi, Temp);
                         ;}
                     else if(T_code == 2){                         
                         Temp.Code = T_code;
                         RecBSTInsert(&Ergates, Temp);}
                     else if(T_code == 3){
                         Temp.Code = T_code;
                         RecBSTInsert(&Antiproswpoi, Temp);
                        }
                  }        
                  printf("Done!");              
      	         break;
         case 2:	do
            {   
                
   	            printf("New Employee Surname: ");
                scanf("%s", &AnItem.Surname);
                printf("New Employee Name: ");
                scanf("%s", &AnItem.Name);
                printf("New Employee Code: ");
                scanf("%d", &AnItem.Code);    
                if(AnItem.Code == 1)  
                    RecBSTInsert(&Ypalilloi, AnItem);
                else if(AnItem.Code == 2)
                    RecBSTInsert(&Ergates, AnItem);  
                else if(AnItem.Code == 3)      
                    RecBSTInsert(&Antiproswpoi, AnItem);    
                else
                    printf("Code Error. \n");    
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 3:    printf("Category to search in[1 = Ypal. Grafeiou | 2 = Ergates | 3 = Antiproswpoi: ");
                    int s_code;
                    scanf("%d",&s_code);   
                    printf("Surname to search for:");
                    scanf("%s", &AnItem.Surname); 
                    if(s_code == 1)
                        RecBSTSearch(Ypalilloi, AnItem, &Found, &LocPtr);                        
                    else if(s_code == 2)    
                        RecBSTSearch(Ergates, AnItem, &Found, &LocPtr);  
                    else if(s_code == 3)    
                        RecBSTSearch(Antiproswpoi, AnItem, &Found, &LocPtr);    
                    else
                        {
                            printf("Code Error. \n");
                            break;
                        }      
                    if(Found==FALSE)
                        printf("Employee not found! \n");
                     else
                        {
                            printf("\nEmployee found! \n");
                            printf("<%s, %s, %d> !",LocPtr->Data.Surname,LocPtr->Data.Name,LocPtr->Data.Code,"/");
                        }       
                        //RecBSTSearch(ARoot, AnItem, &Found, &LocPtr);
         			 
         			break;
        case 4:    
                    printf("\n-------Ypalilloi Grafeiou-------\n");
                    RecBSTInorder(Ypalilloi);      
                    printf("\n-------Ergates------------------\n");            
                    RecBSTInorder(Ergates);       
                    printf("\n-------Antiproswpoi-------------\n");            
                    RecBSTInorder(Antiproswpoi);         
                    break;      
                    
        case 5:
         			break;

		}
   } while (choice!=5);

	return 0;
}//m_E

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (strcmp(Item.Surname, (*Root) ->Data.Surname)<0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.Surname, (*Root) ->Data.Surname)>0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %d EINAI HDH STO DDA\n", Item);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue.Surname, Root->Data.Surname)<0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue.Surname, Root->Data.Surname)>0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer TempPtr;

    if (BSTEmpty(*Root))
        printf("to %d DeN BRE8HKe STO DDA\n", KeyValue);
     else

          if (strcmp(KeyValue.Surname, (*Root) ->Data.Surname)<0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);
          else
            if (strcmp(KeyValue.Surname, (*Root) ->Data.Surname)>0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);
            else
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;
                        free(TempPtr);
                   }
                   else
                   {
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;

                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTPreorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("/%s ",Root->Data.Surname,"/");
        printf("L");
        RecBSTPreorder(Root->LChild);
        printf("R");
        RecBSTPreorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("L");
        RecBSTPostorder(Root->LChild);
        printf("R");
        RecBSTPostorder(Root->RChild);
        printf("/%s ",Root->Data.Surname,"/");
    }
    printf("U");
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {     
        RecBSTInorder(Root->LChild);
        printf("<%s, %s, %d> ",Root->Data.Surname,Root->Data.Name,Root->Data.Code,"/");
        RecBSTInorder(Root->RChild);
    }   
}

void menu(int *choice)
{
    printf("\n                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create BST from file\n");
    printf("2. Insert new employee\n");
    printf("3. Search for an employee\n");
    printf("4. Print employees\n");
    printf("5. Quit\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

