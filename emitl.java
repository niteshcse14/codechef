import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        while(T-->0)
        {
            int i;
            String str=sc.next(),str1="";
            for(i=(str.length()-1);i>=0;i--)
            {
                str1+=String.valueOf(str.charAt(i));
            }
            
            System.out.println(str+"   "+str1);
        }
    }
}
