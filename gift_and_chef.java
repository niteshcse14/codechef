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
         String S,F;
         int len_S,len_F,i,j=0,k=0;
         BigInteger b=new BigInteger("1"),count=new BigInteger("0"),one=new BigInteger("-1"),seven=new BigInteger("7"),sub;
         S=sc.next();
         F=sc.next();
         
         len_S=S.length();
         len_F=F.length();
         
         char ch[]=new char[len_F];
         
         for(i=0;i<len_S;i++)
         {
            
            
            if((int)(S.charAt(i))==(int)(F.charAt(j)))
            {
               ch[j]=F.charAt(j);
               j++;
            }
            else
            {
               j=0;
            }
            if(F.equals(String.valueOf(ch)))
            {
               j=0;
               count=count.add(b);
               ch[len_F-1]='\0';
               i--;
            }
            
         }
         BigInteger res,b1=new BigInteger("10");
         res=(count.add((count.add(one)))).mod((b1.pow(9).add(seven)));
         System.out.println(res);
      }
   }
}
