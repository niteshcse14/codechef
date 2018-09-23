import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,Q,i,j;
        N=sc.nextInt();
        Q=sc.nextInt();
        
        int arr_row[]=new int[N];
        int arr_col[]=new int[N];
        
        while(Q-->0)
        {
            String str=sc.next();
            int R,X;
            R=sc.nextInt();
            X=sc.nextInt();
            if(str.charAt(0)=='R')
            {
                arr_row[R-1]+=X;
            }
            else
            {
                arr_col[R-1]+=X;
            }
        }
        int max1=0,max2=0;//=arr[0][0];
        Arrays.sort(arr_row);
        Arrays.sort(arr_col);
        
        System.out.println(arr_col[N-1]+arr_row[N-1]);
    }
}
