#include<stdio.h>
#include<stdlib.h>

struct stack{
	int capacity;
	int *p;
	int top;
};

int menu();
struct stack* createstack(struct stack *p,int size);
void push(struct stack **p,int item);
void pop(struct stack **p);
int pick(struct stack *p);
void count(struct stack *p);
void isempty(struct stack *p);
void isfull(struct stack *p);
void viewstack(struct stack *p);
void stackhalf(struct stack *p);
void stackdouble(struct stack *);
void capacityofstack(struct stack *p);

int menu(){
	int choice;
	puts("\npress 1 for push item into stack");
	puts("press 2 for pop item from stack");
	puts("press 3 for exit");
	scanf("%d",&choice);
	return choice;
}

struct stack* createstack(struct stack *p,int size){
	struct stack *ptt;
	int *arr;
	ptt=(struct stack*)malloc(sizeof(struct stack));
	arr=(int*)malloc(sizeof(int)*size);
	ptt->capacity=size;
	ptt->p=arr;
	ptt->top=-1;
	return ptt;
}

void push(struct stack **py,int item){
	struct stack *ptt;
	ptt=*py;
	int i;
	if(ptt!=NULL){
		if(ptt->capacity>(pick(ptt)+1)){
			i=ptt->top+=1;
			ptt->p[i]=item;
	 	puts("item push successfully");
		}
		else{
			stackdouble(*py);
			puts("insert again");		}
	}
	else{
		puts("stack is not created ");
	}
}

void pop(struct stack **p){
	struct stack *ptt;
	ptt=*p;
	if(ptt==NULL){
			puts("stack underflow");
	}
	else if((ptt->top)==(ptt->capacity/2)){
		stackhalf(*p);
	}
	else{
		ptt->top-=1;
		puts("item pop successfully");
	}
		
}

int pick(struct stack *p){
	return p->top;
}

void count(struct stack *p){
  int total;
	if(p!=NULL){
		total=pick(p)+1;
		printf("total element in stack is :- %d\n",total);
	}
	else{
		puts("Stack not created yet");
	}
}

void isempty(struct stack *p){
	if(p==NULL){
		puts("stack not created yet");
	}
	else{
		if((p->top+1)<(p->capacity))
		puts("empty");
		else
		puts("not empty");
	}
}

void isfull(struct stack *p){
	if(p==NULL){
		puts("stack not created yet");
	}
	else{
		if((p->top+1)==(p->capacity))
		puts("Stack full");
		else
		puts("Stack not full");
	}
}

void viewstack(struct stack *ptt){
	int i;
	if(ptt!=NULL){
	for(i=0;i<(ptt->top+1);++i){
		printf("%d\t",ptt->p[i]);
	}
}
else{
	puts("stack npt created yet");
}
}

void capacityofstack(struct stack *p){
	if(p!=NULL){
		printf("Capacity of stack is:- %d\n",p->capacity);
	}
}

void stackdouble(struct stack *pt){
  int cap,*t;
  cap=pt->capacity;
  t=(int*)realloc(pt->p,(sizeof(int)*cap)*2);
  pt->capacity*=2;
  pt->p=t;
  
}

void stackhalf(struct stack *pt){
	struct stack *t;
	int *s,i;
	t=pt;
	s=(int*)malloc(sizeof(int)*t->top);
	for(i=0;i<t->top;++i){
		s[i]=t->p[i];
	}
	free(pt->p);
	pt->p=s;
	pt->capacity/=2;
	pt->top-=1;
}
