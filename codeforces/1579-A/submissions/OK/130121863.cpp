#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
	cin>>t;
 while(t--){
 char a[100];int x=0,y=0;
		cin>>a;
 for(int i=0;i<strlen(a);i++){
 if(a[i]=='A'||a[i]=='C')x++;
 else y++;
 }
 if(x==y)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
} 
