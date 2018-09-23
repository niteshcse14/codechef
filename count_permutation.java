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
         int N,i,j,count=0;
         N=sc.nextInt();
         int P[]=new int[N];
         P[0]=1;
         for(i=1;i<N;i++)
         {
            P[i]=i+1;
         }
         for(i=0;i<N;i++)
         {
            System.out.print(P[i]+" ");
         }
         System.out.println();
         for(i=1;i<N-1;i++)
         {
            for(j=2;j<=i;j++)
            {
               if(P[j]>P[j+1] && P[j]>P[j-1])
               {
                  count++;
               }
            }
         }
         System.out.println(count);
      }
   }
}
