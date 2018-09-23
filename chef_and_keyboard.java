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
            int n,m,c,count=0,i,j;
            
            n=sc.nextInt();
            m=sc.nextInt();
            c=sc.nextInt();
            for(i=1;i<=n;i++)
            {
                for(j=0;j<=m;j++)
                {
                    if(i*j>c)
                        break;
                    if(i*j==c)
                    {
                        count++;
                    }
                }
            }
            System.out.println(count);
        }
    }
}
