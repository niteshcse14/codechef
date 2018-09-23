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
         int n,i,j,k,flag=0,l;
         n=sc.nextInt();
         int arr[]=new int[n];
         for(i=0;i<n;i++)
         {
            arr[i]=sc.nextInt();
         }
         for(i=0;i<n;i++)
         {
            for(j=i+1;j<n;j++)
            {
               if(i==j)
                  continue;
               else
               {
                  k=arr[i]*arr[j];
                  for(l=0;l<n;l++)
                  {
                     if(k!=arr[l])
                     {
                        flag++;
                        //break;
                     }
                  }
               }
               if(flag==arr.length)
                  break;
            }
            if(flag==arr.length)
               break;
         }
         if(flag==arr.length)
            System.out.println("no");
         else
            System.out.println("yes");
      }
   }
}
