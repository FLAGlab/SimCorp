#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
 int t;
	cin>>t;
 while(t--){
		mp.clear();
		string s;
		cin>>s;
 int len=s.size();
 for(int i=0;i<len;i++)  mp[s[i]]++;
 if(mp['A']+mp['C']==mp['B']) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
} 
