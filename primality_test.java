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
         int n,flag=0,i;
         n=sc.nextInt();
         for(i=2;i<n/2;i++)
         {
            if(n%i==0)
            {
               flag=1;
               break;
            }
         }
         if(flag!=1)
            System.out.println("yes");
         else
            System.out.println("no");
     }
   }
}
