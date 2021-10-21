#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
 while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
 while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
 return f? -x:x;
}
 
#define pb push_back
 
const int N=2e5+7;
int a[N];
int dp[N][3];
int l[N],r[N];
int pos[N],cnt[N];
 
vector <int> v;
 
int getid(ll x) {return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
 
int main(){
 int T=input();
 while(T--){
		v.clear();
 int n=input();
 
 for(int i=1;i<=n;i++){
			a[i]=input();
			v.pb(a[i]);
 
			dp[i][0]=dp[i][1]=dp[i][2]=0;
			l[i]=r[i]=0;
			cnt[i]=0;
 }
 
		sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
 
 for(int i=1;i<=n;i++){
			a[i]=getid(a[i]);
			r[a[i]]=i;
 if(!l[a[i]]) l[a[i]]=i,pos[a[i]]=i;
			cnt[a[i]]++;
 }
 
 int mx=1;
 
 for(int i=1;i<=n;i++){
			dp[i][0]=dp[pos[a[i]]][0]+1;
			dp[i][1]=max(dp[pos[a[i]]][1]+1,max(dp[pos[a[i]-1]][0]+1,dp[pos[a[i]-1]][2]+1));
 if(i==r[a[i]]) dp[i][2]=dp[l[a[i]]][1]+cnt[a[i]]-1;
			pos[a[i]]=i;
			mx=max(mx,max(dp[i][0],max(dp[i][1],dp[i][2])));
 }
		printf("%d\n",n-mx);
 }
 
}
