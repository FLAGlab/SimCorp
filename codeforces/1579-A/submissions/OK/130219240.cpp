#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
	cin>>t;
 while(t--){
 int sum=0,num=0;
		string s;
		cin>>s;
 for(auto i:s){
 if(i=='B'){
				sum++;
 }else{
				num++;
 }
 }
 if(sum==num){
			cout<<"YES\n"; 
 }else{
			cout<<"NO\n";
 }
 }
} 
