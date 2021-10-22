#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000001];
int q[100001];
signed main(){
 int n,mx=0,mn=INT_MAX,j=0;
	cin>>n;
 for(int i=1;i<=n;i++){
		cin>>q[i];
		v[q[i]].push_back(i);
		mx=max(mx,(int)v[q[i]].size());
 }
 for(int i=1;i<=1e6;i++){
 if(mx==v[i].size()){
 if(v[i][mx-1]-v[i][0]<mn){
				mn=v[i][mx-1]-v[i][0];
				j=i;
 }
 }
 }
	cout<<v[j][0]<<" "<<v[j][mx-1];
 return 0;
}
