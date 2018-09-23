import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int i,j,count,ss,jj;
         String S,J;
         S=sc.next();
         J=sc.next();
         
         ss=S.length();
         jj=J.length();
         
         count=0;
         for(i=0;i<jj;i++)
         {
            for(j=0;j<ss;j++)
            {
               if((int)(S.charAt(j))==(int)(J.charAt(i)))
               {
                  count++;
                  break;
               }
            }
         }
         System.out.println(count);
      }
   }
}
