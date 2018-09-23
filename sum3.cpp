#include<iostream>
using namespace std;
int main()
{
    int N,i,j,k,l,m,count=0,sum=0;
    cin>>N;
    int arr3[20001],ways[20001],arr[N];
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    j=0;
    cout<<"output"<<endl;
    for(i=0;i<(N-2);i++)
    {
        j=0;
        k=i+1;
        for(j=i+1;j<N;j++)
        {
           cout<<(arr[i]+arr[k]+arr[j+1])<<" k = "<<k<<" arr[i] "<<arr[i]<<" arr[k] "<<arr[k]<<" arr[j] "<<arr[j+1]<<endl;
           
           cout<<(i+j+2)<<" "<<i<<endl;
           if((i+j+2)==(N))
           {
                j=i+1+1;
                k++;
           }
           else if(k==N-2)
           {
                break;
           }
           /* count=0;
            sum=arr[i]+arr[i+1]+arr[j];
            arr3[l]=sum;
            for(m=0;m<sizeof(arr3)/sizeof(int);m++)
            {
                if(arr3[m]==sum)
                {
                    count++;
                }
            }
            ways[l]=count;
            l++;
            */
        }
    }
    /*
    for(i=0;i<l;i++)
    {
        cout<<arr3[i]<<" : "<<ways[i]<<endl;
    }
    */
}
