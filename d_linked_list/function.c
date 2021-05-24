#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

int menu();
void insertasfirst(struct node **,int);
void insertaslast(struct node **,int);
void insertafternode(struct node **,int,int);
void deletefirst(struct node **);
void deletelast(struct node **);
void deletegivennode(struct node **,int);
void viewitem(struct node *);

int menu(){
	int choice;
	puts("\nenter 1 for insert item as first node");
	puts("enter 2 for insert item as last node");
	puts("enter 3 for insert item after a given node");
	puts("enter 4 for delete first node");
	puts("enter 5 for delete last node");
	puts("enter 6 for delete a particular node");
	puts("enter 7 for exit");
	puts("enter your choice:- ");
	scanf("%d",&choice);
	return choice;
}

void insertasfirst(struct node **p,int item){
	struct node *pt,*t;
	pt=(struct node*)malloc(sizeof(struct node));
	pt->prev=NULL;
	pt->data=item;
	pt->next=NULL;
	if(*p==NULL){
		*p=pt;
	}
	else{
		t=*p;
	t->prev=pt;
	pt->next=t;
	*p=pt;	
	}
}

void insertaslast(struct node **p,int item){
    struct node *pt,*t;
    pt=(struct node*)malloc(sizeof(struct node));
    pt->prev=NULL;
    pt->data=item;
    pt->next=NULL;
	if(*p==NULL){
		 *p=pt;
	 }
	 else{
	 	t=*p;
	 	while(t->next!=NULL)
	 	   t=t->next;
	pt->prev=t;
	t->next=pt;
	 	
	 }	
}

void insertafternode(struct node **p,int item,int newitem){
	struct node *pt,*t;
    pt=(struct node*)malloc(sizeof(struct node));
    pt->prev=NULL;
    pt->data=newitem;
    pt->next=NULL;
    if(*p==NULL){
    	puts("list empty..!!");
	}
	else{
		t=*p;
		while(t->data!=item ){
		  if(t->next!=NULL)
		    {
		       t=t->next;
	        }
	        else{
	        		puts("element doesnot exit...!");
	        		break;
			}
       	}
		if(t->data==item){ 
		pt->prev=t;
		pt->next=t->next;
		t->next=pt;
	}
	}
}

void viewitem(struct node *p){
	struct node *t;

	if(p==NULL)
	{
		puts("list empty..!!");
	}
	else{
			t=p;
       	
      	while(t->next!=NULL){
      	printf("%d\t",t->data);
      	t=t->next;
      }
      	printf("%d",t->data);
	}
	
}

void deletefirst(struct node **p){
	struct node *s,*t;
	s=*p;
	if(s==NULL){
		puts("list empty..!!");
	}
	else if(s->next!=NULL){
	   t=s->next;
	   t->prev=NULL;
	   *p=t;
	   free(s);
	}
	else{
		free(s);
		*p=NULL;
	}
}

void deletelast(struct node **p){
	struct node *s,*t;
     s=*p;
	if(*p==NULL){
		puts("list empty..!!");
	}
	else if(s->next==NULL)
	{
		*p=NULL;
	}
	else{
		while(s->next!=NULL)
		s=s->next;
		t=s->prev;
		t->next=NULL;
	}
		free(s);
}

void deletegivennode(struct node **p,int item){
	struct node *s,*t,*y;
	s=*p;
	if(*p==NULL){
		puts("list empty..!!");
	}
	else{
	while(s->data!=item)
	s=s->next;
	if(s->next==NULL){
		if(*p==s){
			*p=NULL;
			free(s);
		}
		else{
			t=s->prev;
			t->next=s->next;
			free(s);
		}
	}
	else{
		if(s->prev==NULL && s->next!=NULL){
			t=s->next;
			t->prev=NULL;
			*p=t;
		}
	else{
		t=s->prev;
        y=s->next;
     	t->next=y;
    	y->prev=t;
		}
  
	free(s);	
	}
}
}

