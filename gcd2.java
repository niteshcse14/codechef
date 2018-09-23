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
         BigInteger a,b;
         a=sc.nextBigInteger();
         b=sc.nextBigInteger();
         String str_a=String.valueOf(a),str_b=String.valueOf(a);
         
         while(a.compareTo(b)!=0)
         {
            if(a.compareTo(b)>0)
               a=a.subtract(b);
            else
               b=b.subtract(a);
         }
         System.out.println(a);
      }
   }
}
