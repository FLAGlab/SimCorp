#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
	cin>>t;
 while(t--){
 int b=0, m=0;
 char s[50];
		cin>>s;
 for(int i=0; i<strlen(s); i++){
 if(s[i]=='A' || s[i]=='C') m++;
 else b++;
 }
 if(b==m) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
}
