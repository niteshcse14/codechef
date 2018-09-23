import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) 
	{
		Scanner ss=new Scanner(System.in);
      int n=ss.nextInt(),i;
      while(n>0)
      {
         int digit=0,total=0;
         digit=ss.nextInt();
         while(digit!=0)
         {
            total=total+digit%10;
            digit=digit/10;
         }
         System.out.println(total);
         n--;
      }
	}
}
