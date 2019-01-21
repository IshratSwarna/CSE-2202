#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int>graph[100];
int visited[100];

int main()
{
    int node , edge , x, y;
    cin>>node>>edge;
    cout<<"Enter the Edges : "<<endl;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int source ;
    cout<<"Enter Source node : \n";
    cin>>source;

    queue<int>Q;
    Q.push(source);
    visited[source] = 1;
    while(!Q.empty())
    {
        int u = Q.front();
        cout<<u<<" ";
        Q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(visited[v]==0){
                visited[v]=1;
                Q.push(v);
            }
        }
    }
    return 0;
}

