import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,Q,i;
        N=sc.nextInt();
        Q=sc.nextInt();
        String str=sc.next();
        
        while(Q-->0)
        {
            int q,L;
            String ch,ch1="",ch2="";
            q=sc.nextInt();
            L=sc.nextInt();
            
            if(q==1)
            {
                ch=sc.next();
                
                for(i=0;i<N;i++)
                {
                    if(i==L-1)
                    {
                        ch2+=ch.charAt(0);
                    }
                    else
                    {
                        ch2+=str.charAt(i);
                    }
                }
                str=ch2;
            }
            if(q==2)
            {
                int R,count=0;
                int arr[]=new int[26];
                R=sc.nextInt();
                
                for(i=L-1;i<R;i++)
                {
                    ch1+=str.charAt(i);
                }
                //System.out.println("2 ch1 = "+ch1);
                for(i=0;i<ch1.length();i++)
                {
                    arr[(int)ch1.charAt(i)-97]=arr[(int)ch1.charAt(i)-97]+1;
                }
        
                for(i=0;i<26;i++)
                {
                    if(arr[i]%2==1)
                    {
                        count++;
                    }
                }
        
                if(count==1 || count==0)
                {
                    System.out.println("yes");
                }
                else
                {
                    System.out.println("no");
                }
            }
            //System.out.println("String = "+str);
        }
    }
}
