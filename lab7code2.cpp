#include<bits/stdc++.h>
using namespace std;

void functn(int *coin , int cn , int tk)
{
    int Box[cn+2][tk+2];
    int i,j;
    for(i=0;i<=cn;i++){
        for(j=0;j<=tk;j++){
            if(i>=0 && j==0)
                Box[i][j] = 1;
            else if(i==0)
                Box[i][j] =0;
            else if(coin[i] > j){
                Box[i][j] = 0;
                if(Box[i-1][j] == 1)
                    Box[i][j] = 1;
            }

            else if(coin[i] <= j){
                if(Box[i-1][j-coin[i]] == 1)
                    Box[i][j] = 1;
                else{
                    Box[i][j] = 0;
                    if(Box[i-1][j] == 1)
                        Box[i][j] = 1;
                }

            }
        }
    }
    for(i=0;i<=cn;i++){
        for(j=0;j<=tk;j++)
            cout<<Box[i][j]<<" ";
        cout<<endl;
    }
    if(Box[cn][tk]== 1)
        cout<<"Possible\n";
    else
        cout<<"Not Possible\n";
}
int main()
{
    int cn;
    cout<<"Enter the size of set  : ";
    cin>>cn;
    int coin[cn+2];
    coin[0] = 0;
    cout<<"Enter the coins : \n";
    for(int i=1;i<=cn;i++)
        cin>>coin[i];
    int TK;
    cout<<"Enter the check value : ";
    cin>>TK;
    functn(coin,cn,TK);
    return 0;
}
