#include <bits/stdc++.h>
using namespace std;
string solve(){
	string str;
	cin>>str;
 map<char,int>mp;
 for(char ch: str){
		mp[ch]++;
 }
 return mp['B']==(mp['A']+mp['C'])?"YES":"NO";
}
int main() {
 int t;
	cin>>t;
 while(t--){
		cout<<solve()<<endl;
 }
 return 0;
}
