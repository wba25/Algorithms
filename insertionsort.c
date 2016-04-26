#include <stdio.h>

void insertionsort(int* arr, int size){
	int j, i, key, temp;
	for(j = 1; j<size; j++){
		key = arr[j];
		i = j-1;
		while((i>=0)&&(key<arr[i])){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
}

int main(){
	int arr[20] = {5,2,4,6,1,3}, size = 6, i;
	for(i = 0; i<size; printf("%d ",arr[i++]));	
	puts("\n");
	insertionsort(arr,size);
	for(i = 0; i<size; printf("%d ",arr[i++]));	
}
