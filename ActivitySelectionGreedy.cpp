#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start;
    int End;
};
bool comp(Activity a1, Activity a2){
    return a1.End < a2.End;
}
void GreedyActivities(Activity A[] , int n)
{
    sort(A,A+n,comp);
    int p = 0;
    for(int i=1;i<n;i++){
        if(A[i].start >= A[p].End){
            p = i;
            cout<<A[i].start<<" "<<A[i].End<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    Activity A[n+1];
    for(int i=0;i<n;i++){
        cin>>A[i].start>>A[i].End;
    }
    cout<<"Greedy Selection : \n";
    GreedyActivities(A,n);
    return 0;
}

