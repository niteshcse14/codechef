#include <bits/stdc++.h>
using namespace std;
int a[40000][40000];
int b[40000][40000];
int t, n, m;
int main()
{
	scanf("%d", &t);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
			{
				scanf("%d", &a[i][j]);
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
			{
				scanf("%d", &a[i][j]);
			}
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				C[i][j]=A[i][j]-B[i][j];
			}
		}
		int points[n+m]={0};
		bool flag=true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if((C[i][j]+C[0][0]-C[0][j]-C[i][0])!=0)
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
		{
			for(i=0;i<n;i++)
			{
				points[i]=(C[i][0]-C[0][0]);
			}

			for(i=0;i<m;i++)
			{
				points[n+i]=-C[0][i];
			}
			qsort(points,(n+m), sizeof(int), cmpfunc);
			
			int k=(n+m)/2;
			long long int sum=0;
			for(int x:points)
			{
				sum+=abs(x-points[k]);
			}
			cout<<sum<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
	}
}