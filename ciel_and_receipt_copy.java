import java.io.*;
import java.util.*;
class CC
{
   int receipt(int num)
   {
      int count=0,i=11,temp;
      temp=num;
      while(num!=0)
      {
         if(num>=2048)
         {
            i=12;
         }
         if(num>=(int)(Math.pow(2,i)) && i>=0)
         {
            num=num-(int)(Math.pow(2,i));
            System.out.println(i+"  "+num);
            count++;
         }
         i--;
      }
      return count;
   }
   public static void main(String[] args)
   {
      CC cc=new CC();
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T>0)
      {
         int num,n;
         num=sc.nextInt();
         n=cc.receipt(num);
         System.out.println(n);
         T--;
      }
   }
}
