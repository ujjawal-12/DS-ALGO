#include<stdio.h>
#define max 20
void bubbleSort(int *,int);
int main(){
	int arr[max],size,i;
	printf("enter the size of array\n");
	scanf("%d",&size);
	for(i=0;i<size;++i){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,size);
	printf("After sorting list of element is:- \n");
	for(i=0;i<size;++i){
		printf("%d ",arr[i]);
	}
	return 0;
}

void bubbleSort(int *arr,int size){
	int i,j,num;
	for(i=0;i<size;++i){
		for(j=0;j<size-i;++j){
			if(arr[j]>arr[j+1]){
				num=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=num;
			}
		}
	}
}
