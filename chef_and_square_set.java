import java.util.*;
import java.io.*;
class CC
{
    public static void main(String[] args)
    {   
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            int N,i,count=0;
            N=sc.nextInt();
            int arr[]=new int[N];
            for(i=0;i<N;i++)
            {
                arr[i]=sc.nextInt();
            }
            
            for(i=0;i<N-1;i++)
            {
                double d=Math.sqrt(arr[i]*arr[i+1]);
                if(d==arr[i])
                {
                    continue;
                }
                else
                {
                    count++;
                }
            }
            
            System.out.println(count);
        }
    }
}
