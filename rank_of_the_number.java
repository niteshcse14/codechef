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
         int n,len,i,j,rem=0,k=1;
         n=sc.nextInt();
         len=String.valueOf(n).length();
         int arr[]=new int[len];
         for(i=0;i<len;i++)
         {
            rem=n%10;
            arr[i]=rem;
            n=n/10;
         }
         Arrays.sort(arr);
         for(i=0;i<len;i++)
         {
            k=1;
            System.out.print(arr[i]);
            for(j=0;j<len-1;j++)
            {
               System.out.print(arr[(k+i)%len]);
               k++;
            }
            System.out.println();
         }
      }
   }
}
