#include<bits/stdc++.h>
 
using namespace std;
 
char s[1123];
 
signed main(){
 int t;
	cin>>t;
 while(t--){
		cin>>s;
 int num = 0;
 for(int i = 0;i < strlen(s);i++){
 if(s[i] == 'B') num++;
 }
 if(num*2 == strlen(s)) cout<<"YES"<<endl;
 else cout<<"NO"<<endl; 
 }
 return 0;
} 
