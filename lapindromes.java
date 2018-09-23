import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int n,i=0,j=0,k=0,kk=0,count,l,m,x,len;
      n=sc.nextInt();
      
      while(n-->0)
      {   
         String str;
         str=sc.next();
         len=str.length();
         int sum=0,sum1=0,flag=0;
         String s1="",s2="";
         int count1[]=new int[26];
         int count2[]=new int[26];
         //char ch[]=new char[len/2],ch1[]=new char[len/2];
         if(len%2==0)
         {
               s1=str.substring(0,len/2);
               s2=str.substring(len/2,len);
               
               char ch[]=s1.toCharArray();
               Arrays.sort(ch);
                 
               char ch1[]=s2.toCharArray();
               Arrays.sort(ch1);
                 
               for(i=0;i<len/2;i++)
                 {
                     if(ch[i]==ch1[i])
                        continue;
                     else
                     {
                        flag=1;
                        System.out.println("NO");
                        break;
                     }
                 }
                /* 
               for(j=0;j<s1.length();j++)
               {
                   sum+=(int)(s1.charAt(j));
               }
                 
               for(j=0;j<s2.length();j++)
               {
                   sum1+=(int)(s2.charAt(j));
               }
               
               if(sum==sum1)
               {
                     System.out.println("YES");
               }
               else
               {
                     System.out.println("NO");
               }
               */
            }
            else
            {
                 s1=str.substring(0,len/2);
                 s2=str.substring((len/2)+1,len);
                 char ch[]=s1.toCharArray();
                 Arrays.sort(ch);
                 
                 char ch1[]=s2.toCharArray();
                 Arrays.sort(ch1);
                 
                 for(i=0;i<len/2;i++)
                 {
                     if(ch[i]==ch1[i])
                        continue;
                     else
                     {
                        flag=1;
                        System.out.println("NO");
                        break;
                     }
                 }
                 /*
                 for(j=0;j<s1.length();j++)
                 {
                     sum+=(int)(s1.charAt(j));
                 }
                 
                 for(j=0;j<s2.length();j++)
                 {
                     sum1+=(int)(s2.charAt(j));
                 }
               
                 if(sum==sum1)
                 {
                    System.out.println("YES");
                 }
                 else
                 {
                    System.out.println("NO");
                 }
                 
                 */
            
         }
         if(flag!=1)
            System.out.println("YES");
      }
   }
}
