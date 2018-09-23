import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args)
	{
      Scanner ss=new Scanner(System.in);
      int n,element,first,second,i,size,j=0,k=0;
      n=ss.nextInt();
      while(n>0)
      {
         size=ss.nextInt();
         element=ss.nextInt();
         int arr[]=new int[size];
         for(i=0;i<size;i++)
         {
            arr[i]=ss.nextInt();
         }
         for(i=0;i<size;i++)
         {
            if(arr[i]==size)
            {
               j++;
            }
            if(arr[i]==element)
            {
               k++;
            }
         }
         if(j>0 && k>0)
         {
            System.out.println("Yes");
         }
         else
         {
            System.out.println("No");
         }
         j=0;
         k=0;
         n--;
      }
   }
}
/*
import java.io.*;
import java.util.*;
class TRY
{
   public static void main(String[] args)
   {
      Scanner ss=new Scanner(System.in);
      System.out.println("Enter size of Elements");
      int size=ss.nextInt();
      int arr[]=new int[size];
      int i,n,n1,n2,j=0,k=0;
      System.out.println("Enter two elements");
      n1=ss.nextInt();
      n2=ss.nextInt();
      System.out.println("Enter Elements");
      for(i=0;i<size;i++)
      {
         arr[i]=ss.nextInt();  
      }
      n=arr.length;
      for(i=0;i<n;i++)
      {
         if(arr[i]==n1)
         {
            j++;
         }
         if(arr[i]==n2)
         {
            k++;
         }
      }
      if(j>0 && k>0)
      {
         System.out.println("YES");
      }
      else
      {
         System.out.println("NO");
      }
   }
}
*/
