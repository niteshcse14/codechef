import java.io.*;
import java.util.*;
class Code
{
   public static void main(String[] args) throws Exception
   {
      Scanner ss=new Scanner(System.in);
      int i;
      int n=ss.nextInt();
      String str;
      while(n>0)
      {
         int j=0;
         int k=0;
         str=ss.next();
         int len=str.length();
         for(i=0;i<len;i++)
         {
            if(str.charAt(i)=='1')
            {
               j++;
              // System.out.println("j= "+j);
            }
            else
            {
               k++;
              // System.out.println("k= "+k);
            }
         }
         if(j==1 || k==1)
         {
            System.out.println("Yes");
         }
         else
         {
            System.out.println("No");
         }
         n--;
      }
      
       
   }
}
