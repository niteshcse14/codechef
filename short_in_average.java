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
         int N,M,i,j,k,wt,source,dest;
         N=sc.nextInt();
         M=sc.nextInt();
         
         int arr[][]=new int[N][N];
         
         for(k=0;k<N;k++)
         {
            i=sc.nextInt();
            j=sc.nextInt();
            wt=sc.nextInt();
            arr[i-1][j-1]=wt;
         }
         source=sc.nextInt();
         dest=sc.nextInt();
         for(i=0;i<N;i++)
         {
            for(j=0;j<N;j++)
            {
               System.out.print(arr[i][j]+" ");
            }
            System.out.println();
         }
      }
   }
}
