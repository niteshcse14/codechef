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
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

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

inline long long int sscan()
{
   long long int n=0;
   int ch=gc();
   while( ch < '0' || ch > '9' )
        ch=gc();
   while(  ch >= '0' && ch <= '9' )
   {
       n = (n<<3)+(n<<1) + ch-'0';
       ch=gc();
   }
   return n;
}
bool prime_non_prime(ll n)
	{
		ll i=0,flag=0;
		if(n==2)
		{
			return true;
		}
		if(n%2==0)
		{
			return false;
		}
		for(i=3;i*i<=n;i=i+2)
		{
			if(n%i==0)
			{
				return false;
			}
		}
		return true;
	}
void solve()
{
	int N, Q;
	cin>>N>>Q;
	int arr[N], ans[N] = {0};
	FOR_Z(i, N)
	{
		cin>>arr[i];
	}
	FOR_A(i, 1, N+1)
	{
		ans[i] = ans[i - 1] + prime_non_prime(arr[i]);
	}
	
	int type;
	while(Q--)
	{
		cin>>type;
		int c, d;
		cin>>c>>d;
		if(type == 1)
		{
			
			if(d >= c)
			{
				cout<<(ans[d]-ans[c-1])<<"\n";
			}
			else
			{
				cout<<"0\n";
			}
		}
		else
		{
			int p = prime_non_prime(d) - ans[c] + ans[c - 1];
			if(p != 0)
			{
				FOR_A(i, c,N+1)
				{
					ans[i] = ans[i] + p;
				}
			}
		}
	}
}
int main()
{
    ll T = 1;
    while(T--)
    {
    	solve();
    }
    return 0;
}