#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
signed main(){
 int t;
	cin>>t;
 while(t--){
		mp.clear();
		string str;
		cin>>str;
 for(int i=0;i<str.size();i++){
			mp[str[i]]++;
 }
 if(mp['B']==mp['A']+mp['C'])cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 } 
} 
