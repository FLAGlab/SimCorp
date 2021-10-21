#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,P=1e9+7;
char S[N],T[N];
int n,ch[N][26],fail[N],len[N],tot,lst,diff[N],slink[N],g[N],dp[N];
int find(int u,int i) {
 while(S[i]!=S[i-len[u]-1])
		u=fail[u];
 return u;
}
void ins(int ps,int c) {
 int nw=find(lst,ps);
 if(!ch[nw][c]) {
		ch[nw][c]=++tot;
		len[tot]=len[nw]+2;
 if(nw>1)fail[tot]=ch[find(fail[nw],ps)][c];
 else fail[tot]=2;
		diff[tot]=len[tot]-len[fail[tot]];
 if(diff[tot]==diff[fail[tot]])slink[tot]=slink[fail[tot]];
 else slink[tot]=fail[tot];
 }
	lst=ch[nw][c];
}
int main() {
	len[1]=-1;len[2]=0;fail[2]=1;tot=2;
	diff[2]=1;//slink[2]=1;
	scanf("%s",T+1);
	n=strlen(T+1);
 for(int i=1;i<=n;i+=2)S[i]=T[(i+1)/2];
 for(int i=2;i<=n;i+=2)S[i]=T[n-i/2+1];
	lst=2;
	dp[0]=1;
 for(int i=1;i<=n;++i) {
		ins(i,S[i]-'a');
 for(int j=lst;j>1;j=slink[j]) {
 if(slink[j]!=fail[j])g[j]=(g[fail[j]]+dp[i-len[slink[j]]-diff[j]])%P;
 else g[j]=dp[i-len[slink[j]]-diff[j]];
 if(i%2==0)(dp[i]+=g[j])%=P;
 }
 }
	printf("%d",dp[n]);
 return 0;
}
