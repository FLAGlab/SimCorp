#include <bits/stdc++.h>
 
using namespace std;
int main () {
 int t;
	cin >> t;
 while(t--){
		string s;
		cin >> s;
 int l =  s.length();
 int a=0,c=0;
 for(int i=0; i<l; i++){
 if(s[i]=='A'){
				a++;
 }else if(s[i]=='C'){
				c++;
 }
 }
 if(l/2==(a+c)){
			cout<<"YES"<<endl;
 }else{
			cout<<"NO"<<endl;
 }
 }
}
