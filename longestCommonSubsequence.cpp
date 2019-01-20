#include<bits/stdc++.h>
using namespace std;

void LCS(char *s1,char *s2,int l1,int l2){
    int Box[l1+1][l2+1];
    int i,j;
    for(i=0;i<=l1;i++){
        for(j=0;j<=l2;j++){
            if(i==0 || j==0)
                Box[i][j] =0;
            else if(s1[i-1] != s2[j-1])
                Box[i][j] = max(Box[i-1][j] , Box[i][j-1]);
            else
                Box[i][j] = Box[i-1][j-1] + 1;
        }
    }
    int ans = Box[l1][l2];
    cout<<"Total Characters of Longest Common Subsequence :"<<ans<<endl;
    i = l1 ; j=l2;
    vector<char>v;
    while(1){
        if(i==0 || j==0) break;
        if(Box[i][j] == Box[i-1][j])
            i--;
        else if(Box[i][j] == Box[i][j-1])
            j--;
        else{
            v.push_back(s1[i-1]);
            i--;j--;
        }
    }
    reverse(v.begin(),v.end());
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    char s1[100],s2[100];
    gets(s1);
    gets(s2);
    int l1,l2;
    l1 = strlen(s1);
    l2 = strlen(s2);
    LCS(s1,s2,l1,l2);
    return 0;
}

/*****
INPUT:
    GXTXAYB
    AGGTAB
OUTPUT:
    Total Characters of Longest Common Subsequence :4
    G T A B
*****/
