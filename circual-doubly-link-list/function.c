#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int item;
	struct node *next;
};

int menu();
void insertasfirst(struct node **,int);
void insertaslast(struct node **,int);
void insertafternode(struct node **,int,int);
void deletefirstitem(struct node **);
void deletelastitem(struct node **);
//void deleteparticularnode(struct node **,int);
void viewlistitem(struct node *);

int menu(){
	int choice;
	puts("\npress 1:-> for insert item as first node");
	puts("press 2:-> for insert item as last node");
	puts("press 3:-> for insert item after given node");
	puts("press 4:-> for delete first node");
	puts("press 5:-> for delete last node");
	puts("press 6:-> for delete particular node");
	puts("press 7:-> for exit");
	puts("enter your choice");
	scanf("%d",&choice);
	return choice;
}

void insertasfirst(struct node **p,int val){
	struct node *pt,*t,*s;
	t=*p;
	pt=(struct node*)malloc(sizeof(struct node));
	pt->item=val;
	if(t==NULL){
		pt->prev=pt;
		pt->next=pt;
		*p=pt;
	}
	else{
		s=t->prev;
		pt->prev=t->prev;
		pt->next=t;
		t->prev=pt;
		s->next=pt;
		*p=pt;
	}
}

void insertaslast(struct node **p,int val){
	struct node *pt,*t,*s;
	t=*p;
	pt=(struct node*)malloc(sizeof(struct node));
	pt->item=val;
	if(t==NULL){
		pt->prev=pt;
		pt->next=pt;
		*p=pt;
	}
	else{   
		s=t->prev;
		pt->prev=t->prev;
		pt->next=t;
		s->next=pt;
		t->prev=pt;
	}
}


void viewlistitem(struct node *p){
	struct node *s;
	s=p;
	if(p!=NULL){
	while(s->next!=p){
		printf("\t%d",s->item);
		s=s->next;
	}
		printf("\t%d",s->item);
}
else{
	puts("list empty");
}
}

void insertafternode(struct node **p,int old,int n){
	struct node *pt,*t;
	t=*p;
	pt=(struct node*)malloc(sizeof(struct node));
	pt->item=n;
	while(t->item!=old){
		t=t->next;
	}
	pt->prev=t;
	pt->next=t->next;
	t->next=pt;
}

void deletefirstitem(struct node **p){
  struct node *s,*t,*y;
  s=*p;
	if(*p==NULL){
		puts("list empty");
	}
	else if(s->next==s){
		free(s);
		*p=NULL;
	}
	else{
		t=s->next;
		y=s->prev;
		t->prev=y;
		y->next=t;
		free(s);
		*p=t;
	}
}

void deletelastitem(struct node **p){
	struct node *s,*t,*y;
	s=*p;
	if(s==NULL){
		puts("list empty");
	}
	else if(s->next==s){
		free(s);
		*p=NULL;
	}
	else{
		t=s->prev;
		y=t->prev;
		y->next=t->next;
		free(s->prev);
		s->prev=y;
	}
}
