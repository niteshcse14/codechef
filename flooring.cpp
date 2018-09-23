#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,i,sum=0;
        cin>>N>>M;
        for(i=1;i<=N;i++)
        {
            sum=sum+pow(i,4)*floor(N/i);
            sum=sum%M;
        }
        cout<<sum<<endl;
    }
}
