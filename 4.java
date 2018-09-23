import java.io.*;
import java.util.*;
class GfG
{
    int strstr(String str, String target)
    {
       return str.indexOf(target);
    }
    public static void main(String[] args)
    {
        GfG cfg=new GfG();
        Scanner ss=new Scanner(System.in);
        int i,n;
        n=ss.nextInt();
        String str[]=new String[n],target[]=new String[n];
        for(i=0;i<n;i++)
        {
            str[i]=ss.next();
            target[i]=ss.next();
        }
        for(i=0;i<n;i++)
        {
            String a1=str[i];
            String a2=target[i];
            System.out.println(cfg.strstr(a1,a2));
        }
    }
}

/*
class Greek
{
   public static void main(String[] args) throws Exception
   {
      
      Scanner ss=new Scanner(System.in);
      int i,n=ss.nextInt();
      String str[]=new String[n],str1[]=new String[n];
      for(i=0;i<n;i++)
      {
         str[i]=ss.next();
         str1[i]=ss.next();
         //n--;
      }
      for(i=0;i<n;i++)
      {
         System.out.println(str[i].indexOf(str1[i]));
      }
   }
}
*/
