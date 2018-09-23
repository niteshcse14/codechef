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
	int N, ones = 0, zeros = 0, a, flag = 0, main_zero = 0;
	scanf("%d",&N);
	FOR_Z(i, N)
	{
		scanf("%d",&a);
		if(a == 0)
		{
			zeros++;
			flag = 1;
		}
		else if(a == 1)
		{
			ones++;
		}
		if(zeros == 0 && flag == 0)
		{
			main_zero++;
		}
	}
	if(ones == N && zeros == 0)
	{
		printf("0\n");
	}
	else if(zeros == N && ones == 0)
	{
		printf("%d\n",N*(1100));
	}
	else if(ones != 0 && zeros != 0 && main_zero != 0)
	{
		printf("%d\n",zeros*(1100) + ones*100 - main_zero*100);
	}
	else if(ones !=0 && zeros != 0)
	{
		printf("%d\n",zeros*(1100) + ones*100);
	}
}
int main()
{
    fast;
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	solve();
    }
    return 0;
}
//Chef_and_His_Apartment_Dues.cpp