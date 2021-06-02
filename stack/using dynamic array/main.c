#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	struct stack *pt=NULL;
	int size,item;
	puts("enter the size of stack");
			scanf("%d",&size);
			pt=(struct stack*)createstack(pt,size);
	while(1){
		system("cls");
		capacityofstack(pt);
		isempty(pt);
		isfull(pt);
		count(pt);
		viewstack(pt);
		switch(menu()){
			case 1:
				puts("enter the element to push into stack");
				scanf("%d",&item);
				push(&pt,item);
				break;
			case 2:
				pop(&pt);
				break;
			case 3:
				exit(0);
			default:
				puts("enter a valid choice");
				break;
		}	
		getch();
	}
	free(pt);
	return 0;
}
