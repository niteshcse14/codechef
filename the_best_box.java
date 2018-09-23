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
         int P,S;
         double x,x1,x2,v1,v2;
         P=sc.nextInt();
         S=sc.nextInt();
         x1=(P+Math.sqrt((P*P-24*S)))/12;
         x2=(P-Math.sqrt((P*P-24*S)))/12;
         v1=x1*x1*((P-8*x1)/4);
         v2=x2*x2*((P-8*x2)/4);
         if(v1>v2)
            System.out.printf("%.2f\n",v1);
         else
            System.out.printf("%.2f\n",v2);
         
         
      }
   }
}
