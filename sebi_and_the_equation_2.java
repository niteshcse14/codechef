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
            int A,B,C,N,X=0,Y=0,x,y;
            A=sc.nextInt();
            B=sc.nextInt();
            C=sc.nextInt();
            N=sc.nextInt();
            
            for(x=1;x<=N;x++)
            {
                for(y=x;y<=N;y++)
                {
                    if(x*y==((x|y)*(x&y)+(A*x)+(B*y)+C))
                    {
                        X+=x+y;
                        Y+=x+y;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            System.out.println(X+" "+Y);
        }
    }
}
