import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   int last_prime_Number(int n)
   {
      int i,j,ans=0,flag=1;
      for(j=n;j>0;j--)
      {
         for(i=2;i<j/2;i++)
         {
            if((j-1)%i==0)
            {
               flag=0;
               break;
            }
            else
            {
               flag=1;
               continue;
            }
         }
         if(flag==1)
         {
            j=j-ans;
            ans++;//=j;
            
         }
      }
      return ans;
   }
   public static void main(String[] args)
   {
      CC c=new CC();
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int N,count=0,prime,i,j;
         N=sc.nextInt();
         prime=0;
         if(N>2)
         {
            prime=c.last_prime_Number(N);
         }
         else if(N==2)
            prime=0;
         else if(N==1)
            prime=1;
         if(prime%2==0)
         {
            System.out.println("BOB");
         }
         else
         {
            System.out.println("ALICE");
         }
         
      }
      
   }
}
