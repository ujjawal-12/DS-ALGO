#include<stdio.h>
struct a1* createArray(int);
void appendItem(struct a1 *,int);
int getItem(struct a1 *,int);
int countItem(struct a1 *);
void isEmpty(struct a1 *);
void isFull(struct a1 *);
int editItem(struct a1 *,int,int);
int searchItem(struct a1 *,int);
/*void insertItem(struct a1 *,int,int);*/
void viewarray(struct a1 *);
void removeItetm(struct a1 *,int);
int menu();

typedef struct a1{
int capacity;
int lastIndex;
int *p
}smartArray;

int menu(){
int choice;
printf("\n enter 1 for append item");
printf("\n enter 2 for get item");
printf("\n enter 3 for edit item");
printf("\n enter 4 for search item");
printf("\n enter 5 for delete item");
printf("\n enter 6 for exit");
printf("\n enter the choice:- ");
scanf("%d",&choice);
return choice;
}

smartArray* createArray(int length){
smartArray *pt=(smartArray*) malloc(sizeof(smartArray));
pt->capacity=length;
pt->lastIndex=-1;
pt->p=(int*)malloc((sizeof(int))*length);
return pt;
}

void appendItem(struct a1 *ptt,int item){
if(ptt->lastIndex+1==ptt->capacity){
puts("overflow");
}
else{
    ptt->lastIndex+=1;
    ptt->p[ptt->lastIndex]=item;
    printf("item append sccessfully:- %d\n",item);

}
}

int getItem(struct a1 *ptrr,int index){
   int item;
    if(index<=ptrr->lastIndex)
    { item=ptrr->p[index];
      return item;
    }
    else{
        return NULL;
    }
}

int countItem(struct a1 *pt){
    int item;
    if((pt->lastIndex>=0) && (pt->lastIndex<pt->capacity)){
    item=pt->lastIndex+1;
    return item;
    }
    else {
        return NULL;
    }
}

void isEmpty(struct a1 *p){
   if(p->lastIndex+1==p->capacity){
    puts("Not Empty");
   }
   else{
     puts("Empty");
   }
}

void isFull(struct a1 *p){
    if(p->lastIndex==p->capacity-1){
    puts("Array is full");
   }
   else{
    puts("Not full");
   }
}

int editItem(struct a1 *pt,int index,int value){
    int i;
    if(index<pt->capacity && index>-1){
        i=pt->p[index];
        pt->p[index]=value;
        return i;
    }
    else{
        return NULL;
    }
}

int searchItem(struct a1 *ptt,int item){
   int i;
   if(ptt->lastIndex>=0){
    for(i=0;i<=ptt->lastIndex;i++){
        if(ptt->p[i]==item)
            return ++i;
    }
   return NULL;
}
}

void removeItetm(struct a1 *ptt,int item){
    int i,j;
    for(i=0;i<=ptt->lastIndex;i++){
        if(ptt->p[i]==item){
                for(j=i;j<=ptt->lastIndex;j++){
                  ptt->p[i]=ptt->p[++i];
                }
            ptt->lastIndex-=1;
            break;
        }
    }
}

void viewarray(struct a1 *pt){
    int i;
    for(i=0;i<=pt->lastIndex;i++){
      printf("%d\t",pt->p[i]);
    }
}
