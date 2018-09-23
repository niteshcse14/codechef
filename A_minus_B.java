import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int A,B,sub=0;
      A=sc.nextInt();
      B=sc.nextInt();
      
      sub=A-B;
      if(sub%10<9)
      {
         sub++;
      }
      else
      {
         sub--;
      }
      System.out.println(sub);
   }
}
