import java.util.Scanner;

class Alice_and_Bob_s_Silly_Game 
{
	public static boolean prime_non_prime(int n)
	{
		int i=0,flag=0;
		if(n==2)
		{
			return true;
		}
		if(n%2==0)
		{
			return false;
		}
		for(i=3;i*i<=n;i=i+2)
		{
			if(n%i==0)
			{
				return false;
			}
		}
		return true;
	}
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		int g=sc.nextInt();
		while(g-->0)
		{
			int n,i,prime=0,count=0;
			n=sc.nextInt();
			if(n>1)
			{
				for(i=2;i<=n;i++)
				{
					if(prime_non_prime(i)==true)
					{
						//System.out.println(i+" Prime");
						count++;
					}
				}
				if(count%2==0)
				{
					System.out.println("Bob");
				}
				else
				{
					System.out.println("Alice");
				}
				/*
				for(i=2;i<=n;i++)
				{
					if(prime_non_prime(i)==true)
					{
						prime=i;
						break;
					}
					else
					{
						check=i;
					}
				}
				if(check<n)
				{
					for(i=2;i<=n;i++)
					{
						if(i%prime==0)
						{
							
						}
					}
				}
				*/
			}
			else
			{
				System.out.println("Bob");
			}
		}
	}

}

