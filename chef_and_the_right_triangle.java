import java.io.*;
import java.util.*;
import java.math.*;
class CC
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,i,j,count=0,x1,x2,x3,y1,y2,y3;double A,B,C;
      double a,b,c;
      N=sc.nextInt();
      while(N-->0)
      {
         x1=sc.nextInt();
         y1=sc.nextInt();
         x2=sc.nextInt();
         y2=sc.nextInt();
         x3=sc.nextInt();
         y3=sc.nextInt();
         
         a=Math.sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
         b=Math.sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
         c=Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
         
         
         
         //System.out.println("a = "+a+"\nb = "+b+"\nc = "+c);
         
         A=(Math.asin((c*(Math.sin((Math.toRadians(B))))/b))*((180)/(Math.PI)));
         
         B=(Math.acos((a*a+c*c-b*b)/(2*a*c)))*((180)/(Math.PI));
         
         C=180-B-A;
         
         //System.out.println("Angle A = "+A+"\nAngle B = "+B+"\nAngle C = "+C);
         if((int)A==90 || (int)B==90 || (int)C==90)
            count++;
      }
      System.out.println(count);
   }
}
