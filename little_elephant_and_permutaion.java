import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int N,i,j;
         N=sc.nextInt();
         int arr[]=new int[N];
         for(i=0;i<N;i++)
         {
            arr[i]=sc.nextInt();
         }
      int number_of_invertion=0,number_of_local_invertion=0;
         for(i=0;i<N-1;i++)
         {
            for(j=i+1;j<N;j++)
            {
               if(arr[i]>arr[j])
               {
                  number_of_invertion++;
               }
            }
            if(arr[i]>arr[i+1])
            {
               number_of_local_invertion++;
            }
         }
         
         if(number_of_invertion==number_of_local_invertion)
         {
            System.out.println("YES");
         }
         else
         {
            System.out.println("NO");
         }
      }
   }
}
