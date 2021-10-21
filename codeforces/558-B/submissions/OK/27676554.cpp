#include <iostream>
#include <map>
using namespace std;
int i,a,n,c[1000005][2],k,ans1,ans2,mn=INT_MAX,mx;
map <int,int> mp;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
 for(i=1;i<=n;i++){
		cin>>a;
 if(mp[a]==0) c[a][0]=i;
		mp[a]++;
		c[a][1]=i;
		mn=min(a,mn);
		mx=max(a,mx);
 }
 for(i=mn;i<=mx;i++){
 if(mp[i]>=k){
 if(mp[i]>k){k=mp[i]; ans1=c[i][0]; ans2=c[i][1];}
 else { if(ans2-ans1>c[i][1]-c[i][0]){ ans1=c[i][0]; ans2=c[i][1];}}
 }
 }
	cout<<ans1<<" "<<ans2;
}
