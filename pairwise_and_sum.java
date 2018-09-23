import java.util.*;
import java.io.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,i,sum,j,val;
      N=sc.nextInt();
      int arr[]=new int[N];
      for(i=0;i<N;i++)
      {
         arr[i]=sc.nextInt();
      }
      sum=0;
      for(i=0;i<N;i++)
      {
         for(j=i;j<N;j++)
         {
            if(i==j)
               continue;
            val=arr[i]&arr[j];
            sum=sum+val;
         }
      }
      System.out.println(sum);
   }
}
