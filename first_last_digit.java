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
         int n=0,n1=0,n2=0,n3=0,len=0;
         String str;
         n=sc.nextInt();
         str=String.valueOf(n);
         len=str.length();
         n1=(int)(str.charAt(0))-48;
         n2=(int)(str.charAt(len-1))-48;
         n3=n1+n2;
         System.out.println(n3);
         T--;
      }
   }
}
