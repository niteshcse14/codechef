import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T,sum=0;
        T=sc.nextInt();
        while(T-->0)
        {
            int D,N,i;
            sum=0;
            D=sc.nextInt();
            N=sc.nextInt();
            for(i=0;i<D;i++)
            {
                sum=N*(N+1)/2;
                N=sum;
                //System.out.print(sum +" ");
            }
            System.out.println(sum);
        }
    }
}
