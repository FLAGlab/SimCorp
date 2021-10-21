#include <iostream>
using namespace std;
int i,a,n,c[1000005][2],k,ans1,ans2,mn=INT_MAX,mx,b[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
 for(i=1;i<=n;i++){
		cin>>a;
 if(b[a]==0) c[a][0]=i;
		b[a]++;
		c[a][1]=i;
		mn=min(a,mn);
		mx=max(a,mx);
 }
 for(i=mn;i<=mx;i++){
 if(b[i]>=k){
 if(b[i]>k){k=b[i]; ans1=c[i][0]; ans2=c[i][1];}
 else { if(ans2-ans1>c[i][1]-c[i][0]){ ans1=c[i][0]; ans2=c[i][1];}}
 }
 }
	cout<<ans1<<" "<<ans2;
}
