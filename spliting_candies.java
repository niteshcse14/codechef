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
         long N,K;
         N=sc.nextLong();
         K=sc.nextLong();
         if(K!=0)
            System.out.println((N/K)+" "+(N%K));
         else
            System.out.println("0 "+N);
      }
   }
}
