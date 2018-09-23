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
         int mg,my,mr,og,oy,or,pg,py,pr;
         int sumg=0,sumy=0,sumr=0,zero=0;
         mg=sc.nextInt();
         my=sc.nextInt();
         mr=sc.nextInt();
         
         og=sc.nextInt();
         oy=sc.nextInt();
         or=sc.nextInt();
         
         pg=sc.nextInt();
         py=sc.nextInt();
         pr=sc.nextInt();
         
         sumg=mg+og+pg;
         sumy=my+oy+py;
         sumr=mr+or+pr;
         int arr[]=new int[3];
         arr[0]=sumg;
         arr[1]=sumy;
         arr[2]=sumr;
         Arrays.sort(arr);
         
         if(arr[2]%2==0)
         {
            System.out.println(arr[2]-1);
         }
         else
         {
            System.out.println(arr[2]);
         }
      }
   }
}
