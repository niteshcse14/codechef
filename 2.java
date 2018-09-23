/*you are required to complete this function*/
import java.io.*;
import java.util.*;
class GfG
{
    public static String convertToRoman(int n)
    {
    	if (n < 1 || n > 3999)
        return "Invalid Roman Number Value";
        String s = "";
        while (n >= 1000)
        {
            s += "M";
            n -= 1000;     
        }
        
        while (n >= 900)    
        {
            s += "CM";
            n -= 900;
        }
        
        while (n >= 500) 
        {
            s += "D";
            n -= 500;
        }
        
        while (n >= 400)
        {
            s += "CD";
            n -= 400;
        }
        
        while (n >= 100) 
        {
            s += "C";
            n -= 100;
        }
        
        while (n >= 90) 
        {
            s += "XC";
            n -= 90;
        }
            
        while (n >= 50) 
        {
            s += "L";
            n -= 50;
        }
        
        while (n >= 40)
        {
            s += "XL";
            n -= 40;
        }
        
        while (n >= 10) 
        {
            s += "X";
            n -= 10;
        }
        
        while (n >= 9)
        {
            s += "IX";
            n -= 9;
        }
      
        while (n >= 5)
        {
            s += "V";
            n -= 5;
        }
        
        while (n >= 4)
        {
            s += "IV";
            n -= 4;
        }
            
        while (n >= 1)
        {
            s += "I";
            n -= 1;
        }    
    return s;	
    }
public static void main(String[] args)
   {
      GfG t=new GfG();
      Scanner ss=new Scanner(System.in);
      int i,n=ss.nextInt();
      int nn[]=new int[n];
      for(i=0;i<n;i++)
      {
         nn[i]=ss.nextInt();
      }
      for(i=0;i<n;i++)
      {
         int nnn=nn[i];
         System.out.println(convertToRoman(nnn));
      }
   }
}

