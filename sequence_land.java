import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {   
        Scanner sc=new Scanner(System.in);
        int N,K,ans=1,i,j,flag=0,count=0;
        N=sc.nextInt();
        K=sc.nextInt();
        
        if(N>=1 && K>=1)
        {
            int p,res_p;
            p=sc.nextInt();
            int arr[]=new int[p];
            for(i=0;i<p;i++)
            {
                arr[i]=sc.nextInt();
            } 
            while(N-->1)
            {
                count=0;
                flag=0;
                res_p=sc.nextInt();
            
                int arr1[]=new int[res_p];
                for(i=0;i<res_p;i++)
                {
                    arr1[i]=sc.nextInt();
                }
            
            
                for(i=0;i<p;i++)
                {
                    for(j=0;j<res_p;j++)
                    {
                        if(arr[i]==arr1[j])
                        {
                            count++;
                        }
                    }
                    if(count>=K)
                    {
                        ans++;
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag=0;
                    }
                }
                   
                if(flag==1)
                {
                    p=res_p;
                    arr=new int[p];
                    for(i=0;i<p;i++)
                    {
                        arr[i]=arr1[i];
                    }
                }
            }
            System.out.println(ans);
        }
        else
        {
            System.out.println("0");
        }
    }
}
