import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      String N,B,M;
      BigInteger b1,b2,b3;
      int T,i,div,ans,MM;
      T=sc.nextInt();
      while(T>0)
      {
         ans=0;
         i=1;
         N=sc.next();
         B=sc.next();
         M=sc.next();
         MM=M;
         while(N>0)
         {
         if(N%2==0)
         {
            div=N/2;
         }
         else
         {
            div=(N+1)/2;
         }
         M=(int)(Math.pow(MM,i));
         ans=ans+div*M+B;
         N=N-div;
         i++;
         }
         System.out.println(ans-1);
       T--;
      }
   }
}

/*
import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T,N,B,M,i,div,ans,MM;
      T=sc.nextInt();
      while(T>0)
      {
         ans=0;
         i=1;
         N=sc.nextInt();
         B=sc.nextInt();
         M=sc.nextInt();
         MM=M;
         while(N>0)
         {
         if(N%2==0)
         {
            div=N/2;
         }
         else
         {
            div=(N+1)/2;
         }
         M=(int)(Math.pow(MM,i));
         ans=ans+div*M+B;
         N=N-div;
         i++;
         }
         System.out.println(ans-1);
       T--;
      }
   }
}
*/
