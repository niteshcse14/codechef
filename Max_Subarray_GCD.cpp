#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
 
#define FO(i,a,b) for (int i = (a); i < (b); i++)
 
#define PB push_back
#define FRO freopen("in.txt","r",stdin);
 
#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()
 
#define X first
#define Y second
#define MP make_pair
 
typedef pair<int,int> pint;
typedef map<int,int> mint;
 
void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }
 
#define SIZE 500010
 
int arr[SIZE];
int sparse[SIZE][20];
int bit[SIZE];
 
int get(int x,int y){
    int &b = bit[y-x+1];
    return __gcd(sparse[x][b], sparse[y - (1 << b) + 1][b]);
}
 
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&arr[i]);
    for (int i=n;i>0;--i){
        sparse[i][0] = arr[i];
        for (int j=1;i+(1<<j)<=n;++j)
            sparse[i][j] = __gcd( sparse[i][j-1],
                sparse[i+ ( 1<<(j-1) ) ][j-1] );
        for (int j=19;j>=0;--j){
            if ( i & (1<<j) ){
                bit[i] = j;
                break;
            }
        }
    }
 
    int ans = 0;
    for (int i=1;i<=n;++i){
        int low = 1,high=i;
        int ind = -1;
        while ( low<=high ){
            int mid = (low+high)/2;
            if ( get(mid,i) >= k ){
                high = mid-1;
                ind = mid;
            }else{
                low = mid+1;
            }
        }
        if ( ind != -1 ){
            ans = max( ans , i-ind+1 );
        }
    }
 
    printf("%d\n",ans);
    return 0;
}

/*
using namespace std;
#include <bits/stdc++.h>
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define wl(n) while(n--)
#define ll long long
#define P(x) printf("%d\n",x)
#define PB push_back
#define MP make_pair
#define fl(i,n) for(i=0;i<n;i++)
#define fil(i,a,n) for(i=a;i<n;i++)
#define rev(i,a,n) for(i=n-1;i>=a;i--)
#define mem(a,i) memset(a,i,sizeof(a))
#define F first
#define S1 second
typedef pair<int,int> P;
vector<int> v1;
pair<int,int> p1;
#define MOD 1000000007
#define debug(x)  printf("####%d####\n",x);
#define nl printf("\n");
#define str string
int a[1234567];
string s;
int dp[1001];int tree[2000001];
void create(int start,int end,int index)
{
    if(start==end)
    {
       tree[index]=a[start];
       return;
    }
    int mid=(start+(end-start)/2);
    create(start,mid,2*index+1);
    create(mid+1,end,2*index+2);
    tree[index]=__gcd(tree[2*index+1],tree[2*index+2]);
    return;
}
int getsum(int start,int end,int q1,int q2,int index)
{
    if(q2<start||q1>end)
        return 0;
    if(q1<=start&&q2>=end)
        return tree[index];
    int mid=(start+(end-start)/2);
    int an1=getsum(start,mid,q1,q2,2*index+1);
    int an2=getsum(mid+1,end,q1,q2,2*index+2);
    return __gcd(an2,an1);
}
int main() {
    int t;
    int n,i,j,k,m,l;
    S2(n,k);
    fl(i,n)
        S(a[i]);
    create(0,n-1,0);
    int p=*max_element(a,a+n);
    if(p<k)
    {
        printf("0\n");
        return 0;
    }
    int left=0,right=0;
    int ans=0;
    while(left<n&&right<n) {
        int p=getsum(0,n-1,left,right,0);
        if(p>=k) {
            ans=max(ans,right-left+1);
            right++;
        }
        else
            left++;
        right=max(left,right);
    }
    P(ans);
    return 0;
}
*/