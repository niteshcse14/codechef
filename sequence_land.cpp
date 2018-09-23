#include<iostream>
using namespace std;
int main()
{
    long long int N,K,ans=1,ii=0,i,j,flag=0,count=0;
    cin>>N>>K;
    if(N>=1 && K>=1)
    {
        long long int arr0[1000000];
        long long int p,res_p;
        cin>>p;
        long long int arr[p];
        for(i=0;i<p;i++)
        {
            cin>>arr[i];
        }
        N--;
        
        while(N--)
        {
            count=0;
            flag=0;
            cin>>res_p;
            long long int arr1[res_p];
            for(i=0;i<res_p;i++)
            {
                cin>>arr1[i];
            }
         
            
            for(i=0;i<p;i++)
            {
                for(j=0;j<res_p;j++)
                {
                    if(arr[i]==arr1[j])
                    {
                        count++;
                    }
                }
                if(count>=K)
                {
                    ans++;
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                }
            }
                   
            if(flag==1)
            {
                p=res_p;
                arr[p];
                for(i=0;i<p;i++)
                {
                    arr[i]=arr1[i];
                    //ii++;
                }
            }
            /*
            cout<<"flag = "<<flag<<" ans = "<<ans<<endl;  
            for(i=0;i<p;i++)
            {
                cout<<arr[i]<<" ";
            }         
            cout<<endl;
           */   
         }
        cout<<ans<<endl;
    }
}
