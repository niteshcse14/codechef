#include<iostream>
#include<algorithm>
using namespace std;
int N;
bool palindrome(int arr[],int low,int high)
{
    if(high==low)
    {
        return 1;
    }
    int mid=(high-low)/2;
    for(int i=0;i<mid;i++)
    {
        if(arr[low+i]!=arr[high-i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin>>N;
    int a[N],arr[N+1],i,j;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
        arr[i]=N+1;
    }
    arr[N]=0;
    for(i=N-1;i>=0;i--)
    {
        for(j=i;j<N;j++)
        {
            if(a[i]==a[j])
            {
                if(palindrome(a,i,j))
                {
                    arr[i]=min(1+arr[j+1],arr[i]);
                }
            }
        }
    }
    cout<<arr[0]<<endl;
}
