#include<iostream>
using namespace std;
int main()
{
    long long int T;
    cin>>T;
    while(T--)
    {
        long long int A,N,sum=0,i=0,flag=0;
        cin>>A>>N;
        while(true && A>0 && N>0 && sum<=N)
        {
            sum+=A;
            i++;
            if(sum==(N+1))
            {
                flag=1;
                break;
            }
            else if(sum>(N+1))
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<i<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
}
