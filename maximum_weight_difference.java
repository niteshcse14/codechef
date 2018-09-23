import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int n,k,sum=0,sum1=0,i;
         n=sc.nextInt();
         k=sc.nextInt();
         int arr[]=new int[n];
         
         for(i=0;i<n;i++)
         {
            arr[i]=sc.nextInt();
         }
         Arrays.sort(arr);
         if(k>n/2)
            k=n-k;
         for(i=0;i<k;i++)
         {
            sum+=arr[i];
         }
         for(i=k;i<n;i++)
         {
            sum1+=arr[i];
         }
         System.out.println(sum1-sum);
      }
   }
}
