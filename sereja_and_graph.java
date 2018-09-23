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
         int n,m,i=0,j=0,k=0,flag=0;
         n=sc.nextInt();
         m=sc.nextInt();
         int arr[][]=new int[n][n];
         
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
               arr[i][j]=0;
            }
         }
         
         for(k=0;k<m;k++)
         {
            i=sc.nextInt();
            j=sc.nextInt();
            
            arr[i-1][j-1]=arr[j-1][i-1]=arr[i-1][j-1]+1;
         }
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
               System.out.print(arr[i][j]+" ");
            }
            System.out.println();
         }
         
         for(i=0;i<n;i++)
         {
            if(arr[i][0]>1)
            {
               flag=1;
               break;
            }
         }
         if(flag==1)
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
