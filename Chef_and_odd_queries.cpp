#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define po pop_back
using namespace std;
struct seg
{
	int l;
	int r;
	int lb;
};
bool cmp(seg q1,seg q2)
{
	if(q1.lb<q2.lb)
	  return true;
	if(q1.lb>q2.lb)
	  return false;
	if(q1.lb==q2.lb)
	{
		if(q1.r<q2.r)
		   return true;
		else
		   return false;
	}
}
 
 
int mx=100000;
int st,ed;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int t;
	cin>>t;
	while(t--)
	{
	    int n,q;
    	cin>>n;
    	int nb=sqrt(mx);
    	seg s[n];
    	for(int i=0;i<n;i++)
    	{
    		cin>>s[i].l;
    		cin>>s[i].r;
    		s[i].lb=((s[i].l)/nb);
    	}
    	sort(s,s+n,cmp);
    	cin>>q;
    	vector<int> pnt[100001];
    	for(int i=0;i<q;i++)
    	{
    	    int m;
    	    cin>>m;
    	    for(int j=0;j<m;j++)
    	    {
        	    int x;
        	    cin>>x;
        	    pnt[x].pb(i);
    	    }
    	}
    	vector<int> ans[q]; // ans[i] will hold segment nos corres to query
    	
    	st=s[0].l;
    	ed=st;
    	for(int i=0;i<pnt[st].size();i++)
    	{
    	    if(ans[pnt[st][i]].size()>=1)
    	       ans[pnt[st][i]].pop_back();
    	    else
    	       ans[pnt[st][i]].push_back(0);
    	}
    	
    	
    	
    //	int count=0;
    	for(int i=0;i<n;i++)  // for all segments do
    	{
    		while(ed<s[i].r)
    		{
    			ed++;
    			for(int ii=0;ii<pnt[ed].size();ii++)
    			{
        			if(ans[pnt[ed][ii]].size()>=1)
        			{
        			    int kk=ans[pnt[ed][ii]].back();
        			    if(kk==i)
        	                ans[pnt[ed][ii]].pop_back();
        	            else
        	                ans[pnt[ed][ii]].push_back(i);
        			}
        	        else
        	            ans[pnt[ed][ii]].push_back(i);
    			}
    		}
    		while(st>s[i].l)
    		{
    			st--;
    			for(int ii=0;ii<pnt[st].size();ii++)
    			{
        			if(ans[pnt[st][ii]].size()>=1)
        			{
        			    int kk=ans[pnt[st][ii]].back();
        			    if(kk==i)                              // same segment no previously pushed
        	                ans[pnt[st][ii]].pop_back();
        	            else
        	                ans[pnt[st][ii]].push_back(i);
        			}
        	        else
        	            ans[pnt[st][ii]].push_back(i);
    			}
    		}
    		while(ed>s[i].r)
    		{
    			for(int ii=0;ii<pnt[ed].size();ii++)
    			{
        			if(ans[pnt[ed][ii]].size()>=1)
        			{
        			    int kk=ans[pnt[ed][ii]].back();
        			    if(kk==i)
        	                ans[pnt[ed][ii]].pop_back();
        	            else
        	                ans[pnt[ed][ii]].push_back(i);
        			}
        	        else
        	            ans[pnt[ed][ii]].push_back(i);
    			}
    			ed--;
    		}
    		while(st<s[i].l)
    		{
    			for(int ii=0;ii<pnt[st].size();ii++)
    			{
        			if(ans[pnt[st][ii]].size()>=1)
        			{
        			    int kk=ans[pnt[st][ii]].back();
        			    if(kk==i)                              // same segment no previously pushed
        	                ans[pnt[st][ii]].pop_back();
        	            else
        	                ans[pnt[st][ii]].push_back(i);
        			}
        	        else
        	            ans[pnt[st][ii]].push_back(i);
    			}
    			st++;
    		}
    	}
    	
    	for(int i=0;i<q;i++)
    	{
    	    ans[i].pb(n);
    	    int fl=0;
    	    int s=0;
    	    for(int j=0;j<ans[i].size()-1;j++)
    	    {
    	        if(fl==0)
    	        {
    	            s=s+ans[i][j+1]-ans[i][j];
    	            fl=1;
    	        }
    	        else
    	          fl=0;
    	    }
    	    cout<<s<<"\n";
    	}
	}
	return 0;
}  











/*
using bitset solution

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ask l
#define askf r
#define maxn 100010
vector<int>st[maxn],en[maxn];
bitset<maxn>b[maxn],temp;
int t,n,m,q,l,r;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			st[i].clear();
			en[i].clear();
			b[i].reset();
		}
		for(int i=1;i<=n;++i){
			scanf("%d%d",&l,&r);
			r++;
			st[l].pb(i);
			en[r].pb(i);
		}
		temp.reset();
		for(int i=1;i<=n;++i){
			for(int j=0;j<st[i].size();++j)
				temp.set(st[i][j]);
			for(int j=0;j<en[i].size();++j)
				temp.set(en[i][j],0);
			b[i]=temp;
		}
		scanf("%d",&q);
		while(q--){
			temp.reset();
			scanf("%d",&m);
			for(int i=0;i<m;++i){
				scanf("%d",&l);
				temp^=b[l];
			}
			cout<<temp.count()<<"\n";
		}
	}
	return 0;
}
*/