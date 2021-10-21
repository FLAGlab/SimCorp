#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
 
int n,m,a[N],fa[N<<1];
vector<int> ft[N];
unordered_map<int,bool> fl[N<<1];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
 for(int i=2;i<N;i++) if(ft[i].empty())
 for(int j=i;j<N;j+=i) ft[j].push_back(i);
 for(int i=1;i<=N+n;i++) fa[i]=i;
 for(int i=1;i<=n;i++){
		cin>>a[i];
 for(auto y:ft[a[i]]) fa[find(i)]=find(y+n);
 }
 for(int i=1;i<=n;i++) for(auto x:ft[a[i]]) for(auto y:ft[a[i]+1]) fl[find(x+n)][find(y+n)]=1;
 while(m--){
 int x,y,fx,fy;
		cin>>x>>y,fx=find(x),fy=find(y);
 if(fx==fy) cout<<"0\n";
 else if(fl[fx][fy]||fl[fy][fx]) cout<<"1\n";
 else cout<<"2\n";
 }
 return 0;
}
