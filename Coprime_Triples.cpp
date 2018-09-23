#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
pair <int, int > pii;
pair <pii, int > piii;
map <piii, int> present;
int arr[maxn];
int N;
int get_GCD(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	return get_GCD(b % a, a);
}
int gcd(int a, int b, int c){
	return get_GCD(a, get_GCD(b, c));
}
int _coprime(int curr_gcd, int i, int j){
	if(j == N){
		if(curr_gcd == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
	piii key = make_pair(make_pair(curr_gcd, i), j);
}
int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}
	//present.clear();
	int ans = 0;
	for(int i = 0; i < N - 2; i++)
	{
		ans += _coprime(arr[i], i + 1, i + 2);
	}
	printf("%d\n", ans);
	return 0;
}
//Coprime_Triples.cpp