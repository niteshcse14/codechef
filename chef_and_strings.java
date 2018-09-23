import java.io.*;
import java.util.*;
class CC
{
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        int Q=sc.nextInt(),len=str.length();
        while(Q-->0)
        {
            int i=0,j=0,j1=0,sum=0,k=0;
            
            String str1,str2;
            str1=sc.next();
            str2=sc.next();
            
            int i1,i2;
            i1=sc.nextInt();
            i2=sc.nextInt();
            
            char s=str1.charAt(0),e=str2.charAt(0);
            
            int arr1[]=new int[len];
            int arr2[]=new int[len];
            for(i=i1-1;i<i2;i++)
            {
                if(str.charAt(i)==s)
                {
                    arr1[j++]=i;
                }
                else if(str.charAt(i)==e)
                {
                    arr2[j1++]=i;
                }
            }
            
            for(i=0;i<j;i++)
            {
                for(k=0;k<j1;k++)
                {
                    if(arr1[i]<arr2[k])
                    {
                        sum++;
                    }
                }
            }
            System.out.println(sum);
        }
    }
}
