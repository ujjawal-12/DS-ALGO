#include<stdio.h>
#define max 20
int linear_search(int *,int,int);
int main(){
	int arr[max],i,result,num,size;
	printf("enter the size of array\n");
	scanf("%d",&size);
	printf("enter the element in array\n");
	for(i=0;i<size;++i){
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be search\n");
	scanf("%d",&num);
	result=linear_search(arr,size,num);
	if(result==-1)
	printf("%d element is not present in this array",num);
	else
	printf("%d is present at index %d",num,result);
	return 0;
}

int linear_search(int *arr,int size,int num){
	int i;
	for(i=0;i<num;++i){
		if(num==arr[i]){
			return i;
		}
	}
	return -1;
}
