import java.io.*;
import java.util.*;
import java.math.*;
class Algo
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int i,j,n,m,flag=0;
      String str,str1;
      str=sc.next();
      str1=sc.next();
      n=str.length();
      m=str1.length();
      j=0;
      for(i=0;i<n;i++)
      {
         if((int)(str.charAt(i))==(int)(str1.charAt(j)))
         {
            j++;
            if(j==m)
            {
               flag=1;
               break;
            }
            continue;
         }
         j=0;
      }
      if(flag==1)
      {
         System.out.println("Goog");
      }
      else
      {
         System.out.println("Bad");
      }
   }
}
