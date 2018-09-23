import java.io.*;
import java.util.*;
class CC
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n,i;
        n=sc.nextInt();
        int arr[]=new int[n];
        for(i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        int sum=0,first=arr[0];
        for(i=0;i<n;i++)
        {
            //sum+=arr[i];
            if(first==arr[i])
            {
                sum+=arr[i];
            }
            else if(sum>=3)
            {
                break;
            }
            else
            {
                sum+=arr[i];
            }
        }
        System.out.println(sum);
    }
}
