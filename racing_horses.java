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
         int n,i;
         n=sc.nextInt();
         int arr[]=new int[n];
         for(i=0;i<n;i++)
         {
            arr[i]=sc.nextInt();
         }
         Arrays.sort(arr);
         int output=arr[1]-arr[0];
         for(i=0;i<n-1;i++)
         {
            if(output>(arr[i+1]-arr[i]))
               output=arr[i+1]-arr[i];
         }
            System.out.println(output);
      }
   }
}
