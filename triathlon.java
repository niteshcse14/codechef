import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,i,j,k,temp,sum;
      N=sc.nextInt();
      
      int out[]=new int[N],
      cobol[]=new int[N],
      pole_vault[]=new int[N],
      dought_eating[]=new int[N],
      output[]=new int[N];
      
      for(i=0;i<N;i++)
      {
         cobol[i]=sc.nextInt();
         pole_vault[i]=sc.nextInt();
         dought_eating[i]=sc.nextInt();
      }
      k=0;
      for(i=0;i<N;i++)
      {
         for(j=i;j<N;j++)
         {
            if(cobol[i]<cobol[j])
            {
               temp=cobol[i];
               cobol[i]=cobol[j];
               cobol[j]=temp;
               
               temp=pole_vault[i];
               pole_vault[i]=pole_vault[j];
               pole_vault[j]=temp;
               
               temp=dought_eating[i];
               dought_eating[i]=dought_eating[j];
               dought_eating[j]=temp;
               k=j;
            }
         }
         //System.out.println(cobol[i]+"  "+k);
      }
      
      sum=0;
      for(i=0;i<N;i++)
      {
         output[i]=sum+cobol[i]+pole_vault[i]+dought_eating[i];
         sum=sum+cobol[i];
      }
      Arrays.sort(output);
      System.out.println(output[N-1]);
   }
}
