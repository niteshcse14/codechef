#include <bits/stdc++.h>
using namespace std;
int T, N, A, B, tmp, tmp2;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		cin >> N >> A >> B;
		if(A > B) swap(A, B);
		tmp = B - 1 - A;
		tmp2 = N - tmp - 2;
		if(tmp == tmp2)
		{
			cout << "0\n";
		}
		else
		{
			cout << (min(tmp2, tmp)) << "\n";
		}
	}
	return 0;
}