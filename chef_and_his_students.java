import java.util.*;
import java.io.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            String str=sc.next();
            int len=str.length(),i=0,count=0;
            char ch[]=str.toCharArray();
            for(i=0;i<len;i++)
            {
                if(ch[i]=='<')
                {
                    ch[i]='>';
                }
                else if(ch[i]=='>')
                {
                    ch[i]='<';
                }
                else if(ch[i]=='*')
                {
                    ch[i]='*';
                }
            }
            String str1=new String(ch);
            //System.out.println(str1);
            
            char ch1[]=str1.toCharArray();
            
            for(i=0;i<len-1;i++)
            {
                if(ch[i]=='>' && ch[i+1]=='<')
                {
                    count++;
                    i++;
                }
            }
            System.out.println(count);
        }
    }
}
