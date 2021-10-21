#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1000007;
char str[maxn];
 
struct PAM{
 int next[maxn][26];
 int fail[maxn];
 int cnt[maxn];
 int num[maxn];
 int len[maxn];
 int S[maxn];
	ll dp[maxn];
 int dif[maxn];
 int anc[maxn];
	ll sum[maxn];//等差数列的border贡献和，记录在最长的回文节点上
 int last,n,sz;
 int newnode(int l){
 for(int i=0;i<26;i++){
			next[sz][i]=0;
 }
		cnt[sz]=0;
		len[sz]=l;
 return sz++;
 }
 void init(){
		sz=0;
		newnode(0);
		newnode(-1);
		last=0;
		n=0;
		S[n]=-1;
		fail[0]=1;
		dp[0]=1;
 }
 int getfail(int x){
 while(S[n-len[x]-1]!=S[n])x=fail[x];
 return x;
 }
 void insert(char ch){
 int c=ch-'a';
		S[++n]=c;
 int u=getfail(last);
 if(!next[u][c]){
 int v=newnode(len[u]+2);
			fail[v]=next[getfail(fail[u])][c];
			next[u][c]=v;
			num[v]=num[fail[v]]+1;
 }
		last=next[u][c];
		cnt[last]++;
		dif[last]=len[last]-len[fail[last]];
		anc[last]=(dif[last]==dif[fail[last]]?anc[fail[last]]:fail[last]);
 //cout<<len[fail[last]]<<' '<<dif[last]<<' '<<len[anc[last]]<<endl;
 int p=last;
 while(p){
 if(anc[p]==fail[p]){
				sum[p]=dp[n-len[p]];
 }
 else if(anc[p]==0){
				sum[p]=(sum[fail[p]]+dp[n-1])%mod;
 }
 else {
				sum[p]=(sum[fail[p]]+dp[n-len[anc[p]]])%mod;
 }
 if(n%2==0)dp[n]=(dp[n]+sum[p])%mod;
			p=anc[p];
 }
 }
	ll count(){
		ll ret=0;
 for(int i=sz-1;i;i--){
			cnt[fail[i]]+=cnt[i];
			ret=(ret+cnt[i])%mod;
 }
 return ret;
 }
}pam;
 
int main(){
	scanf("%s",str);
 int len=strlen(str);
	pam.init();
 for(int i=1;i<=len/2;i++){
		pam.insert(str[i-1]);
		pam.insert(str[len-i]);
 }
	printf("%lld\n",pam.dp[len]);
}
