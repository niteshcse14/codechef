#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T=sscan();
    while(T--)
    {
    	ll N=sscan();
    	ll a[N]={0},b[N]={0},x,y;
    	FOR_Z(i,N)
    	{
    		x=sscan();
    		y=sscan();
    		a[i]=x;
    		b[i]=y;
    	}
    	ll M=sscan();
    	ll l[M]={0},c[M]={0};
    	FOR_Z(i,M)
    	{
    		l[i]=sscan();
    		c[i]=sscan();
    	}
    	FOR_A(i,0,N-1)
    	{
    		a[i]=abs(a[i%N]-a[(i+1)%N]);
    		b[i]=abs(b[i%N]-b[(i+1)%N]);
    	}
    	ll mm=0,sum=0;
    	FOR_Z(i,N)
    	{
    		mm=max(a[i],b[i]);
    		if(mm!=0)
    		{
    			FOR_Z(j,M)
    			{
    				if(mm==l[j])
    				{
    					sum+=c[j];
    					break;
    				}
    			}
    		}
    	}
    	printf("%lld\n",sum);
    }
    return 0;
}