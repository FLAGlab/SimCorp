#include<bits/stdc++.h>
using namespace std;
long long n,m,i,x,y,a[111111],z;
vector<long long> v[111111],vv[111111],ans;
queue<long long>q;
bool zer(vector<long long>v[111111]){
 for(i=1;i<=n;i++) if(v[i].size()>2) return 0;
 return 1; 
}
bool cyc(vector<long long>v[111111]){
 for(i=1;i<=n;i++){
 if(!a[i]){
			z++;
			q.push(i);
			a[i]=1;
 while(!q.empty()){
				x=q.front();
				vv[z].push_back(x);
				q.pop();
 for(int j=0;j<v[x].size();j++) if(!a[v[x][j]]) a[v[x][j]]=1,q.push(v[x][j]);
 }
 }
 }
 long long s=0;
 for(i=1;i<=z;i++)s+=vv[i].size();
 if(s==n) return 1;
 else return 0;
}
main () {
	cin>>n>>m;
 for(i=1;i<=m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
 }
 if(zer(v) && cyc(v) && n>=m){
		cout<<"YES"<<"\n"<<n-m<<"\n";
		i=2;
 for(i=1;i<=n;i++)if(v[i].size()==1) ans.push_back(i);
 for(i=1;i<ans.size();i+=2){
			cout<<ans[i-1]<<" "<<ans[i]<<"\n";
 }
 }
 else cout<<"NO";
}
