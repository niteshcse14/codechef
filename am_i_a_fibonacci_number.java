import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      BigInteger[] fiboo=fib(5001);
      Scanner sc=new Scanner(System.in);
      BigInteger n;
      int T=sc.nextInt();
      while(T-->0)
      {
         n=sc.nextBigInteger();
         int res=Arrays.binarySearch(fiboo,n);
         if(res<0)
            System.out.println("NO");
         else
            System.out.println("YES");
      }
   }
   
   public static BigInteger[] fib(int n)
   {
      BigInteger[] fib=new BigInteger[n+1];
      fib[0]=BigInteger.ZERO;
      fib[1]=BigInteger.ONE;
      for(int i=2;i<=n;i++)
      {
         fib[i]=fib[i-1].add(fib[i-2]);
      }
      return fib;
   }
}
