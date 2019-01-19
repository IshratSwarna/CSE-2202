#include<bits/stdc++.h>
using namespace std;

void QuickSort(int data[] , int first , int last)
{
    int pivot,left,right;
    if(first<last){
        pivot = first;
        left = first;
        right = last;
        while(left < right){
            while(data[left]<=data[pivot] && left<last)
                left++;
            while(data[right]>data[pivot])
                right--;
            if(left<right)
                swap(data[left],data[right]);
        }
        swap(data[pivot],data[right]);
        QuickSort(data,first,right-1);
        QuickSort(data,right+1,last);
    }
}

int main()
{
    int Telement ;
    cin>>Telement;
    int data[Telement+1];
    for(int i=0;i<Telement;i++)
        cin>>data[i];

    QuickSort(data,0,Telement-1);

    for(int i=0;i<Telement;i++)
        cout<<data[i]<<" ";
    return 0;
}
