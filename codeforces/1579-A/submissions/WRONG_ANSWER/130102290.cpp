#include<bits/stdc++.h>
using namespace std;
 
signed main() {
 int t;
	cin>>t;
 while(t--){
		string s;
		cin>>s;
 int a = 0;
 int b = 0;
 for(int i = 0; i < s.length(); i++){
 if(s[i] == 'A' || s[i] == 'C') a++;
 else b++;
 } 
 if(b >= a) cout<<"YES";
 else cout<<"NO";
		cout<<endl;
 }
 return 0;
}
