#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
	cin>>t;
 while(t--){
		string s;
 int a=0,b=0,c=0;
		cin>>s;
 for(auto x:s){
 if(x=='A')++a;
 else if(x=='B')++b;
 else ++c;
 }
 if(a+c==b)cout<<"YES\n";
 else cout<<"NO\n";
 }
 return 0;
}
