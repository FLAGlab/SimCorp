#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
 
int n,m,_,a[N],fa[N<<1];
bool np[N];
vector<int> ft[N],vp[N<<1];
unordered_map<int,bool> fl[N<<1];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
bool ok(int fx,int y){
 for(auto z:ft[y]) if(fl[fx][z]) return 1;
 return 0;
}
 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
 for(int i=2;i<N;i++)
 if(!np[i]){
			ft[i].push_back(i);
 for(int j=i+i;j<N;j+=i) ft[j].push_back(i),np[j]=1;
 }
 for(int i=1;i<=(_=(N<<1)-1);i++) fa[i]=i;
 for(int i=1;i<=n;i++){
		cin>>a[i];
 for(auto y:ft[a[i]]) merge(i,y+n);
 }
 for(int i=1;i<=_;i++) vp[find(i)].push_back(i);
 for(int i=1;i<=_;i++) if(find(i)==i){
 for(auto x:vp[i]) if(x<=n)
 for(auto y:ft[a[x]+1]) fl[i][y]=1;
 }
 while(m--){
 int x,y,fx,fy;
		cin>>x>>y,fx=find(x),fy=find(y);
 if(fx==fy) cout<<"0\n";
 else if(ok(fx,y)||ok(fy,x)) cout<<"1\n";
 else cout<<"2\n";
 }
 return 0;
}
