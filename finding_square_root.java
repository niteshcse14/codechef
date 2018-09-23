import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T>0)
      {
         int n;
         n=sc.nextInt();
         double dd=Math.sqrt(n);
         System.out.println((int)dd);
         T--;
      }
   }
}
