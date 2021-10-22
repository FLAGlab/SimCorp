#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
	cin>>t;
 int b[4]={0};
 while(t--){
		string a;
		memset(b,0,12);
		cin>>a;
 for(int i=0;i<a.size();i++){
			b[a[i]-'A']++;
 }
 if((b[0]+b[2])==b[1])cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
} 
