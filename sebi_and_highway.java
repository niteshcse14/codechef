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
            int s,sg,fg,d,t;
            s=sc.nextInt();
            sg=sc.nextInt();
            fg=sc.nextInt();
            d=sc.nextInt();
            t=sc.nextInt();
            
            int ans=s+(d*50*18)/(5*t);
            int a,b;
            a=Math.abs(ans-sg);
            b=Math.abs(ans-fg);
            if(sg==fg || a==b)
            {
                System.out.println("DRAW");
            }
            else if(a>b)
            {
                System.out.println("FATHER");
            }
            else if(b<a)
            {
                System.out.println("SEBI");
            }
            
        }
    }
}
