#include<bits/stdc++.h>
#define int long long//
using namespace std;
int n,x[1000004],y[1000004],flag,ans;
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
 for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
 }
 for(int i=0;i<n;i++){
 for(int j=i;j<n;j++){
 int b=x[i]+x[j],c=y[i]-x[i]*x[i]*2-x[i]*x[j];
			flag=0;
 for(int k=0;k<n;k++){
 if(y[k]>x[k]*x[k]+b*x[k]+c){
					flag=1;
 }
 }
 if(!flag){
				ans++;
 }
 }
 }
	cout<<ans;
 return 0;
}
 
