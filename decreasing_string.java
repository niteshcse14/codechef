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
         int pos,temp=0,i=0,rem,p,j;
         String str;
         char ch;
         pos=sc.nextInt();
         rem=pos%25;
         p=pos/25;
         if(rem!=0)
         {
           while(rem!=-1)
            {
                  ch=(char)(97+rem);
                  System.out.print(ch);
                  //i++;
                  rem--;
            }
         }
         for(i=0;i<p;i++)
         {
            for(j=25;j>=0;j--)
            {
               ch=(char)(97+j);
               System.out.print(ch);
            }
         }
         System.out.println();
      }
   }
}
