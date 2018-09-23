#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, count_U, count_D;
	string str;
	cin >> T;
	while(T--)
	{
		count_D = count_U = 0;
		cin >> str;
		char ch = str[0];
		if(ch == 'U')
		{
			count_U++;
		}
		else
		{
			count_D++;
		}
		//cout << ch << "  " << count_U << "  " << count_D << "\n";
		for(int i = 1; i < str.size(); i++)
		{
			if(str[i] == ch)
			{
				continue;
			}
			else
			{
				if(str[i] == 'U')
				{
					count_U++;
					ch = 'U';
				}
				else
				{
					count_D++;
					ch = 'D';
				}
				//cout << i << "    " << ch << "  " << count_U << "  " << count_D << "\n";
			}
		}
		cout << (min(count_D, count_U)) << "\n";
	}
	return 0;
}