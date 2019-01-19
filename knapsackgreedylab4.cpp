#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int main()
{
    clock_t s = clock();
    int N;
    cin>>N;
    int weight[N+1];
    int profit[N+1];
    int totalWeight =0;
    for(int i=0; i<N; i++)
    {
        weight[i] = rand()%100;
        profit[i] = rand()%100;
        totalWeight += weight[i];
    }
    cout<<"Array of weight : ";
    for(int i=0;i<N;i++)
        cout<<weight[i]<<" ";
    cout<<"Array of profit : ";
    for(int i=0;i<N;i++)
        cout<<profit[i]<<" ";
    cout<<endl<<"After Sorting according to profit : "<<endl;
    int WEIGHT = (totalWeight*70)/100;
    vector<pii>v;
    vector<int>vt;
    for(int i=0;i<N;i++){
        v.pb(mp(profit[i],weight[i]));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        cout<<v[i].first<<"\t"<<v[i].second<<endl;
    }
    cout<<endl;
    int wtgain=0;
    int profit_gain =0;
    for(int i=N-1;i>=0;i--){
        if(v[i].second <= WEIGHT){
            vt.pb(v[i].second);
            wtgain+= v[i].second;
            profit_gain += v[i].first;
            WEIGHT = WEIGHT - v[i].second;
        }
        else
            continue;
    }
    cout<<"Collected weights : "<<endl;
    for(int i=0;i<vt.size();i++)
        cout<<vt[i]<<endl;
    cout<<"Total profit gain = "<<profit_gain<<endl;
    clock_t e = clock();
    cout<<(double)(e-s)/1.80e9<<endl;
    return 0;
}


