#include<bits/stdc++.h>
using namespace std;
 
int main(){
 int t;
	cin>>t;
 
 while(t--){
		string s;
		cin>>s;
 
 int a=0;
 int b=0;
 int c=0;
 for(int i=0;i<s.length();i++){
 if(s[i]=='a')
				a++;
 if(s[i]=='b')
				b++;
 if(s[i]=='c')
				c++;
 }
 
 if(a+c==b)
			cout<<"YES\n";
 else
			cout<<"NO\n";
 }
 
 return 0;
}
