#include<stdio.h>
#include<stdlib.h>

struct stack{
int item;
struct stack *next;
};

int menu();
void push(struct stack **p,int);
void pop(struct stack **p);
void viewstack(struct stack *);

int menu(){
	int choice;
	puts("\npress 1 for push item into stack");
	puts("press 2 for pop item from stack");
	puts("press 3 for exit");
	scanf("%d",&choice);
	return choice;
}

void push(struct stack **p,int data){
struct stack *pt,*t;
t=*p;
pt=(struct stack*)malloc(sizeof(struct stack));
pt->item=data;
pt->next=NULL;
if(t==NULL){
	*p=pt;
}	
else{
	while(t->next!=NULL)
	t=t->next;
	t->next=pt;
}
}

void pop(struct stack **p){
	struct stack *t,*s;
	t=*p;
	if(t==NULL){
		puts("stack underflow");
	}
	else{
		if(t->next!=NULL){
		while(t->next!=NULL)
		{    s=t;
		     t=t->next;
      	}
      	free(t);
      	s->next=NULL;
	}
	else{
		 free(*p);
		 *p=NULL;
	}
  }
}

void viewstack(struct stack *pt){
	struct stack *s;
	s=pt;
	if(s!=NULL){
	while(s){
		printf("%d\t",s->item);
		s=s->next;
	}
}
else{
	puts("stack underflow");
}
}
