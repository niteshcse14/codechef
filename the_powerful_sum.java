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
          BigInteger n,p,sum=new BigInteger("0"),b_i;
          int k,i,r=2;
          n=sc.nextBigInteger();
          k=sc.nextInt();
          p=sc.nextBigInteger();
          /*
          for(i=1;i<=n.intValue();i++)
          {
             b_i=new BigInteger(Integer.toString(i));
             sum=(sum.add((b_i).pow(k))).mod(p);
          }
          */
          System.out.println();
      }
   }
}
