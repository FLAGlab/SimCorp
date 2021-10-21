#include<bits/stdc++.h>
using namespace std;const int N=1e6+7,mod=1e9+7;
int a[N][26],n,k,now,i,anc[N],diff[N],fa[N],len[N],p,f[N],g[N],sz=1;char s[N],t[N];
void add(int c,int n){
 while(s[n-len[p]-1]!=s[n])p=fa[p];
 if(!a[p][c]){
		now=++sz;k=fa[p];
		len[now]=len[p]+2;
 while(s[n-len[k]-1]!=s[n])k=fa[k];
		fa[now]=a[k][c];a[p][c]=now;
		diff[now]=len[now]-len[fa[now]];
		anc[now]=diff[now]==diff[fa[now]]?anc[fa[now]]:fa[now];
 }p=a[p][c];
 for(k=p;k>1;k=anc[k]){
		g[k]=f[n-len[anc[k]]-diff[k]];
 if(diff[k]==diff[fa[k]])(g[k]+=g[fa[k]])%=mod;
 (f[n]+=(n%2==0)*g[k])%=mod;
 }
}
int main(){
	fa[1]=fa[0]=1;len[1]=-1;f[0]=1;
 for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n/2;++i)t[i*2-1]=s[i],t[2*i]=s[n-i+1];
 for(memcpy(s+1,t+1,n),i=1;i<=n;++i)add(s[i]-'a',i);printf("%d\n",f[n]);
}
