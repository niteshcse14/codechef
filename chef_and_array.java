import java.util.*;
import java.io.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,M,x,y,j,i=0,max=0,sum=0,max_x_y=0,min_x_y=0;
      N=sc.nextInt();
      int arr[]=new int[N];
      for(i=0;i<N;i++)
      {
         arr[i]=sc.nextInt();
      }
      M=sc.nextInt();
      x=sc.nextInt();
      y=sc.nextInt();
      sum=0;
      while(M-->0)
      {
         if(i>0)
         {
            x=(x+7)%(N-1);
            y=(y+11)%N;
         }
         if(x>y)
         {
            max_x_y=x;
            min_x_y=y;
         } 
         else if(y>x)
         {
            max_x_y=y;
            min_x_y=x;
         }
         else if(x==y)
         {
            max_x_y=min_x_y=x=y;
         }
         max=arr[x]; q
         for(j=min_x_y;j<=max_x_y;j++)
         {
            if(max<arr[j])
               max=arr[j];
         }
         sum=sum+max;
         i++;
      }
      System.out.println(sum);
   }
}
