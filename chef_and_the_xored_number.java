import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] atgs)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int N,i,flag=0,j,len;
         N=sc.nextInt();
         String str=Integer.toBinaryString(N);
         len=str.length();
         for(i=0;i<len;i++)
         {
            if(str.charAt(i)=='0')
            {
               flag=1;
               break;
            }
         }
         if(flag==0)
         {
            if(N==1)
            {
               System.out.println("2");
            }
            else
            {
               System.out.println((int)(Math.pow(2,len-1)-1));
            }
         }
         else
         {
            System.out.println("-1");
         }
      }
   }
}
