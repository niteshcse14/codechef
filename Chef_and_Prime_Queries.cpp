#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e6 + 6;
int spf[M];
int n;
int arr[N];
int q;
int l[N], r[N], x[N], y[N];
int ans[N];
vector < pair <int, int> > v[M];
vector < int > add[M];
vector < int > sub[M];
void pre()
{
	for(int i = 2; i < M; i++){
		if(!spf[i])
		{
			for(int j = i; j < M; j += i){
				if(!spf[j]){
					spf[j] = i;
				}
			}
		}
	}
	spf[1] = 1;
}
int bit[N];
void update(int idx, int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int main(){
	pre();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", arr + i);
	}
	for(int i = 1; i <= n; ++i){
		int val = arr[i];
		int last = spf[val];
		int cnt = 0;
		while(val > 1){
			int x = spf[val];
			val /= x;
			if(x == last){
				cnt++;
			}
			else{
				v[last].emplace_back(make_pair(i, cnt));
				cnt = 1;
				last = x;
			}
		}
		if(last > 1){
			v[last].emplace_back(make_pair(i, cnt));
		}
	}
	for(auto it:v[i])
	return 0;
}