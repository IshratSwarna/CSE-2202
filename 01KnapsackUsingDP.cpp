#include<bits/stdc++.h>
using namespace std;

int Knapsack(int *weight,int *profit,int TW, int n)
{
    int Box[TW+1][n+1];
    int i,j;
    for(i=0;i<=TW;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                Box[i][j] = 0;
            else if(weight[j] > i)
                Box[i][j] = Box[i][j-1];
            else{
                int row = i-weight[j];
                int rcap = Box[row][j-1];
                int c = profit[j] + rcap;
                Box[i][j] = max(Box[i][j-1] , c);
            }
        }
    }
    cout<<"Weights\t\tObjects\n";
    cout<<"////\t\t";
    for(i=0;i<=n;i++)
        cout<<i<<"\t";
    cout<<"////-------------------------------------------\n";
    for(i=0;i<=TW;i++){
        cout<<i<<"\t\t";
        for(j=0;j<=n;j++)
            cout<<Box[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<"Collected Weights : ";
    i = TW ; j = 4;
    while(i>0 || j>0){
        if(Box[i][j] == Box[i][j-1])
            j--;
        else{
            cout<<weight[j] <<" ";
            i = i - weight[j];
        }
    }
    cout<<endl;
    return Box[TW][n];
}
int main()
{
    int n;
    cin>>n;
    int weight[n+2];
    int profit[n+2];
    weight[0] = 0; profit[0] = 0;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>profit[i];
    int Kw;
    printf("\nKnapsack Weight : ");
    cin>>Kw;
    int ans = Knapsack(weight,profit,Kw,n);
    printf("\nMaximum Profit gain : \n");
    cout<<ans<<endl;
    return 0;
}

/*** 
/////Input     
4
2 3
3 4
4 5
5 6

Knapsack Weight : 11

/////Output
Weights         Objects
///             0       1       2       3       4
///--------------------------------------------------
0               0       0       0       0       0
1               0       0       0       0       0
2               0       3       3       3       3
3               0       3       4       4       4
4               0       3       4       5       5
5               0       3       7       7       7
6               0       3       7       8       8
7               0       3       7       9       9
8               0       3       7       9       10
9               0       3       7       12      12
10              0       3       7       12      13
11              0       3       7       12      14

Collected Weights : 5 4 2

Maximum Profit gain :
14

**/



