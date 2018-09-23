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
         int n,i,flag=0,j;
         n=sc.nextInt();
         int arr[]=new int[n],arr_copy[]=new int[100000];
         for(i=0;i<n;i++)
         {
            arr[i]=sc.nextInt();
         }
         for(i=0;i<n;i++)
         {
            for(j=i+1;j<n;j++)
            {
               if(arr[i]==arr[j])
               {
                  flag=j;
                  break;
               }
            }
            if(flag!=0)
               break;
         }
         System.out.println(flag);
      }
   }
}
