///Given a set of coins and a value(tk) . Find if it's possible to change the the given value with the coins of given set....

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

/*****
///Input
Enter the size of set  : 3
Enter the coins :
2 3 4
Enter the check value : 8

///Output

1 0 0 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0
1 0 1 1 0 1 0 0 0
1 0 1 1 1 1 1 1 0
Not Possible

******/
