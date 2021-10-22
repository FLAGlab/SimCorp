#include<bits/stdc++.h>
using namespace std;
int a[4];
string s;
signed main(){
 int t; cin>>t;
 while(t--){
		cin>>s;
		a[0]=a[1]=a[2]=0;
 for(int i=0;i<s.size();i++)
			a[s[i]-'A']++;
 if(a[0]+a[2]==a[1]) puts("YES");
 else puts("NO"); 
 }
 return 0;
}
 
