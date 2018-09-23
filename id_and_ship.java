import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T,len;
      String ch1;
      char ch;
      T=sc.nextInt();
      while(T>0)
      {
         ch1=sc.next();
         len=ch1.length();
         if(ch1.equals("B") || ch1.equals("b") && len==1)
         {
            System.out.println("BattleShip");
         }
         else if(ch1.equals("C") || ch1.equals("c") && len==1)
         {
            System.out.println("Cruiser");
         }
         else if(ch1.equals("D") || ch1.equals("d") && len==1)
         {
            System.out.println("Destroyer");
         }
         else if(ch1.equals("F") || ch1.equals("f") && len==1)
         {
            System.out.println("Frigate");
         }
         else
         {
            System.out.println("Error");
         }
         T--;
      }
   }
}
