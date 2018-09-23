import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] arg)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int size,i,j,temp,k,l;
         size=sc.nextInt();
         int arr[]=new int[size],out_arr[]=new int[size];
         for(i=0;i<size;i++)
         {
            arr[i]=sc.nextInt();
         }
         Arrays.sort(arr);
         for(i=0,k=size-1,l=0;i<size;i++)
         {
               if((i+1)%2==0)
               {
                  out_arr[i]=arr[k];
                  k--;
               }
               else
               {
                  out_arr[i]=arr[l];
                  l++;
               }
           System.out.print(out_arr[i]+" ");
         }
         System.out.println();
      }
   }
}
