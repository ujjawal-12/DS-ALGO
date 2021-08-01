#include<stdio.h>
#define max 20
int binarySearch(int *,int,int);
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
	result=binarySearch(arr,size,num);
	if(result==-1)
	printf("%d element is not present in this array",num);
	else
	printf("%d is present at index %d",num,result);
	return 0;
}

int binarySearch(int *arr,int size,int num){
int l,u,div;
l=0;
u=size-1;
while(l<=u){
	div=(l+u)/2;
	if(num==arr[div]){
		return div;
	}
	else if(arr[div]>num){
		u=div-1;
	}
	else{
		l=div+1;
	}
}
return -1;
}
