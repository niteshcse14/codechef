#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sstream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        string str;
        stringstream res;
        res<<N;
        str=res.str();
        int count=0,i=0,len=0;
        for(i=0;i<str[i]!='\0';i++)
        {
            len++;
        }
       // cout<<len<<endl;
        for(i=0;i<len;i++)
        {
            if(str[i]=='4')
            {
                //count++;
            }
            else if(str[i]=='7')
            {
                
            }
            else
            {
                count++;
            }
            //cout<<(str[i])<<" ";
        }
        cout<<count<<endl;
    }
}
