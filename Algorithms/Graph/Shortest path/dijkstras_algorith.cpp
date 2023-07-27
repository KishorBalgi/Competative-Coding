#include<iostream>
#include<limits.h>

using namespace std;

#define V 9

int minDistance(int dist[],bool sptSet[]){
    int min=INT_MAX,min_index;

    for(int i=0;i<V;i++){
        if(sptSet[i]==false && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V],int src){
    // Array to store distances from src:
    int dist[V];

    // Array to store included nodes in SPT(shortest Spanning Tree):
    bool sptSet[V];

    // Init the dist and sptSet:
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<V-1;i++){
        int u=minDistance(dist,sptSet);

        sptSet[u]=true;

        for(int v=0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist);
}   

int main(){
    int graph[V][V]={
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph,0);

    return 0;
}