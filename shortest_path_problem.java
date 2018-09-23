import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int NN,N,M,i,j;
      NN=sc.nextInt();
      while(NN!=0)
      {
         N=NN;//sc.nextInt();
         M=sc.nextInt();
         int arr[][]=new int[N][M];
         for(i=0;i<N;i++)
         {
            for(j=0;j<M;j++)
            {
               arr[i][j]=sc.nextInt();
            }
         }
         
         
         
         
         NN=sc.nextInt();
      }
   }
}
