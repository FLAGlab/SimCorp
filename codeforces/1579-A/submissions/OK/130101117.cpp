#include<bits/stdc++.h>
using namespace std;
char c[100];
signed main(){
 int t;
	cin>>t;
 while(t--){
		cin>>c;
 int a=0,b=0;
 for(int i=0;i<strlen(c);i++){
 if(c[i]=='B') a++;
 else b++;
 }
 if(a==b) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
}
