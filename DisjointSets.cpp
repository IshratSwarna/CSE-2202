///Disjoint Sets

#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;

int Parent[100];
int Rank[100];

void initSet(int n){
    for(int i=0;i<n;i++){
        Parent[i] = i;
        Rank[i] = 1;
    }
}

int FindParent(int x){
    if(Parent[x] != x){
        return Parent[x] = FindParent(Parent[x]);
    }
    else
        return x;
}

void UnionSet(int x, int y){
    int px = FindParent(x);
    int py = FindParent(y);

    if(px==py) return;

    if(Rank[px] > Rank[py]){
        Parent[py] = Parent[px];
        Rank[px]++;
    }
    else if(Rank[py] > Rank[px]){
        Parent[px] = Parent[py];
        Rank[py]++;
    }
    else{
        Parent[py] = Parent[px];
         Rank[px]++;
    }
}

void PrintSet(int n){
    for(int i=0;i<n;i++){
        printf("Node %d : Parent %d\n",i,FindParent(i));
    }
    printf("\n");
}
int main()
{
    int n;
    cin>>n;
    initSet(n);
    PrintSet(n);

    int m,x,y;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        UnionSet(x,y);
        PrintSet(n);
    }

    for(int i=0;i<n;i++){
        printf("Node %d : Rank %d\n",i,Rank[i]);
    }
    printf("\n");
    return 0;
}


