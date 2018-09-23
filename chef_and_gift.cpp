#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,i=0,j=0,count=0;
        cin>>n>>k;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%2==0)
            {
                count++;
            }
        }
        if(count==n && k==0)
        {
            cout<<"NO"<<endl;
        }
        else if(count>=k)
        {
            cout<<"YES"<<endl;
        }        
        else 
        {
            cout<<"NO"<<endl;
        }
    }
}
