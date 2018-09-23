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
    	ll N,M,a=0,b=0;
    	N=sscan();
    	M=sscan();
    	ll arr[1000001]={0},arr1[1000001]={0};
    	FOR_Z(i,N)
    	{
    		a=sscan();
    		arr[i]=a;
    	}
    	FOR_Z(i,M)
    	{
    		b=sscan();
    		arr1[b]+=1;
    	}
    	ll sum=0;
    	FOR_Z(i,N)
    	{
    		if(arr1[arr[i]]>0)
    		{
    			sum++;
    		}
    	}
    	printf("%lld\n",sum);
    }
    return 0;
}