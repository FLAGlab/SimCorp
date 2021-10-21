#include <bits/stdc++.h>
using namespace std;
 
int a[1000010];
long long x[100010],l,r,ans,maks,n;
bool p;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin>>n;
	maks=-1;
 for(int i=1;i<=n;i++){
		cin>>x[i];
		a[x[i]]++;
 }
 for(int i=1;i<=1000000;i++){
 if(a[i]>maks){
			ans=i;
			maks=a[i];
 }
 }
 for(int i=1;i<=n;i++){
 if(x[i]==ans){
 if(!p){
				l=i;
				p=true;
 }
 else{
				r=i;
 }
 }
 }
	cout<<l<<" "<<r<<endl;
 
 return 0;
}
