#include<iostream>
#include<stdlib.h>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n,i=0,j=0;
        cin>>n;
        string str;
        cin>>str;
        long long int len=str.size();
        if(len==n)
        {
           /*
            for(i=0;i<str.length();i++)
            {
                if(str[i]=='1')
                {
                    count++;
                }
            }
            */
            
            long long int ans=count(str.begin(),str.end(),'1');//*(count(s.begin(),s.end(),'1')+1);
            cout<<ans/2<<endl;
       }
     }
}
