import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
         int node,edge,k=0,i,j,wt;
         node=sc.nextInt();
         int A[][]=new int[node][node];
         
         for(i=0;i<node;i++)
         {
            for(j=0;j<node;j++)
            {
               A[i][j]=100000007;
            }
         }
         
         edge=sc.nextInt();
         for(i=0;i<edge;i++)
         {
            j=sc.nextInt();
            k=sc.nextInt();
            wt=sc.nextInt();
            if(j!=0 && k!=0)
            {
               A[j-1][k-1]=A[k-1][j-1]=wt;
            }
         }
         
         
         for(i=0;i<node;i++)
         {
            A[i][i]=0;
         }
         for(k=0;k<node;k++)
         {
            for(i=0;i<node;i++)
            {
               for(j=0;j<node;j++)
               {
                  if(A[i][k]+A[k][j]<A[i][j])
                  {
                     A[i][j]=A[i][k]+A[k][j];
                  }
               }
            }
         }
         int output=A[0][0];
         for(i=0;i<node;i++)
         {
            for(j=0;j<node;j++)
            {
               output=Math.max(output,A[i][j]);
            }
         }
         System.out.println(output);
   }
}
