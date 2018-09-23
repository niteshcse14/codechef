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
            int N,n,div=0;
            N=sc.nextInt();
            div=N/8;
            if(N>0)
            {
                n=N%8;
            
                if(n==1)
                {
                    System.out.println((N+3)+"LB");
                }
                else if(n==2)
                {
                    System.out.println((N+3)+"MB");
                }
                else if(n==3)
                {
                    System.out.println((N+3)+"UB");
                }
                else if(n==4)
                {
                    System.out.println((N-3)+"LB");
                }
                else if(n==5)
                {
                    System.out.println((N-3)+"MB");
                }
                else if(n==6)
                {
                    System.out.println((N-3)+"UB");
                }
                else if(n==7)
                {
                    System.out.println((N+1)+"SU");
                }
                else if(n==0)
                {
                    System.out.println((N-1)+"SL");
                }
            }
        }
    }
}
