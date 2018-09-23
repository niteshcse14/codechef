#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6 +10;
vector<ll> g[2000001],g2[1000001],g3;
bool vis[2000001]={0};
ll spf[N]={0};
ll c1[N]={0};
void seive()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;
    for (int i=4; i<N; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<N; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
void fun(ll x)
{
    while (x != 1)
    {
        c1[spf[x]]++;
        x = x / spf[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    seive();
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            fun(a[i]);
        }
        ll ans=1;
        for(int i=2;i<N;i++)
        {
            if(c1[i]>=n)
            {
                multiset<ll> mul;
                for(int j=0;j<n;j++)
                {
                    ll x=a[j];
                    ll c2=0;
                    while(1)
                    {
                        if(x%i==0)
                        {
                            x=x/i;
                            c2++;
                        }
                        else
                            break;
                    }
                    mul.insert(c2);
                }
                ll x=mul.size();
                for(int j=x;j<n;j++)
                    mul.insert(0);
                while(1)
                {
                    auto it1=mul.begin();
                    auto it2=mul.end();
                    it2--;
                    ll t1=*it1;
                    ll t2=*it2;
                    if(t1+1>t2-2)
                        break;
                    else
                    {
                        mul.erase(it1);
                        mul.erase(it2);
                        mul.insert(t1+1);
                        mul.insert(t2-2);
                    }
                }
                ll xx=*mul.begin();
                ll y=pow(i,xx);
                ans=ans*y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
} 