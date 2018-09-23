import java.io.*;
import java.util.*;
class CC
{
   public static void main(String[] args) throws Exception
   {
      Scanner sc=new Scanner(System.in);
      int n=0,sum,rem,temp,i,out=0;
      n=sc.nextInt();
   //scanf("%d",&n);
   while(n>0)
   {
      long num=0;
      num=sc.nextInt();
      for(num=num+1;;num++)
      {
        // num++;
         sum=0;
         rem=0;
         temp=num;
         while(num!=0)
         {
            rem=num%10;
            sum=sum*10+rem;
            num=num/10;
            out=sum;
         }
         if(sum==temp)
         {
            System.out.print(temp);
            break;
         }
         num=temp;
      }
      System.out.println();
      n--;
   }
   }
}
