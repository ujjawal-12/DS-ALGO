#include<stdio.h>
#define max 20
void selectionSort(int *,int);
int main(){
	int arr[max],size,i;
	printf("enter the size of array\n");
	scanf("%d",&size);
	for(i=0;i<size;++i){
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,size);
	printf("After sorting list of element is:- \n");
	for(i=0;i<size;++i){
		printf("%d ",arr[i]);
	}
	return 0;
}

void selectionSort(int *arr,int size){
	int i,j,num,n;
	for(i=0;i<size;++i){
			num=arr[i];
		for(j=i+1;j<size;++j){
			if(num>arr[j]){
				n=arr[j];
				arr[j]=num;
				arr[i]=n;
			}
		}
	}
}
