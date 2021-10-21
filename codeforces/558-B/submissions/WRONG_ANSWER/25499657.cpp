#include<bits/stdc++.h>
using namespace std;
 
int n, a[100005], l, r;
map<int, int> mp;
int num , mx=0;
 
int main(){
	cin>>n;
 for(int i=0; i<n; i++) cin>>a[i];
 
 for(int i=0; i<n; i++){
		mp[a[i]]++;
 if(mx<mp[a[i]]){
			mx=mp[a[i]];
			num=a[i];
			r=i+1;
 }
 }
 
 for(int i=0; i<n; i++){
 if(a[i]==num){
			cout<<i+1<<" "<<r;
 break;
 }
 }
 
}
