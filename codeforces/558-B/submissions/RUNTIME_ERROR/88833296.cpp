#include <bits/stdc++.h>
 
using namespace std;
 
const int NN=101010;
 
int a[NN];
vector<int> adj[NN*10];
 
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
#endif
 
 int n; cin>>n;
 for(int i=1;i<=n;i++)scanf("%d",a+i);
 
 for(int i=1;i<=n;i++){
		adj[a[i]].push_back(i);
 }
 
 int l=1,r=n,cnt=0;
 for(int i=1;i<NN*10;i++){
 if(adj[i].size()==cnt){
			cnt=adj[i].size();
 if(r-l > adj[i][adj[i].size()-1]-adj[i][0]){
				r=adj[i][adj[i].size()-1];
				l=adj[i][0];
 }
 }
 if(adj[i].size()>cnt){
			cnt=adj[i].size();
			r=adj[i][adj[i].size()-1];
			l=adj[i][0];
 }
 }
 
	cout<<l<<" "<<r<<endl;
 
 return 0;
}
 
 
