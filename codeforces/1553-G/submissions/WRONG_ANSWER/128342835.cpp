#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 150000 + 5;
const int MAX_V = 1000000 + 5;
int n,q,a[MAX_N],fa[MAX_V];
int _find(int x){
 if(fa[x]!=x) fa[x]=_find(fa[x]);
 return fa[x];
}
vector<int> v[MAX_V];
set<pair<int,int> > s;
signed main(){
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++) scanf("%d",&a[i]);
 for(int i=1;i<=1000000;i++) fa[i]=i;
 for(int i=2;i<=1000000;i++){
 if(v[i].empty()){
 for(int j=i;j<=1000000;j+=i)
				v[j].push_back(i);
 }
 }
 for(int i=1;i<=n;i++)
 for(int j=0;j<v[a[i]].size();j++)
			fa[_find(a[i])]=_find(v[a[i]][j]);
 for(int i=1;i<=n;i++){
 vector<int> ve=v[a[i]+1];
		ve.push_back(a[i]);
 for(int j=0;j<ve.size();j++){
 for(int k=j+1;k<ve.size();k++){
 int x=_find(ve[j]),y=_find(ve[k]);
 if(x!=y){
 if(x>y) swap(x,y);
					s.insert(make_pair(x,y));
 }
 }
 }
 }
 while(q--){
 int u,v;
		scanf("%d%d",&u,&v);
		u=_find(a[u]),v=_find(a[v]);
 if(u>v) swap(u,v);
 if(u==v) puts("0");
 else if(s.count(make_pair(u,v))) puts("1");
 else puts("2");
 }
 return 0;
}
