#include <stdio.h>
#define INT_MAX 2147483647

void merge(int *arr, int begin, int middle, int end){
	int n1, n2, i, j, k;
	n1 = middle - begin + 1;
	n2 = end - middle;
	//Reserva-se uma posição extra para o sentinel
	int left[n1+1], right[n2+1];
	for(i = 0; i < n1; i++){
		left[i]= arr[begin + i];
	}
	for(j = 0; j < n2; j++){
		right[j] = arr[middle + 1 + j];
	}
	//Sentinelas
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	i = j = 0;
	
	for(k=begin; k<=end; k++){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
	}
}

void mergesort(int* arr, int begin, int end){
	if(begin<end){		
		int middle = (begin+end)/2;
		mergesort(arr,begin,middle);
		mergesort(arr,middle+1,end);
		merge(arr,begin,middle,end);
	}
}

int main(){
	int arr[30] = {5,2,4,6,1,3,67,12,9,8,51,21,41,61,11,31,671,121,91,81,75,72,74,76,71,73,767,712,79,78}, size = 30, i;
	for(i = 0; i<size; printf("%d ",arr[i++]));	
	puts("\n");
	mergesort(arr,0,size-1);
	for(i = 0; i<size; printf("%d ",arr[i++]));	
	return 0;
}
