#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
 
int n,m,_=2000005,a[N],fa[N<<1];
bool np[N];
vector<int> ft[N];
unordered_map<int,bool> fl[N<<1];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
void merge(int x,int y){
 int fx=find(x),fy=find(y);
 if(fx!=fy) fa[fx]=fy;
}
 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
 for(int i=2;i<N;i++)
 if(!np[i]){
			ft[i].push_back(i);
 for(int j=i+i;j<N;j+=i) ft[j].push_back(i),np[j]=1;
 }
 for(int i=1;i<=_;i++) fa[i]=i;
 for(int i=1;i<=n;i++){
		cin>>a[i];
 for(auto y:ft[a[i]]) merge(i,y+n);
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
