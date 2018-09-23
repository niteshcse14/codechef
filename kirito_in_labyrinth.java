import java.io.*;
import java.util.*;
class CC
{
    int gcd(int a,int b)
    {
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }
    public static void main(String[] args)
    {
        CC c=new CC();
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            int i,j=0,n,count=1;
            n=sc.nextInt();
            int arr[]=new int[n];
            for(i=0;i<n;i++)
            {
                arr[i]=sc.nextInt();
            }
            
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(c.gcd(arr[i],arr[j])>1)
                    {
                        //System.out.println(arr[i]+"  "+arr[j]+"  "+c.gcd(arr[i],arr[j]));
                        i=j-1;
                        count++;
                        break;
                    }
                }
            }
            System.out.println(count);
        }
    }
}
