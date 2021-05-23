#include<stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node *next;
};

int menu();
void itemasfirstnode(struct node **,int);
void itemaslastnode(struct node **,int);
void itemasgivennodde(struct node **,int,int);
void deletefirstitem(struct node **);
void deletelastitem(struct node **);
void deleteasgivennode(struct node **,int);
void viewalllistitem(struct node **);

int menu(){
    int choice;
puts("\nenter 1 for add item as last node");
puts("enter 2 for add item as first node");
puts("enter 3 for add item as after given node");
puts("enter 4 for delete first node");
puts("enter 5 for delete after given node");
puts("enter 6 for delete last node");
puts("enter 7 for view list item");
puts("enter 8 for exit");
puts("enter your choice");
scanf("%d",&choice);
return choice;
}
void itemasfirstnode(struct node **pt,int item){
    struct node *p,*t;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=item;
    p->next=NULL;
    t=*pt;
    if(*pt==NULL){
        *pt=p;
    }
        else{
   p->next=t;
   *pt=p;
        }
}

void itemaslastnode(struct node **pt,int item){
    struct node *p,*t;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=item;
    p->next=NULL;
    t=*pt;
if(*pt!=NULL){
    while(t->next!=NULL)
        t=t->next;
    t->next=p;
}
else{
*pt=p;
}
}

void viewalllistitem(struct node **pt){
 struct node *t;
 if(*pt==NULL){
    puts("empty list!!..");
 }
 else{
     t=*pt;
     printf("%d\t",t->data);
    while(t->next!=NULL)
    {

        t=t->next;
         printf("%d\t",t->data);
    }

 }
}

void itemasgivennodde(struct node **pt,int item,int newitem){
   struct node *p,*t,*s;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=newitem;
    p->next=NULL;
   if(*pt==NULL){
    puts("list empty..!!");
   }
   else{
    t=*pt;
    while(t->data!=item)
        t=t->next;
    s=t;
    p->next=s->next;
    t->next=p;
   }
}

void deletelastitem(struct node **pt){
 struct node *t,*s,*y;
 y=*pt;
 if(*pt==NULL){
    puts("empty list..!!");
 }
 else{
    t=*pt;
    while(t->next!=NULL){
        s=t;
        t=t->next;
    }
    if(y->next==NULL){
        *pt=NULL;
    }
    else{
    s->next=NULL;
    free(t);
    }
 }
}

void deletefirstitem(struct node **pt){
  struct node *s;
  if(*pt==NULL){
    puts("empty list..!!");
  }
  else{
    s=*pt;
    *pt=s->next;
    free(s);
  }
}

void deleteasgivennode(struct node **pt,int item){
   struct node *t,*s;

    if(*pt==NULL){
        printf("no item exit after ");
    }
    else{
        t=*pt;
        while(t->data!=item){
           t=t->next;
        }

        if(t->next!=NULL){
        s=t->next;
        t->next=s->next;
        free(s);
        }
        else{
            printf("\n no element exit after %d",s->data);
        }

    }
}
