#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define f first
#define s second
#define F front
#define P pop
#define p push
#define Pb pop_back
#define b begin
#define e end
#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mh make_heap
#define ph push_heap
#define Ph pop_heap
#define sh sort_heap
#define ih is_heap
#define p_que priority_queue
#define FOR_Z(i,a) for(int i = 0; i < a; ++i)
#define FOR_A(i,a,b) for(int i = a; i < b; ++i)
#define FOR_O_Z(i,a) for(int i = a; i >= 0; --i)
#define FOR_O_A(i,a,b) for(int i = a; i > b; --i)
#define mod 1000000007
#define s_l(a) scanf("%lld",&a)
#define s_ll(a, b) scanf("%lld %lld",&a, &b)
#define s_lll(a, b, c) scanf("%lld %lld %lld",&a, &b, &c)

#define s_i(a) scanf("%d",&a)
#define s_ii(a, b) scanf("%d %d",&a, &b)
#define s_iii(a, b, c) scanf("%d %d %d",&a, &b, &c)

#define p_l(a) printf("%lld\n",a)
#define p_ll(a, b) printf("%lld %lld\n",a, b)
#define p_lll(a, b, c) printf("%lld %lld %lld\n",a, b, c)

#define p_i(a) printf("%d\n",a)
#define p_ii(a, b) printf("%d %d\n",a, b)
#define p_iii(a, b, c) printf("%d %d %d\n",a, b, c)
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
#define INF 0x3f3f3f3f

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

typedef pair<int, int> iPair;

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

ll power(ll a, ll b)
{
    int f = 1;
    while(b)
    {
        f = b & 1 ? (f * a) % MOD : f;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return f % MOD;
}

ll modpow(ll a, ll b)
{
	ll r = 1;

	while (b) {
		if (b & 1) {
			r = (r * a) % mod;
		}

		a = (a * a) % mod;

		b >>= 1;
	}

	return r;
}

ll modpowinverse(ll a) 
{
	return modpow(a, mod - 2);
}
//create method to here



void solve()
{
	ll N, M;
	cin>>N>>M;
	V_ll arr;
	FOR_Z(i, N)
	{
		ll data;
		cin>>data;
		arr.pb(data);
	}
	while(M--)
	{
		ll L, R, K, flag = 0, sum = 0, ans = -1;
		cin>>L>>R>>K;
		L = L - 1;
		R = R - 1;
		ll KK = floor((R - L + 1) / 2);
		if(K > KK)
		{
			FOR_A(i, L, R + 1)
			{
				sum = 0;
				FOR_A(j, L, R + 1)
				{
					if(arr[i] == arr[j])
					{
						sum++;
					}

					if(sum > K)
					{
						flag = 1;
						ans = arr[i];
						break;
					}
					
					if(arr[i] != arr[j])
					{
						sum = 0;
					}
				}
				if(flag == 1)
				{
					break;
				}
			}
			if(flag == 1)
			{
				p_l(ans);
			}
			else
			{
				printf("-1\n");
			}
		}
		else
		{
			printf("-1\n");
		}
	}

	}
int main()
{
    fast;
    ll T = 1;
    //cin>>T;
    while(T--)
    {
    	solve();
    }
    return 0;
}
//Most_Frequent_Element.cpp