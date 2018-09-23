#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int st[2 * MAX];
int arr[MAX];
char str[MAX];
int N, M, l, r;
void build(int si, int ss, int se)
{
	if(ss == se)
	{
		st[ss] = (arr[ss] % 3 == 0) ? 1 : 0;
		return;
	}
	int mid = (ss + se) / 2;
	build(2 * si + 1, ss, mid);
	build(2 * si + 2, mid + 1, se);
	st[si] = st[2 * si + 1] + st[2 * si + 2];
}
int query(int si, int ss, int se, int l, int r)
{
	if(se < l || ss > r || ss > se)
	{
		return 0;
	}
	if(ss >= l && se <= r)
	{
		return st[si];
	}
	int mid = (ss + se) / 2;
	return (query(2 * si + 1, ss, mid, l, r) + query(2 * si + 2, mid + 1, se, l, r));
}
int main()
{
	scanf("%d %d", &N, &M);
	scanf("%s", str);
	for(int i = i = 0; i < N; i++)
	{
		arr[i] = str[i] - '0';
	}
	build(0, 0, N - 1);
	while(M--)
	{
		scanf("%d %d", &l, &r);
	}
	return 0;
}