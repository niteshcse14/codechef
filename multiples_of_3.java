import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,Q,n,A,B,count,i,j;
      N=sc.nextInt();
      Q=sc.nextInt();
      int arr[]=new int[N];
      for(i=0;i<Q;i++)
      {
         n=sc.nextInt();
         A=sc.nextInt();
         B=sc.nextInt();
         count=0;
         if(n==0)
         {
            for(j=A;j<=B;j++)
            {
               arr[j]=arr[j]+1;
            }
         }
         else if(n==1)
         {
            for(j=A;j<=B;j++)
            {
               if(arr[j]%3==0)
                  count++;
            }
         }
         else
         {
            System.out.println("Invalid");
         }
         
         if(n==1)
            System.out.println(count);
      }
   }
}
