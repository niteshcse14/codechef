import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
/*
   int numMethod(int num,int n)
   {
      while(num!=0)
       {
          if(num>=2048)
             {
                 num=num-2048;
                 n=n-11;
             }
          if(num>=1024 && num<2048)
             {
                 num=num-1024;
                 n=n-10;
             }
          if(num>=512 && num<1024)
             {
                 num=num-512;
                 n=n-9;
             }
          if(num>=256 && num<512)
             {
                 num=num-256;
                 n=n-8;
             }
          if(num>=128 && num<256)
             {
                 num=num-128;
                 n=n-7;
             }
          if(num>=64 && num<128)
             {
                 num=num-64;
                 n=n-6;
             }
          if(num>=32 && num<64)
             {
                 num=num-32;
                 n=n-5;
             }
          if(num>=16 && num<32)
             {
                 num=num-16;
                 n=n-4;
             }
          if(num>=8 && num<16)
             {
                 num=num-8;
                 n=n-3;
             }
          if(num>=4 && num<8)
             {
                 num=n-4;
                 n=n-2;
             }
          if(num>=2 && num<4)
             {
                 num=num-2;
                 n=n-2;
             }
          if(num>=1 && num<2)
             {
                 num=num-1;
                 n=n-1;
             }
        }
         return n;
   }
   */
   public static void main(String[] args)
   {
     // System.out.println((int)(Math.sqrt(512)));
      Scanner sc=new Scanner(System.in);
     // CC cc=new CC();
      int T,ans;
      T=sc.nextInt();
      while(T>0)
      {
         int n,num,nn;
         num=sc.nextInt();
         n=(int)(Math.sqrt(num));
         if((int)(Math.pow(n,2))==num && num<=1024)
         {
            ans=1;
            System.out.println(ans);
         }
         else
         {
            if((int)(Math.pow(n,2))==num)
            {
               System.out.println(n);
               nn=(int)(Math.sqrt(n));
               ans=(nn-1)/2;
               System.out.println(ans);
            }
            else
            {
               ans=(n+1)/2;
               System.out.println(ans);
            }
         }
         T--;
      }
   }
}
