#include <stdio.h>

void selectionsort(int* arr, int size){
	int i,j,menor,temp;
	for(j=0;j<size-1;j++){
		menor = j;
		i = j+1;
		while(i<size){
			if(arr[menor]>arr[i]) menor = i;
			i++;
		}
		
		if(menor!=j){
			temp = arr[j];
			arr[j] = arr[menor];
			arr[menor] = temp;
		}
	}
}

int main(){
	int arr[20] = {5,2,4,6,1,3}, size = 6, i;
	for(i = 0; i<size; printf("%d ",arr[i++]));	
	puts("\n");
	selectionsort(arr,size);
	for(i = 0; i<size; printf("%d ",arr[i++]));
	return 0;
}
