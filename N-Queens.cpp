#include<bits/stdc++.h>
using namespace std;
int col[10];
int isSafe(int n , int mr , int mc)
{
    int p=1,q=1;
    for(int cr = 1;cr<=mr;cr++){
        if(col[cr] == mc){
            p = 0; break;
        }
    }
    for(int cr =1;cr<=mr;cr++){
        if(abs(col[cr] - mc) == abs(cr - mr)){
            q = 0; break;
        }
    }
    if(p==1 && q==1)
        return 1;
    else
        return 0;
}
int main()
{
    int n,c=1;
    cout<<"Enter the value of n : ";
    cin>>n;
    stack<int>st;
    int r=2; col[1] = 1;
    st.push(1);
    while(r<(n+1)){
        int check = 0;
        for( ;c<=n;c++){
            if(isSafe(n,r,c) == 1){
                st.push(c); col[r]=c;r++; c=1;check = 1;
                break;
            }
        }
        if(check==0){
            c = st.top() + 1 ;
            r--; col[r] = 0; st.pop();
            if(c>n){
                c= st.top() + 1 ; r--;  col[r]=0; st.pop();
            }
        }
    }
    cout<<"\nRow\tColumn\n";
    for(r=1;r<=n;r++)
        cout<<r<<"\t"<<col[r]<<endl;
    return 0;
}
/***
Input
======
Enter the value of n : 4

Output
======

Row     Column
1       2
2       4
3       1
4       3
***/
