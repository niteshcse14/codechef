#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int count = 0, N = str.length();
	int arr[26];
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < N; i++)
	{
		arr[str[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++)
	{
		if(arr[i] % 2 != 0)
		{
			count++;
		}
	}
	if(count % 2 != 0)
	{
		printf("Ram\n");
	}
	else
	{
		printf("Shyam\n");
	}
	return 0;
}