//Mochila booleana, sem repetição

#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
	return a>b ? a : b;
}

/*
-k = capacidade da mochila
-n = total de itens a escolha
-wt = pesos dos n itens
-val = valores dos n itens
*/
int knapsack(int k, int n, int* wt, int* val){
	int W[n+1][k+1];
	int i,j;
	//Recursão bottom up:
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < k+1; j++){
			//caso base: primeira linha e primeira coluna eh 0(zero)
			if((i==0)||(j==0)){
				W[i][j] = 0;
			}
			//casos indutivos
			//Se cabe
			else if(  wt[i-1] <= j){
				//Recebe o maior valor entre o valor de linha anterior e seu valor somado com o peso da linha anterior da coluna j-wt[i-1]
				W[i][j] = max(val[i-1]+W[i-1][j-wt[i-1]], W[i-1][j]);
			}
			//Se não cabe
			else{
				//Recebe o valor da linha anterior
				W[i][j] = W[i-1][j];
			}
		}
	}
	
	return W[n][k];
}

int main(){
	int k, n, *wt, *val;
	scanf("%d%d",&k,&n);
	wt = new int[n];
	val = new int[n];
	cout << "Valor maximo: " << knapsack(k,n,wt,val) << endl;
	return 0;
}
