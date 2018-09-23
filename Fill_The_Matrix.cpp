#include <bits/stdc++.h>
using namespace std;
const int maxn =  1e6 + 5;
typedef struct Query {
	int s;
	int e;
	int v;
} Query;
int n, q;
Query query[maxn];
int arr[maxn];
int compare(const void *p, const void *q) {
	Query pp= *(Query *)p;
	Query qq = *(Query *)q;
	return pp.s - qq.s;
}
int main(){
	int t;
	int l;
	int v;
	int r;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while(t-- ){
		scanf("%d%d", &n, &q);
		int flag = 1;
		for(int i = 1; i <= n; i++){
			arr[i] = -1;
		}
		int cnt = 0;
		while(q--) {
			scanf("%d%d%d", &l, &r, &v);
			if(l == r && v){
				flag = 0;
			}
			if(flag){
				query[cnt].s = max(l, r); 
				query[cnt].e = min(l, r); 
				query[cnt++].v = v;
			}
		}
		if(!flag){
			printf("no\n");
			continue;
		}
		qsort(query, cnt, sizeof(Query), compare);
		int j = 1; arr[j] = 0;
		for(int i = 0; flag && i < cnt; i++) {
			l = query[i].s;
			r = query[i].e;
			v = query[i].v;
			for(; j <= n && j < l; j++){
				if(arr[j] == -1){
					arr[j] = 0;
				}
			}
			if(arr[l] != -1){
				if(abs(arr[l] - arr[r]) != v){
					flag = 0;
				}
			}
			else{
				if(v){
					arr[l] = arr[r] ? 0 : 1;
				}
				else{
					arr[l] = arr[r];
				}
			}
		}
		printf("%s\n", flag ? "yes" : "no");
	}
	return 0;
}