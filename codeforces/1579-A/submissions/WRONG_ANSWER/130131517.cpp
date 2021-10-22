#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
	cin>>t;
 while(t--){
 char s[55];
		cin>>s;
 int a=0,b=0,c=0;
 for(int i=0;i<strlen(s);i++){
 if(s[i]=='A')a++;
 if(s[i]=='B')b++;
 if(s[i]=='C')c++;
 }
		cout<<a<<" "<<b<<" "<<c<<endl;
 if(a+c==b)
		cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
}
