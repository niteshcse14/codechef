#include<iostream>
using namespace std;
int check_prime_or_not(int n)
{
    int i,flag=0;
    if(n>2)
    {
        for(i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag!=0)
    {
        return 0;
    }
    return 1;
}
int composite_numbers(int n)
{
    int i,k=1,arr[n],arr1[n];
    for(i=0;i<n;i++)
    {
        if(check_prime_or_not(k))
        {
            arr[i]=k;
        }
        else
        {
            i--;
        }
        k++;
    }
    k=0;
    int flag=0,j,N=n;
    for(i=1;;i++)
    {
        int ff=0;
        flag=0;
        if(k==N)
        {
            break;
        }
        if(check_prime_or_not(i) || i<=3 && n!=k)
        {
            arr1[k]=i;
            k++;
            ff++;
            continue;
        }
        else if(i>3)
        {
            flag=0;
            for(j=1;;j++)
            {
                if(i%(arr[j]*arr[j])==0)
                {
                    flag=1;
                    break;
                }
                
                if((arr[j]*arr[j])>i)
                {
                    break;
                }
            }
        }
        if(flag==0 && ff==0)
        {
            arr1[k]=i;
            k++;
        }
    }
    //cout<<"n "<<n<<"k "<<k<<endl;
    
    for(i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    //*/
    cout<<arr1[n-1]<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,i,j,count=0;
        cin>>N;
        composite_numbers(N);
    }
}
