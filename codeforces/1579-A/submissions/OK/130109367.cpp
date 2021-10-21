#include<iostream>
using namespace std;
int main(){
 int T;cin >> T;
 while(T--){
		string s;cin >> s;
 int a=0,b=0,c=0;
 for(int i=0;i<s.length();i++){
 if(s[i]=='B') a++;
 else b++;
 }
 if(a==b) cout<<"YES\n";
 else cout<<"NO\n";
 }
} 
