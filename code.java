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
            int N,K,answer,i,j;
            N=sc.nextInt();
            K=sc.nextInt();
            answer=sc.nextInt();
            int arr[]=new int[N];
            for(i=0;i<N;i++)
            {
                arr[i]=sc.nextInt();
            }
            String operator=sc.next();
            
            if(operator.equals("XOR"))
            {
                //for(i=0;i<K;i++)
                //{
                    for(j=0;j<N;j++)
                    {
                        answer=answer^arr[j];
                    }
                //}
            }
            else if(operator.equals("OR"))
            {
               // for(i=0;i<K;i++)
                //{
                    for(j=0;j<N;j++)
                    {
                        answer=answer|arr[j];
                    }
                //}
            }
            else if(operator.equals("AND"))
            {
                //for(i=0;i<K;i++)
                //{
                    for(j=0;j<N;j++)
                    {
                        answer=answer&arr[j];
                    }
                //}
            }
            System.out.println(answer);
        }
    }
}
