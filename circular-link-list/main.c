#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	struct node *last=NULL;
	int value,no;
	while(1){
		system("cls");
		viewlistitem(last);
		switch(menu()){
			case 1:
				puts("enter element to insert");
				scanf("%d",&value);
				insertitemfirst(&last,value);
				break;
			case 2:
				puts("enter element to last");
				scanf("%d",&value);
				insertitemlast(&last,value);
				break;
			case 3:
				puts("enter element to insert after a particular element");
				scanf("%d",&value);
				puts("after which element");
				scanf("%d",&no);
				insertitemafternode(&last,no,value);
				break;
			case 4:
				deletefirst(&last);
				break;
			case 5:
				deletelast(&last);
				break;
			case 6:
				puts("enter element to delete");
				scanf("%d",&value);
				delgivennode(&last,value);
				break;
			case 7:
					exit(0);
			default:
				puts("enter valid choice");
				break;
		}
		getch();
	}
	free(last);
	return 0;
}
