#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

int main()
{
struct node *start=NULL;
int val,item;
while(1){
    system("cls");
    viewalllistitem(&start);
    switch(menu()){
case 1:
    puts("enter the item to add");
    scanf("%d",&val);
    itemaslastnode(&start,val);
    break;
case 2:
    puts("enter the item to add");
    scanf("%d",&val);
     itemasfirstnode(&start,val);
    break;
case 3:
    puts("enter the item to add");
    scanf("%d",&val);
    puts("enter the item to add after node");
    scanf("%d",&item);
    itemasgivennodde(&start,item,val);
    break;
case 4:
    deletefirstitem(&start);
    break;
case 5:
     puts("enter the item to delete after node");
    scanf("%d",&val);
    deleteasgivennode(&start,val);
    break;
case 6:
     deletelastitem(&start);
    break;
case 7:
    viewalllistitem(&start);
    break;
case 8:
    exit(0);
default:
    puts("enter valid no...");
    }
    getch();
}
  free(start);
    return 0;
}
