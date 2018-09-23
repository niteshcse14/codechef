#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string g[n];
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        string s;
        cin>>s;
      	//cout<<" dfg"<<s<<"fg";
        int vc[1100];
        memset(vc,0,sizeof(vc));
        char temp=s[s.size()-1];
        vector<char> v;
        if(temp=='L')
            v.push_back(temp);
        if(temp=='R')
            v.push_back(temp);
        if(temp=='D')
            v.push_back(temp);
        if(temp=='U')
            v.push_back(temp);
        vc[int(temp)-65]=3;
        for(int i=s.size()-2;i>=0;i--){
            if(vc[int(s[i])-65]!=3){
                vc[int(s[i])-65]=3;
                v.push_back(s[i]);
                if(v.size()==4)
                    break;
            }
        }
        memset(vc,0,sizeof(vc));
        vector<char> vv;
        for(int i=0;i<s.size();i++){
            if(vc[int(s[i])-65]!=3){
                vc[int(s[i])-65]=3;
                vv.push_back(s[i]);
                if(vv.size()==4)
                    break;
            }
        }
        for(int ii=vv.size()-1;ii>=0;ii--){
            v.push_back(vv[ii]);
        }
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]=='L'){//cout<<"tt";
                for(int j=0;j<n;j++){
                     int c=0;
                     for(int k=0;k<g[j].size();k++){
                        if(g[j][k]=='1')
                            c++;
                     }
                     for(int k=0;k<g[j].size();k++){
                        if(c>0)
                        {
                            g[j][k]='1';
                            c--;
                        }
                        else
                            g[j][k]='0';
                     }
                }
            }
            if(v[i]=='R'){//cout<<"tt";
                for(int j=0;j<n;j++){
                     int c=0;
                     for(int k=0;k<g[j].size();k++){
                        if(g[j][k]=='1')
                            c++;
                     }
                     for(int k=g[j].size()-1;k>=0;k--){
                        if(c>0)
                        {
                            g[j][k]='1';
                            c--;
                        }
                        else
                            g[j][k]='0';
                     }
                }
            }
            if(v[i]=='D'){
                for(int j=0;j<m;j++){
                     int c=0;
                     for(int k=0;k<n;k++){
                        if(g[k][j]=='1')
                            c++;
                     }
                     for(int k=n-1;k>=0;k--){
                        if(c>0)
                        {
                            g[k][j]='1';
                            c--;
                        }
                        else
                            g[k][j]='0';
                     }
                }
 
            }
            if(v[i]=='U'){
 //  cout<<"rtt";
                    for(int j=0;j<m;j++){
                     int c=0;
                     for(int k=0;k<n;k++){
                        if(g[k][j]=='1')
                            c++;
                     }
                     for(int k=0;k<n;k++){
                        if(c>0)
                        {
                            g[k][j]='1';
                            c--;
                        }
                        else
                            g[k][j]='0';
                     }
                }
 
            }
        }
        for(int i=0;i<n;i++){
            cout<<g[i]<<"\n";
        }
    }
}