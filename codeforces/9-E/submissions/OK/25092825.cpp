#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector < pair<int,int> > ans;
const int maxn=55;
int degree[maxn],fa[maxn];
 
int findfa(int v){
 if (fa[v]==v) return v;
 else return fa[v]=findfa(fa[v]);
}
 
void merge(int v1,int v2){
 int fa1=findfa(v1);
 int fa2=findfa(v2);
 if (fa1!=fa2) fa[fa2]=fa1;
}
bool func(){
 int n,m;
	cin>>n>>m;
 for (int i=1;i<=n;++i) fa[i]=i;
 for (int i=1;i<=m;++i){
 int v1,v2;
		cin>>v1>>v2;
 ++degree[v1];
 ++degree[v2];
 if ( degree[v1]>2 || degree[v2]>2 ) return false;
		merge(v1,v2);
 }
 
 
 for (int i=1;i<=n;++i) if (degree[i]<2) {
 for (int j=1;j<i;++j) if (degree[j]<2 && findfa(i)!=findfa(j) ) {
 ++degree[i];
 ++degree[j];
			merge(i,j);
			ans.push_back( make_pair(j,i) );
 }
 }
 
 for (int i=1;i<=n;++i) if (degree[i]<2) {
 for (int j=i+1;j<=n;++j) if (degree[j]==1 ) {
 ++degree[i];
 ++degree[j];
			merge(i,j);
			ans.push_back( make_pair(i,j) );
 }
 }
 
 for (int i=1;i<=n;++i) if (!degree[i]) ans.push_back( make_pair(i,i) );
 
 int tmp=findfa(1);
 for (int i=2;i<=n;++i) if (findfa(i)!=tmp) return false;
 
	cout<<"YES"<<endl<<ans.size()<<endl;
 for (int i=0;i<ans.size();++i) cout<<ans[i].first<<" "<<ans[i].second<<endl;
 return true; 
}
int main(){
	ios::sync_with_stdio(false);
//	freopen("data.txt","r",stdin);
 if ( !func() ) cout<<"NO"<<endl; 
}
