import java.io.*;
import java.util.*;
class CC
{
   int same(int arr[],int N)
   {
      int i,count=0;
      for(i=1;i<N;i++)
      {
         if(arr[i]==arr[0])
         {
            count++;
         }
         else
         {
            break;
         }
      }
      if(count==N-1)
         return 1;
      else
         return 0;
   }
   public static void main(String[] args)
   {
      CC c=new CC();
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int N,flag=0,i,j,max,sum,min,sub;
         N=sc.nextInt();
         int arr[]=new int[N];
         for(i=0;i<N;i++)
            arr[i]=sc.nextInt();
            
         Arrays.sort(arr);
         
         min=arr[0];
         max=arr[N-1];
         flag=c.same(arr,N);
         
         if(flag==1)
         {
            System.out.println(min);
         }
         else
         {
            while(flag!=1)
            {
               sub=arr[N-1]-arr[N-2];
               arr[N-1]=sub;
               Arrays.sort(arr);
               flag=c.same(arr,N);
            }
            System.out.println(arr[0]);
         }
         
      }
   }
}
