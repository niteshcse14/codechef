import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,i;
        N=sc.nextInt();
        if(N>0)
        {
            int arr[]=new int[N];
            BigInteger arr1[]=new BigInteger[N];
            for(i=0;i<N;i++)
            {
                arr[i]=sc.nextInt();
            }
            Arrays.sort(arr);
            for(i=0;i<N;i++)
            {
                BigInteger b_i=new BigInteger(String.valueOf(N-i)),b_arr=new BigInteger(String.valueOf(arr[i]));
                arr1[i]=b_i.multiply(b_arr);
            }
            Arrays.sort(arr1);
            System.out.println(arr1[N-1]);
        }
    }
}
