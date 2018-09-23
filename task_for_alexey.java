import java.io.*;
import java.util.*;
class CC
{
    private static long calcAlexTask(long a, long b)
    {
        return(a * b) / gcd(a, b);
    }
 
 
    private static long gcd(long a,long b)
    {
        if(b==0)
        {
            return a;
        }
        else
            return gcd(b,a % b);
    }
   public static void main(String[] args)throws Exception
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int N,i,j,flag=0,count;
         N=sc.nextInt();
         int arr[]=new int[N];
         for(i=0;i<N;i++)
         {
            arr[i]=sc.nextInt();
         }
         
         long sum=Long.MAX_VALUE;
         for(i=0;i<N;i++)
         {
            for(j=i+1;j<N;j++)
            {
                sum=Math.min(sum,calcAlexTask((long)arr[i],(long)arr[j]));
            }
         }
         System.out.println(sum);
      }
   }
}
