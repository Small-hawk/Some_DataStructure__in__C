








void FilterStack (StackType *Stack, int Element)
{
StackType TempStack;
CreateStack(&TempStack);
int TempElement=0;
while(!EmptyStack(*Stack))
{
Pop(Stack,&TempElement);
if(TempElement!=Element)
{
Push(&TempStack,TempElement);
}
}

while(!EmptyStack(TempStack))
{
Pop(&TempStack,&TempElement);
Push(Stack,TempElement);
}
}
