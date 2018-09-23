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
         int i,j,len,count;
         String str=sc.next();
         len=str.length();
         char ch[]=str.toCharArray();
         int arr[]=new int[26];
         for(i=0;i<len;i++)
         {
            arr[(int)ch[i]-97]=1;
         }
         count=0;
         for(i=0;i<26;i++)
         {
            if(arr[i]==1)
               count++;
         }
         System.out.println(count);
      }
   }
}
