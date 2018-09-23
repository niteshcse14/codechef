#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int T, V, E, u, v, uu, vv;
int adj[MAX][MAX];
int u_arr[MAX], v_arr[MAX];
bool is_safe(int v, int path[], int pos)
{
	if(adj[path[pos - 1]][v] == 0)
	{
		return false;
	}
	for(int i = 0; i < pos; i++)
	{
		if(path[i] == v)
		{
			return false;
		}
	}
	return true;
}
bool hamlCycle_Util(int path[], int pos)
{
	if(pos == V)
	{
		if(adj[path[pos - 1]][0] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	for(int i = 0; i < V; i++)
	{
		if(is_safe(i, path, pos))
		{
			path[pos] = i;
			if(hamlCycle_Util(path, pos + 1))
			{
				return true;
			}
			path[pos] = -1;
		}
	}
	return false;
}
bool hamlCycle()
{
	int *path = new int[V];
	for(int i = 0; i < V; i++)
	{
		path[i] = -1;
	}
	path[0] = 0;
	if(hamlCycle_Util(path, 1))
	{
		return true;
	}
	return false;
}
int main()
{
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		scanf("%d %d", &uu, &vv);
		adj[uu - 1][vv - 1] = adj[vv - 1][uu - 1] = 1;
		u_arr[i] = uu;
		v_arr[i] = vv;
	}
	if(hamlCycle())
	{
		printf("YES\n");
		for(int i = 0; i < E; i++)
		{
			printf("%d %d\n", u_arr[i], v_arr[i]);
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}