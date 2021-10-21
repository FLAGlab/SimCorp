#include <bits/stdc++.h>
using namespace std;
int solve(void){
 int n;
	cin>>n;
 vector<int> v(n);
 vector<pair<int,int> > a(n);
 for(int i=0;i<n;++i){
		cin>>v[i];
		a[i]={v[i],i};
 }
	sort(a.begin(),a.end());
 int cnt=0;
 unordered_multiset<int> st;
 for(int i=0;i<n;++i){
 if(i>0&&a[i].first!=a[i-1].first){
			cnt++;
 }
		v[a[i].second]=cnt;
		st.insert(cnt);
 }
 vector<int> d(n),dp1(n),dp2(n),dp3(n);
 unordered_map<int,int> mp;
 for(int i=0;i<n;++i){
 if(st.count(v[i])){
			st.erase(st.find(v[i]));
 }
 if(mp.count(v[i]-1)){
 if(!mp.count(v[i])){
				dp2[i]=max(dp2[i],dp1[mp[v[i]-1]]+1);
 if(!st.count(v[i]-1)){
					dp2[i]=max(dp2[i],dp2[mp[v[i]-1]]+1);
 }
 }
 if(!st.count(v[i]-1)){
				dp3[i]=max(dp3[i],dp2[mp[v[i]-1]]+1);
 }
			dp3[i]=max(dp3[i],dp1[mp[v[i]-1]]+1);
 }
 if(mp.count(v[i])){
			dp1[i]=dp1[mp[v[i]]]+1;
			dp2[i]=max(dp2[i],dp2[mp[v[i]]]+1);
			dp3[i]=max(dp3[i],dp3[mp[v[i]]]+1);
 }
 else{
			dp1[i]=1;
 }
		dp2[i]=max(dp2[i],dp1[i]);
		dp3[i]=max(dp3[i],dp2[i]);
		mp[v[i]]=i;
 }
 return n-*max_element(dp3.begin(),dp3.end());
}
int main(){
 int t;
	cin>>t;
 while(t--){
		cout<<solve()<<'\n';
 }
 return 0;
}
