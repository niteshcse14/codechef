import java.io.*;
import java.util.*;
class CC 
{
   public static void main(String args[])
   {
      Scanner sc=new Scanner(System.in);
           
      int T;
      T=sc.nextInt();
      while(T>0)
      {
         String A,B,s1,s2;
         A=sc.next();
         B=sc.next();
         StringBuffer sb,sb1;
         sb = new StringBuffer(A); 
         sb1=new StringBuffer(B);
         sb.reverse();
         sb1.reverse();
         s1=String.valueOf(sb);
         s2=String.valueOf(sb1);
         if(s1.equals(A))
         {
            System.out.println("Yes");
         }
         else if(s2.equals(B))
         {
            System.out.println("Yes");
         }
         else
         {
            System.out.println("No");
         }
         T--;
      }
   }  
}
