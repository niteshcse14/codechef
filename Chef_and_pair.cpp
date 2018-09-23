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

void solve()
{
	ll N = sscan(), count = 0, sum = 0;
	//ll x[], y[];
	if(N >= 1000000001)
	{
		for(int i = sqrt(N); i <=N; i++)
		{
			//cout<<"HH";
			for(int j = 2; j <= 50; j++)
			{
				if((ll)pow(i, j) == N)
				{
					count++;
					sum+=i+j;
					break;
					//cout<<i<<"  "<<j<<"\n";
				}
			}
		}
		cout<<(count+1)<<endl;
		cout<<(sum+N+1)<<endl;
	}
	else
	{
		for(int i = 2; i <sqrt(N); i++)
		{
			//cout<<"HH";
			for(int j = 3; j <= 50; j++)
			{
				if((ll)pow(i, j) == N)
				{
					count++;
					sum+=i+j;
					//cout<<i<<"  "<<j<<"\n";
				}
			}
		}

		ll root = sqrt(N);
		if(root*root == N)
		{
			cout<<(count+1+1)<<endl;
			cout<<(sum+N+1+root+2)<<endl;
		}
		else
		{
			cout<<(count+1)<<endl;
			cout<<(sum+N+1)<<endl;
		}
	}
	
}
int main()
{
    fast;
    ll T = sscan();
    while(T--)
    {
    	solve();
    }
    return 0;
}