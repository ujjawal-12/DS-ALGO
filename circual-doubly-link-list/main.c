#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int ele,old;
	struct node *start=NULL;
	while(1){
		system("cls");
		viewlistitem(start);
		switch(menu()){
			case 1:
				puts("enter the element to insert");
				scanf("%d",&ele);
				insertasfirst(&start,ele);
				break;
			case 2:
				puts("enter the element to insert");
				scanf("%d",&ele);
				insertaslast(&start,ele);
				break;
			case 3:
				puts("enter the element to insert and after which element");
				scanf("%d %d",&ele,&old);
				insertafternode(&start,old,ele);
				break;
			case 4:
				deletefirstitem(&start);
				break;
			case 5:
				deletelastitem(&start);
				break;
			case 6:
				puts("enter element to delete");
				scanf("%d",&old);
				deleteparticularnode(&start,old);
				break;
			case 7:
				  exit(0);
			default :
				puts("enter a valid choice");
		}
		getch();
	}
	return 0;
}
