import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,i,j,max=0,val;
      N=sc.nextInt();
      int arr[]=new int[N];
      for(i=0;i<N;i++)
      {
         arr[i]=sc.nextInt();
      }
      for(i=0;i<N;i++)
      {
         for(j=i;j<N;j++)
         {
            if(i==j)
            {
               continue;
            }
            if(i==0 && j==1)
            {
               val=arr[i]&arr[j];
               max=val;
            }
            else
               val=arr[i]&arr[j];
            //max=arr[0];
            if(max<val)
            {
               max=val;
            }
         }
      }
      System.out.println(max);
   }
}
