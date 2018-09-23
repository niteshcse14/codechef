#include <bits/stdc++.h>
using namespace std;
#define MAXL 1000000
#define MAXP 80000
#define MAXN 10;
int P, N;
int arr[MAXL];
int prime[MAXP];
//int count[MAXP];
int init()
{
	int i, j;
	for(i = 2; i * i < MAXL; i++)
	{
		if(arr[i])
		{
			continue;
		}
		for(j = i * i; j < MAXL; j += i)
		{
			arr[j] = 1;
		}
		prime[P++] = i;
	}
	for(; i < MAXL; i++)
	{
		if(!arr[i])
		{
			prime[P++] = i;
		}
	}
	return P;
}
int main()
{
	int i, j, T, data;
	long long ans = 1;
	init();
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int count[P];
		memset(count, 0, sizeof(count));
		//memset(count, 0, sizeof(int) * MAXP);
		for(i = 0; i < N; i++)
		{
			scanf("%d", &data);
			for(j = 0; j < P; j++)
			{
				while(!(data % prime[j]))
				{
					//printf("divisible  %d   ", prime[j]);
					++count[j];
					data /= prime[j];
				}
			}
		}
		ans = 1;
		for(i = 0; i < P; i++)
		{
			ans *= (count[i] + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
#include <stdio.h>
#include <string.h>
 
#define MAXL 1000000
#define MAXP 80000
#define MAXN 10
 
int fac[MAXL];
int primes[MAXP];
int count[MAXP];
int P,N;
 
int init(){
 
	int i,j;
 
	for(i = 2; i*i < MAXL; i++){
		if(fac[i]) continue;
		for(j = i*i; j < MAXL; j += i) fac[j] = 1;
		primes[P++] = i;
	}
 
	for(; i < MAXL; i++){
		if(fac[i]) continue;
		primes[P++] = i;
	}
 
	return P;
}
 
int main(){
 
	int i,t,n,p;
	long long sol;
 
	init();
 
	scanf("%d",&t);
 
	while(t--){
		scanf("%d",&N);
		memset(count, 0, sizeof(int)*MAXP);
 
		for(i = 0; i < N; i++){
			scanf("%d",&n);
			for(p = 0; p < P; ++p){
				while(!(n%primes[p])){
					++count[p];
					n /= primes[p];
				}
			}
		}
 
		sol = 1;
		for(p = 0; p < P; ++p) sol *= (count[p]+1);
		printf("%lld\n",sol);
	}
 
 
	return 0;
}

*/