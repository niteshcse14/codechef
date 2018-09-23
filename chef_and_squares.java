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
         int i,j,k,K,ii,jj;
         K=sc.nextInt();
         ii=jj=(K+1)/2;
         ii=ii-1;
         jj=jj-1;
         int arr[][]=new int[K][K];
         if(K>1)
         {
            for(i=0;i<K;i++)
            {
               k=1;
               for(j=i;k<K;j--)
               {
                  if(i==j)
                  {
                     arr[i][j]=K;
                  }
                  else
                  {
                     if(j<0)
                     {
                        j=K-1;
                     }
                     arr[i][j]=k;
                     k++;
                  }
               }
            }
         }
         for(i=0;i<K;i++)
         {
            for(j=0;j<K;j++)
            {
               System.out.print(arr[i][j]+" ");
            }
            System.out.println();
         }
      }
   }
}
