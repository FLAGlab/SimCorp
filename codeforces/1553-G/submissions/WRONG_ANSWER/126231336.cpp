#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
 
int n,m,a[N],fa[N<<1];
vector<int> ft[N];
map<int,bool> fl[N<<1];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
 
signed main(){
	cin>>n>>m;
 for(int i=2;i<N;i++) if(ft[i].empty())
 for(int j=i;j<N;j+=i) ft[j].push_back(i);
 for(int i=1;i<=N+n;i++) fa[i]=i;
 for(int i=1;i<=n;i++){
		cin>>a[i];
 for(auto y:ft[a[i]]) fa[find(i)]=find(y+n);
 }
 for(int i=1;i<=n;i++){
 for(auto x:ft[a[i]]) for(auto y:ft[a[i]+1]) fl[find(x+n)][find(y+n)]=1;
 for(auto x:ft[a[i]+1]) for(auto y:ft[a[i]+1]) fl[find(x+n)][find(y+n)]=1;
 }
 while(m--){
 int x,y,fx,fy;
		cin>>x>>y,fx=find(x),fy=find(y);
		cout<<(fx==fy)?0:((fl[fx][fy]||fl[fy][fx])?1:2)<<'\n';
 }
}
