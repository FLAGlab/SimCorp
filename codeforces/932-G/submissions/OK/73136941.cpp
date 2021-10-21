#include<bits/stdc++.h>
using namespace std;
 
const int N=1010000,mod=1000000007;
inline void reduce(int&x){x+=x>>31&mod;}
int d[N][26],cnt,f[N],fail[N],pre[N],l[N],sz[N],p,n,i,diff[N],ac[N],dp[N],dq[N];
char s[N],t[N];
void add(int c,int n){
 for(;s[n-l[p]-1]!=s[n];p=f[p]);
 if(!d[p][c]){
 int np=++cnt,q=f[p];
		l[np]=l[p]+2;
 for(;s[n-l[q]-1]!=s[n];q=f[q]);
		f[np]=d[q][c];d[p][c]=np;
		diff[np]=l[np]-l[f[np]];
		ac[np]=(diff[np]==diff[f[np]]?ac[f[np]]:f[np]);
 }
	sz[p=d[p][c]]++;
}
 
void PAM(){
	l[1]=-1;f[0]=f[1]=cnt=1;dp[0]=1;
 for(i=1;i<=n;i++){
		add(s[i]-'a',i);
 for(int j=p;j;j=ac[j]){
			dq[j]=dp[i-l[ac[j]]-diff[j]];
 if(ac[j]!=f[j])reduce(dq[j]+=dq[f[j]]-mod);
 if(!(i&1))reduce(dp[i]+=dq[j]-mod);
 }
 }
	cout<<dp[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>(t+1);n=strlen(t+1);
 if(n&1){
		cout<<0<<'\n';
 return 0;
 }
 for(int i=1;i<=n;i+=2){s[i]=t[i/2+1];s[i+1]=t[n-i/2];}
	PAM();
 return 0;
}
