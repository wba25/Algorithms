#include <bits/stdc++.h>
#define MAX 100

using namespace std;

vector<int> l_adj[MAX];

bool mark[MAX];
int d[MAX];

void BFS(Graph* G, int s){
	queue <int> que;
	for(int u = 0; u<G->edge ;u++){
		mark[u] = false;
		d[u] = -1;
	}
	
	mark[s] = true;
	d[s] = 0;
	
	que.push(s);
	
	while(!que.empty()){
		int u = que.pop();
		if(!l_adj[u].empty()){			
			for(int v = l_adj[u].front();   v<l_adj[u].size();    v++){
				if(mark[v] == false){
					mark[v] = true;
					d[v] = d[u] + 1;
					que.push(v);
				}	
			}
		}
	}
	
}

typedef struct graph{
	int edge;
	int vertex;
}Graph;

int main(){
	
	return 0;	
}
