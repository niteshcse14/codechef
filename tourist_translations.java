import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T,i,len,index=0;
      String S,in;
      T=sc.nextInt();
      S=sc.next();
      char small_ch[]=S.toCharArray();
      char caps_ch[]=new char[26];
      for(i=0;i<26;i++)
      {
         caps_ch[i]=(char)(((int)small_ch[i])-32);
      }
      while(T-->0)
      {
         in=sc.next();
         len=in.length();
         char input[]=in.toCharArray();
         for(i=0;i<len;i++)
         {
            if((int)(input[i])>64 && (int)(input[i])<91)
            {
               index=(int)(input[i]);
               input[i]=(char)(((int)small_ch[index-65])-32);
            }
            else if((int)(input[i])>96 && (int)(input[i])<123)
            {
               index=(int)(input[i]);
               input[i]=small_ch[index-97];
            }
            else if(input[i]=='_')
            {
               input[i]=' ';
            }
            else
            {
               input[i]=input[i];
            }
            
            System.out.print(input[i]);
         }
         System.out.println();
      }
   }
}
