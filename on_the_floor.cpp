#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,i,sum=0;
        cin>>N;
        for(i=1;i<=N;i++)
        {
            sum=sum+floor(i/2);
        }
        cout<<sum<<endl;
    }
}
