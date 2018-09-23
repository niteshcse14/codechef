#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,i,j,temp=0,sum=0,sum1=0;
        cin>>N;
        int arr[N];
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<N;i++)
        {
            for(j=i;j<N;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        sum=0;
        while(true)
        {
            if(sum<sum1)
            {
                sum+=arr[0];
            }
            else
            {
                sum1+=arr[1];
            }
            if(sum==sum1)
            {
                break;
            }
        }
        cout<<sum<<endl;;
    }
}
