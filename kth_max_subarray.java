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
            int N,M,i,j,size=0,k=0,t=0,sub_size=0;
            N=sc.nextInt();
            for(i=0;i<N;i++)
            {
                sub_size+=(i+1)*(N-i);
            }
            
            M=sc.nextInt();
            size=((N)*(N+1))/2;
            int arr[]=new int[N];
            int sub_arr[]=new int[sub_size];
            for(i=0;i<N;i++)
            {
                arr[i]=sc.nextInt();
            }
            t=0;
            //System.out.println("SUB");
            for(i=0;i<N;i++)
            {
                t=i;
                while(t<N)
                {
                    //System.out.println(t);
                    for(j=i;j<t+1;j++)
                    {
                        sub_arr[k]=arr[j];
                        k++;
                    }
                    t++;
                }
            }
            /*
            for(i=0;i<k;i++)
            {
                System.out.print(sub_arr[i]+" ");
            }
            System.out.println("K = "+k);
            */
            Arrays.sort(sub_arr);
            /*
            for(i=0;i<k;i++)
            {
                System.out.print(sub_arr[i]+" ");
            }
            System.out.println("K = "+k);
            */
            //System.out.println("SUM "+count);
            while(M-->0)
            {
                int P;
                P=sc.nextInt();
                System.out.println(sub_arr[k-P-1]);
            }
        }
    }
}
