#include <bits/stdc++.h>
using namespace std;
#define ll long
ll arr[100001];
int main()
{
	char type;
	ll N, M, d;
	scanf("%ld %ld", &N, &M);
	for(int i = 0; i < N; i++)
	{
		scanf("%ld", &arr[i]);
	}
	int i = 0;
	while(M--)
	{
		getchar();
		scanf("%c %ld", &type, &d);
		if(type == 'R')
		{
			printf("%ld\n", arr[(d + i - 1) % N]);
		}
		else if(type == 'A')
		{
			i = (i + N - d) % N;
		}
		else if(type == 'C')
		{
			i = (d + i) % N;
		}
	}
	return 0;
}