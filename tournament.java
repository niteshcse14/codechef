import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,i,j=0,sum=0,t=1;
        N=sc.nextInt();
        int arr[]=new int[N];
        int arr1[]=new int[N-1],arr2[]=new int[N-1];
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        for(i=1;i<N;i++)
        {
            arr2[i-1]=arr[i-1]*(N-i);
        }
        while(t<N)
        {
            sum=0;
            for(i=t;i<N;i++)
            {
                sum+=arr[i];
            }
            arr1[t]=sum;
            //j++;
            t++;
        }
        sum=0;
        for(i=0;i<N-1;i++)
        {
            sum+=Math.abs(arr2[i]-arr1[i]);
        }
        System.out.println(sum);
    }
}
