#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
using namespace std;

int** createmat(int n){
	int **m = new int*[n];
	for(int i=0;i<n;i++)
		m[i] = new int[n];
	return m;
}
int minKey(int key[], bool mstSet[],int V)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
int printMST(int parent[], int V, int **graph)
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int **graph,int V)
{
     int parent[V];
     int key[V]; 
     bool mstSet[V];  
     for (int i = 0; i < V; i++)
     key[i] = INT_MAX, mstSet[i] = false;
     key[0] = 0;
     parent[0] = -1; 
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet,V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST(parent, V, graph);
}
 
int main(){
	int n,v;
	cout<<"The no of vertices\n";
	cin>>n;
	int **graph=createmat(n);
	cout<<"Enter the no of edges\n";
	cin>>v;
	cout<<"Enter the points joining and distance\n";
	rep(i,n) rep(j,n) graph[i][j]=0;
	rep(i,v){
		int x,y,d;
		cin>>x>>y>>d;
		graph[x][y]=d,graph[y][x]=d;
	}
	rep(i,n){
		rep(j,n) cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	primMST(graph,n);
}
