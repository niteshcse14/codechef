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
         BigInteger b_N=sc.nextBigInteger(),one=new BigInteger("1"),two=new BigInteger("2");
         System.out.println((b_N.multiply(b_N.subtract(one))).divide(two));
      }
   }
}
