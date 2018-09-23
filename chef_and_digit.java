import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int n,m,x,i,j,B1,B2;
      n=sc.nextInt();
      m=sc.nextInt();
      int arr[]=new int[n];
      String str=sc.next();
      
      for(i=0;i<n;i++)
      {
         arr[i]=Integer.parseInt(String.valueOf(str.charAt(i)));
      }
         
      while(m-->0)
      {
         B1=0;
         B2=0;
         x=sc.nextInt();
         int b_y[]=new int[x-1];
         for(i=0;i<x-1;i++)
         {
            b_y[i]=arr[x-1]-arr[i];
         }
         
         for(i=0;i<x-1;i++)
         {
            if(b_y[i]>0)
            {
               B1+=b_y[i];
            }
            else
            {
               B2+=b_y[i];
            }
         }
         
         System.out.println(B1-B2);
      }
   }
}
