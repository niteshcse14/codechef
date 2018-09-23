#include<iostream>
#include<string.h>
using namespace std;
int check(char a[])
{
    long int i,count=0;
    for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='T')
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count<0)
            {
                return 0;
            }
        }
        if(count==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[100001];
        cin>>str;        
        if(check(str))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}
