import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T>0)
      {
         int size,i=0,j=0,temp;
         size=sc.nextInt();
         int arr[]=new int[size];
         for(i=0;i<size;i++)
         {
            arr[i]=sc.nextInt();
         }
         int min=arr[0]+arr[1];
         for(i=0;i<size-1;i++)
         {
            for(j=1;j<size;j++)
            {
               temp=arr[i]+arr[j];
               if(i!=j)
               {
                  if(temp<min)
                  {
                     min=temp;
                  }
               }
            }
         }
         System.out.println(min);
         T--;
      }
   }
}
