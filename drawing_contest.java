import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T,j=1;
        T=sc.nextInt();
        while(T-->0)
        {
            int K,i,sum=0;
            K=sc.nextInt();
            int h[]=new int[K],l[]=new int[K];
            for(i=0;i<K;i++)
            {
                  h[i]=sc.nextInt();
            }
            for(i=0;i<K;i++)
            {
                  l[i]=sc.nextInt();
            }
            Arrays.sort(h);
            Arrays.sort(l);
            for(i=0;i<K;i++)
            {
                  sum+=Math.abs(h[i]-l[i]);
            }
            System.out.println("Case "+j+":"+" "+sum);
            j++;
        }
    }
}
