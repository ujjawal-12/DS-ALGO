#include <stdio.h>
#include <stdlib.h>

int main()
{
int data,item,ele,pos,len;
struct a1 *ptr=NULL;
puts("Enter length of array");
scanf("%d",&len);
ptr=createArray(len);
    while(1){
        system("cls");
        data=countItem(ptr);
        printf("Total element in array:- %d\n",data);
        isEmpty(ptr);
        isFull(ptr);
        viewarray(ptr);
        switch(menu()){
        case 1:
                puts("enter the element to append in array");
                scanf("%d",&item);
                appendItem(ptr,item);
                puts("Press enter to proceed");
                break;
        case 2:
               puts("enter index to get item");
               scanf("%d",&pos);
               ele=getItem(ptr,pos);
               if(ele!=NULL){
                printf("\n item:- %d",ele);
                    }
               else{
                puts("array index out of bond");
                    }
               break;
        case 3:
                 puts("enter position and value to replace\n");
                 scanf("%d %d",&pos,&item);
                 ele=editItem(ptr,pos,item);
                if(ele!=NULL){
                     printf("%d is replaced with current element %d\n",ele,item);
                    }
                else{
                     puts("array index is not valid");
                    }
               break;
        case 4:
              puts("enter elment for search in array");
              scanf("%d",&item);
              ele=searchItem(ptr,item);
              if(ele!=NULL){
                  printf("%d is availaible in %d index",item,--ele);
                 }
              else{
                  printf("array is empty || index out of bond",ele);
                 }
               break;
        case 5:
              puts("enter element to delete");
              scanf("%d",&item);
              removeItetm(ptr,item);
               break;
        case 6:
              exit(0);
        default :
               printf("Invalid choice");
        }
        getch();
    }
    free(ptr);
    return 0;
}
