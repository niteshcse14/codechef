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
#define FOR_Z(i,a) for(int i=0;i<a;i++)
#define FOR_A(i,a,b) for(int i=a;i<b;i++)
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
# define INF 0x3f3f3f3f
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
class Graph
{
	int V;
	int E;
	list< pair<int,int> > *adj;
public:	
	void display();
	void number_edges(int src, int dest);
	//bool conneted_or_not(int a, int b);
	Graph(int V, int E);
	void addEdge(int v, int u, int w);
};
Graph::Graph(int V, int E)
{
	this->V = V;
	adj = new list<pair<int,int> >[V];
}
void Graph::addEdge(int v, int u, int w)
{
	adj[v].pb(mp(u, w));
}
/*
bool Graph::conneted_or_not(int a, int b)
{
	int flag = 0;
	list< pair<int, int> >::iterator i;
	for(i = adj[a].b(); i != adj[a].e(); i++)
	{
		if((*i).f == b)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/
void Graph::number_edges(int src, int dest)
{
	set< pair<int, int> > setds;
	V_int dist(V, INF);
	V_int ans(V, 0);
	setds.insert(mp(0, src));
	dist[src] = 0;

	while(!setds.empty())
	{
		pair<int, int> tmp = *(setds.b());
		setds.erase(setds.b());
		int u = tmp.s;
		list< pair<int, int> >::iterator i;
		for(i = adj[u].b(); i != adj[u].e(); i++)
		{
			int v = (*i).f;
			int w = (*i).s;
			if(dist[v] > dist[u] + w)
			{
				if(dist[v] != INF)
				{
					setds.erase(setds.find(mp(dist[v], v)));
				}
				ans[v] = ans[u] + 1;
				dist[v] = dist[u] + w;
				setds.insert(mp(dist[v], v));
			}
		}
		if(u == dest)
		{
			break;
		}
	}
	/*
	FOR_Z(i, V)
	{
		printf("%d    %d    %d\n",i, ans[i], dist[i]);
	}
	*/
	if(dist[dest] > 10000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d  %d \n",dist[dest], ans[dest]);
		double a = dist[dest], b = ans[dest];
		float ANS = a/b;
		printf("%.1f\n",ANS);
	}
}
int main()
{
    fast;
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	int V, E, v, u, w;
		scanf("%d %d",&V,&E);
		Graph g(V, E);
		vector< pair<int, int> > adj[V];
		FOR_Z(i, E)
		{
			scanf("%d %d %d",&v,&u,&w);
			g.addEdge(v - 1, u - 1, w);
		}
		//g.display();
		int a, b;
		scanf("%d %d",&a, &b);
		g.number_edges(a - 1, b - 1);
    }
    return 0;
}
//Short_in_Average.cpp
/*
2
3 3
1 2 1
2 3 2
3 2 3
1 3
3 3
1 2 10
2 3 1
3 2 1
1 3
*/