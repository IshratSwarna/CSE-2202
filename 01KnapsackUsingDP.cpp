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
    return Box[TW][n];
}
int main()
{
    int n;
    cin>>n;
    int weight[n+2];
    int profit[n+2];
    weight[0] = 0; profit[0] = 1;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>profit[i];
    int Kw;
    printf("\nKnapsack Weight : ");
    cin>>Kw;
    int ans = Knapsack(weight,profit,Kw,n);
    printf("\nMaximum Profit gain : ");
    cout<<ans<<endl;
    return 0;
}

/*** Input                  Output
4                           Maximum Profit gain : 14
2 3
3 4
4 5
5 6

Knapsack Weight : 11
**/



