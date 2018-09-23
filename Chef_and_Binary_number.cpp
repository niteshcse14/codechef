#include <bits/stdc++.h>
using namespace std;
void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x % MOD;
  F[0][1] = y % MOD;
  F[1][0] = z % MOD;
  F[1][1] = w % MOD;
}
void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0] % MOD;
}
ll fast_power(ll a, ll b)
{
    ll result = 1;
    while(b > 0)
    {
        if(b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b / 2;
    }
    return result;
}
int main()
{
    fast;
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        ll N;
        scanf("%lld",&N);
        if(N == 1)
        {
            printf("0\n");
        }
        else
        {
            ll ans = fast_power(2, N) - fib(N + 2);
            if(ans >= 0)
            {
                printf("%lld\n",ans);
            }
            else
            {
                printf("%lld\n",ans + MOD);
            }
        }
    }
    return 0;
}