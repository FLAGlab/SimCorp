#include<bits/stdc++.h>
using namespace std;
 
signed main() {
 int t;
	cin>>t;
 while(t--){
		string s;
		cin>>s;
 int countAC=0,countB=0;
 for(char c: s){
 if(c=='A' | c=='C')countAC++;
 if(c=='B') countB++;
 }
 if(countAC==countB)cout<<"YES\n";
 else cout<<"NO\n";
 }
}
