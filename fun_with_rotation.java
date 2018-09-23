import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,M;
        N=sc.nextInt();
        M=sc.nextInt();
        int arr[]=new int[N],i=0;
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        while(M-->0)
        {
            String str=sc.next();
            int d;
            d=sc.nextInt();
            if(str.charAt(0)=='R')
            {
                System.out.println(arr[d-1]);
            }
            else if(str.charAt(0)=='C')
            {
                for(i=0;i<N;i++)
                {
                    arr[i]=arr[(i+d)%N];
                    System.out.print(arr[i]+" ");
                }
                System.out.println();
            }
            else if(str.charAt(0)=='A')
            {
                for(i=0;i<N;i++)
                {
                    arr[i]=arr[(N+i-d)%N];
                    System.out.print(arr[i]+" ");
                }
                System.out.println();
            }
        }
    }
}
