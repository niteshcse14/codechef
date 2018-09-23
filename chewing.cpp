#include<iostream>
using namespace std;
int main()
{
    long long int N,K=0,k=0,i,j,count=0;
    cin>>N>>K;
    long long int arr[N],arr1[N];
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        if(arr[i]<K)
        {
            arr1[k]=arr[i];
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
             if((arr1[i]+arr1[j])<K)
             {
                 count++;
             }
        }
    }
    cout<<count<<endl;
}
