/*
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
            int G,I,N,Q,i,j,count_H=0,count_T=0;
            G=sc.nextInt();
            while(G-->0)
            {
                count_H=0;
                count_T=0;
                I=sc.nextInt();
                N=sc.nextInt();
                Q=sc.nextInt();
                char ch[]=new char[N];
                if(I==1)
                {
                    for(i=0;i<N;i++)
                    {
                        ch[i]='H';
                    }
                }
                else
                {
                    for(i=0;i<N;i++)
                    {
                        ch[i]='T';
                    }
                }
            
                for(i=0;i<N;i++)
                {
                    for(j=0;j<=i;j++)
                    {
                        if(ch[j]=='H')
                        {
                            ch[j]='T';
                        }
                        else
                        {
                            ch[j]='H';
                        }
                    }
                }
            
                for(i=0;i<N;i++)
                {
                    //System.out.print(ch[i]+" ");
                    if(ch[i]=='H')
                    {
                        count_H++;
                    }
                    else
                    {
                        count_T++;
                    }
                }
                //System.out.println();
                if(Q==1)
                {
                    System.out.println(count_H);
                }
                else
                {
                    System.out.println(count_T);
                }
            }
        }
    }
}
*/

import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        while(T-->0)
        {
            int G,I,N,Q,div,rem,sum;
            G=sc.nextInt();
            while(G-->0)
            {
                sum=0;
                I=sc.nextInt();
                N=sc.nextInt();
                Q=sc.nextInt();
                
                div=N/2;
                rem=N%2;
                sum=div+rem;
                if(I==Q)
                {
                    System.out.println(N-sum);
                }
                else
                {
                    System.out.println(sum);
                }
            }
        }
    }
}
