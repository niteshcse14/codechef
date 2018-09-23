import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,flag=0,i;
      N=sc.nextInt();
      int arr[]=new int[N];
      for(i=0;i<N;i++)
         arr[i]=sc.nextInt();
      
      for(i=0;i<N-3;i++)
      {
         int a=arr[i],b=arr[i+1],c=arr[i+2],d=arr[i+3];
         int ff=(((a^b)^c)^d);
         if(ff==0)
         {
            flag=1;
            break;
         }
      }
      if(flag==1)
      {
         System.out.println("Yes");
      }
      else
      {
         System.out.println("No");
      }
   }
}
