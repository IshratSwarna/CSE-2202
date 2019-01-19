#include<bits/stdc++.h>
#define MAX 9999
#define V 5
using namespace std;

int FindMin(int cost[], int visit[])
{
    int mini = MAX, minx ;
    for(int i=0;i<V;i++){
        if((cost[i] < mini) && (visit[i] == 0)){
            minx = i; mini = cost[i];
        }
    }
    return minx;
}
void Prims(int graph[V][V])
{
    int parent[V+1] , cost[V+1] , visit[V+1];
    for(int i=0;i<V;i++){
        cost[i] = MAX;
        visit[i] = 0;
    }
    cost[0] = 0; parent[0] = -1;
    for(int c=0;c<V-1;c++){
        int u = FindMin(cost,visit);
        visit[u] = 1;
        for(int v=0;v<V;v++){
            if((graph[u][v] != 0) && (visit[v] == 0) && (graph[u][v] < cost[v])){
                cost[v] = graph[u][v] ; parent[v] = u;
            }
        }
    }
    for(int i=1;i<V;i++)
        cout<<parent[i]<<"-"<<i<<"  "<<cost[i]<<endl;
}

int main()
{
    int graph[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            graph[i][j] = 0;
    }
    int x,y,c;
    int edge;
    cin>>edge;
    for(int i=0;i<edge;i++){
        cin>>x>>y>>c;
        graph[x][y] = c;
        graph[y][x] = c;
    }
    cout<<"Minimum Spanning Tree using Prim's Algorithm :\n";
    Prims(graph);
    return 0;
}
/***Input:              Output:
7
0 1 3                   Minimum Spanning Tree using Prim's Algorithm :
0 2 5                   0-1  3
1 3 6                   1-2  1
1 2 1                   2-3  2
2 3 2                   3-4  1
3 4 1
2 4 4
***/
