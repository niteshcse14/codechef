#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e6 + 1;
vector<int> adj[MAX];
int dis[MAX];
int T, N, u, v;
int bfs(int v)
{
	memset(dis, -1, sizeof(dis));
	queue<int> q;
	dis[v] = 0;
	q.push(v);
	int u;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		vector<int>::iterator i;
		for(i = adj[u].begin(); i != adj[u].end(); i++)
		{
			if(dis[*i] == -1)
			{
				dis[*i] = dis[u] + 1;
				q.push(*i);
			}
		}
	}
	return u;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 1; i < N; i++)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(N <= 2)
		{
			printf("YES\n");
			continue;
		}
		int first_node = bfs(1);
		int second_node = bfs(first_node);
		int distance = dis[second_node];
		if(dis[bfs(second_node)] < distance)
		{
			printf("YES\n");
		}
		else
		{
			if(dis[bfs(first_node)] < distance)
			{
				printf("YES\n");
			}
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}