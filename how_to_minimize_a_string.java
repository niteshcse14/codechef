import java.io.*;
import java.util.*;
import java.lang.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            int N,i,max=0,count=0;
            N=sc.nextInt();
            String str=sc.next();
            if(str.length()==N)
            {
                Character ch=new Character(str.charAt(N-1));
                max=(new Character(str.charAt(0))).compareTo(ch);
                
                for(i=0;i<N-1;i++)
                {
                    if(max<(new Character((str.charAt(i))).compareTo(ch)))
                    {
                        max=(new Character(str.charAt(i))).compareTo(ch);
                    }
                }
                
                char ch_arr[]=str.toCharArray(),ans[]=new char[N];
                
                for(i=0;i<N;i++)
                {
                    if((new Character(str.charAt(i))).compareTo(ch)==max && count<1)
                    {
                        ans[i]=str.charAt(N-1);
                        count++;
                    }
                    else if(count>0)
                    {
                        ans[i]=str.charAt(i-1);
                    }
                    else
                    {
                        ans[i]=ch_arr[i];//.toString();
                    }
                    System.out.print(ans[i]);
                }
                System.out.println();
            }
            else
            {
                System.out.println("Error");
            }
            //System.out.println(new String(ans));//.toString());
        }
    }
}
