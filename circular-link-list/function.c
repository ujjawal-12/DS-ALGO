#include <stdio.h>
#include <stdlib.h>

struct node{
	int item;
	struct node *next;
};

int menu();
void insetitemfirst(struct node **,int);
void insertitemlast(struct node **,int);
void insertitemafternode(struct node **,int,int);
void deletefirst(struct node **);
void deletelast(struct node **);
void delgivennode(struct node **,int);
void viewlistitem(struct node *);

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

void insertitemfirst(struct node **pt,int item){
	struct node *py,*t;
	py=(struct node*)malloc(sizeof(struct node));
     py->item=item;
	t=*pt;
	if(t==NULL){
		py->next=py;
		*pt=py;
	}
	else{
	  py->next=t->next;
	  t->next=py;
	}
}

void insertitemlast(struct node **pt,int data){
	struct node *py,*t,*s;
     py=(struct node*)malloc(sizeof(struct node));
     py->item=data;
	t=*pt;
	if(t==NULL){
		py->next=py;
		*pt=py;
	}
	else{
		py->next=t->next;
		t->next=py;
		*pt=py;
	}
}

void insertitemafternode(struct node **pt,int item,int val){
	struct node *s,*py;
		s=*pt;
	if(item==s->item){
		insertitemlast(pt,val);
	}
	else{
     py=(struct node*)malloc(sizeof(struct node));
     py->item=val;
     py->next=NULL;
	
		while(s->item!=item)
		   s=s->next;
		py->next=s->next;
		s->next=py;
	}
}

void deletefirst(struct node **pt){
	struct node *py,*t,*s;
	py=*pt;
    if(*pt==NULL){
    	puts("list empty..!!");
	}
	else if(py->next==py){
		free(*pt);
		*pt=NULL;
	}
	else{
	t=py->next;
	s=t->next;
	py->next=s;
	free(t);
	}	
}

void deletelast(struct node **pt){
	struct node *py,*t,*s;
	py=*pt;
    if(py==NULL){
    	puts("list empty..!!");
	}
	else if(py->next==*pt){
			free(*pt);
		*pt=NULL;
	}
	else{
		t=*pt;
		while(t->next!=t){
			t=t->next;	
		}
		t->next=py->next;
		free(*pt);
		*pt=t;
	}	
}

void delgivennode(struct node **pt,int item){
	struct node *s,*r,*py;
	py=*pt;
	s=py->next;
	if(py->item==item)
	  deletelast(pt);
	else if(s->item==item)
	   deletefirst(pt);
	else{
		while(s->item!=item){
			r=s;
			s=s->next;
		}
		r->next=s->next;
		free(s);
	}
}

void viewlistitem(struct node *pt){
   struct node *s,*t;
   if(pt==NULL){
   	puts("list empty");
   }
   else{
   	s=pt->next;
	while(s->next!=s){
    printf("%d\t",s->item);	
 	s=s->next;
	
	}
	printf("%d\t",s->item);	
	}
}
