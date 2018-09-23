import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T,gcd;
      T=sc.nextInt();
      while(T>0)
      {
         int A,B;
         A=sc.nextInt();
         B=sc.nextInt();
         while(A!=B)
         {
            if(A>B)
               A=A-B;
            else
               B=B-A;
         }
         gcd=A;
         System.out.println(A+" "+(A*B)/gcd);
        T--;
      }
   }
}
