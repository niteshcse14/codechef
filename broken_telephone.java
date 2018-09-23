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
         int N,i,count=0;
         N=sc.nextInt();
         int arr[]=new int[N];
         for(i=0;i<N;i++)
         {
            arr[i]=sc.nextInt();
         }
         int first=arr[0];
         for(i=0;i<N;i++)
         {
            if(first==arr[i])
            {
               count++;
            }
         }
         if(count==N)
            System.out.println(count);
      }
   }
}
