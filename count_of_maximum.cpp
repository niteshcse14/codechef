#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,arr[10001]={0},arr1[10001]={0},arr2[10001]={0},arr3[10001]={0},i=0,j=0,k=0,count=0,min=0,max=0;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<N;i++)
        {
            count=0;
            for(j=0;j<N;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                }
            }
            arr2[i]=count;
        }
        max=arr2[0];
        for(i=0;i<N;i++)
        {
            if(max<arr2[i])
            {
                max=arr2[i];
            }
        }
        for(i=0;i<N;i++)
        {
            if(max==arr2[i])
            {
                arr3[k]=arr[i];
                k++;
            }
        }
        int arr4[k];
        for(i=0;i<k;i++)
        {
            arr4[i]=arr3[i];
        }
        min=arr4[0];
        for(i=0;i<k;i++)
        {
            if(min>arr4[i])
            {
                min=arr4[i];
            }
        }
        cout<<min<<" "<<max<<endl;
    }
}
