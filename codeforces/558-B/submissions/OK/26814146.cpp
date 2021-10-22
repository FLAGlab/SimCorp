#include<bits/stdc++.h>
using namespace std;
int m[1000005],L[1000005];
signed main(){
 int n,x;
 int mx=0,mn=100000001,cnt=-1;
	cin>>n;
 for(int i=0;i<n;i++){
		cin>>x;
 if(m[x] == 0){
			L[x] = i;
			m[x] = 1;
 }
 else m[x]++;
 if(m[x]>mx){
			mx=m[x];
    		mn=i-L[x]+1;
    		cnt=L[x]+1;
 }
 else if(m[x]==mx&&i-L[x]+1<mn){
    		mn=i-L[x]+1;
    		cnt=L[x]+1;
 }
 }
	cout<<cnt<<" "<<cnt+mn-1;
 return 0;
}
