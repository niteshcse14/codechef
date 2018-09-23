import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int i,j,k,t,temp,max,n;
      //BigInteger 
      n=sc.nextInt();
      String arr[]=new String[n],sec_arr[]=new String[n],out_arr[]=new String[n];
      for(i=0;i<n;i++)
      {
         arr[i]=sc.next();
         sec_arr[i]=String.valueOf(i+1);
      }
      temp=n;
      t=0;
      while(temp>0)
      {
         for(i=0;i<n;i++)
         {
            out_arr[i]=arr[i]+sec_arr[(t+i)%n];
         }
         t++;
         temp--;
      }
   }
}
