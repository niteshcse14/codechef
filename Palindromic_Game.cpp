#include <bits/stdc++.h>
using namespace std;
bool palim(int arr[])
{
	int count = 0, sum = 0;
	for(int i = 0; i < 26; i++)
	{
		sum += arr[i];
		if(arr[i] % 2 != 0)
		{
			count++;
		}
	}
	if(count <= 1 && sum > 1)
	{
		return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		string s, t;
		cin >> s >> t;
		int N = s.length();
		int s_arr[26], t_arr[26], condition[26];
		memset(s_arr, 0, sizeof(s_arr));
		memset(condition, 0, sizeof(condition));
		memset(t_arr, 0, sizeof(t_arr));
		for(int i = 0; i < N; i++)
		{
			s_arr[s[i] - 'a']++;
		}
		for(int i = 0; i < N; i++)
		{
			t_arr[t[i] - 'a']++;
		}
		char ans;
		bool find = false;
		int count_s = 0, count_t = 0;
		for(int i = 0;i < 26; i++)
		{
			count_s = max(count_s, s_arr[i]);
		}
		for(int i = 0;i < 26; i++)
		{
			count_t = max(count_t, t_arr[i]);
		}
		if(count_s == N && count_t == N && N > 1)
		{
			if(s[0] == t[0])
			{
				printf("B\n");
			}
			else
			{
				printf("A\n");
			}
			continue;
		}
		int count = 1, chance = 0;
		//printf("optimal\n");
		while(count != 26)
		{
			count = 0;
			int flag = 1;
			for(int i = 0; i < 26; i++)
			{
				if(s_arr[i] != 0 && t_arr[i] != 0)
				{
					continue;
				}
				if(chance % 2 == 0 && s_arr[i] != 0 && t_arr[i] == 0)
				{
					s_arr[i] = s_arr[i] - 1;
					//printf("if   %d %d\n", chance, i);
					condition[i]++;
					flag = 0;
					break;
				}
				else if(chance % 2 != 0 && t_arr[i] != 0 && s_arr[i] == 0)
				{
					t_arr[i] = t_arr[i] - 1;
					//printf("else  %d %d\n", chance, i);	
					condition[i]++;
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				//printf("FLAG\n");
				for(int i = 0; i < 26; i++)
				{
					if(s_arr[i] != 0 && t_arr[i] != 0)
					{
						if(chance % 2 == 0)
						{
							s_arr[i] = s_arr[i] - 1;
						}
						else
						{
							t_arr[i] = t_arr[i] - 1;
						}
						condition[i]++;
						break;
					}
				}
			}
			if(palim(condition) && chance % 2 != 0)
			{
				//printf("true chance  %d\n", chance);
				/*
				for(int i = 0; i < 26; i++)
				{
					printf("%d ", condition[i]);
				}
				printf("\n");
				*/
				ans = 'B';
				break;
			}
			else if(palim(condition) && chance % 2 == 0)
			{
				//printf("true chance  %d\n", chance);
				ans = 'A';
				break;
			}
			for(int i = 0; i < 26; i++)
			{
				if(s_arr[i] == 0 && t_arr[i] == 0)
				{
					count++;
				}
			}
			chance++;
		}
		printf("%c\n", (count == 26) ? 'B' : ans);
	}
	return 0;
}