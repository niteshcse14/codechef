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
         int N,K,student,teacher;
         N=sc.nextInt();
         K=sc.nextInt();
         student=N/K;
         teacher=N-student*K;
         System.out.println(student+" "+teacher);
         //System.out.println();
      }
   }
}
