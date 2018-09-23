#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int max(int arr[],int n)
{
    int m=arr[0],i=0;
    for(i=0;i<n;i++)
    {
        if(m<arr[i])
        {
            m=arr[i];
        }
    }
    return m;
}

int min(int arr[],int n)
{
    int m=arr[0],i=0;
    for(i=0;i<n;i++)
    {
        if(m>arr[i])
        {
            m=arr[i];
        }
    }
    return m;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,i=0,j=0,ll=0,k=0,mx=0,mn=0,sum=0;
        cin>>N;
        int arr[N];
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        
        int mm=1,z=0;
        
        for(i=0;i<N;i++)
        {
            mm++;
            int arr1[mm];
            for(k=0;k<mm-1;k++)
            {
                arr1[ll]=arr[k];
                ll++;
            }
            for(j=i+1;j<N;j++)
            {
                arr1[ll]=arr[j];
                mx=max(arr1,mm);
                mn=min(arr1,mm);
                sum+=mx-mn;
                for(z=0;z<=ll;z++)
                {
                    cout<<arr1[z]<<" ";
                }
                cout<<endl;
                cout<<"arr1 size "<<ll<<" mm "<<mm<<" for i = "<<i<<" MIN "<<mn<<" MAX "<<mx<<" SUM "<<sum<<endl;
            }
        }
    }
}
