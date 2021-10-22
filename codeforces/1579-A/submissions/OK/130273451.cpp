#include<bits/stdc++.h>
using namespace std;
 
signed main(){
 int t;cin>>t;
 while(t--){
 vector<int> a(3,0);
		string s;cin>>s;
 for(auto x:s){
			a[x-'A']++;
 }
 if(a[1]==a[0]+a[2]) cout<<"YES\n";
 else cout<<"NO\n";
 }
}
