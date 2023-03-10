#include<iostream>
using namespace std;
#include<limits.h>
#define V 5
int minDistance(int dist[],bool sptSet[]) {
	int min=INT_MAX,min_index;
for(int v=0;v<V;v++)
        if(sptSet[v]==false && dist[v]<=min)
           min=dist[v],min_index=v;
return min_index;
}
void printSolution(int dist[]) {
	cout<<"Vertex \t Distance from source"<<endl;
	for(int i=0;i<V;i++)
	    cout<<i<<"\t\t"<<dist[i]<<endl;
}
void djikstra(int graph[V][V],int src) {
	int dist[V];
	bool sptSet[V];
	for(int i=0;i<V;i++) 
	    dist[i]=INT_MAX,sptSet[i]=false;
	dist[src]=0;
	for(int count=0;count<V-1;count++) {
		int u=minDistance(dist,sptSet);
		sptSet[u]=true;
		for(int v=0;v<V;v++)
		    if(!sptSet[v] && graph[u][v] && dist[u!=INT_MAX && dist[u]+graph[u][v]<dist[v]])
		           dist[v]=dist[u]+graph[u][v];
	}
	printSolution(dist);
}
int main() {
	int graph[V][V],source;
	char i,j;
	cout<<"Enter adjacency matrix for 5 vertices \n";
	for(i=0;i<V;i++) {
		for(j=0;j<V;j++) {
			cin>>graph[i][j];
		}
	}
	cout<<"Enter source :";
	cin>>source;
	djikstra(graph,source);
	return 0;
}
