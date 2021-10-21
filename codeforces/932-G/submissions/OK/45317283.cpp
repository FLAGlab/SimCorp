#include<bits/stdc++.h>
#define maxn 1001000
#define mod 1000000007
using namespace std;
int n,lst,cnt,f[maxn],g[maxn],h[maxn];
int anc[maxn],fail[maxn];
int diff[maxn],len[maxn];
int nxt[maxn][26]; 
char s[maxn],A[maxn];
void upd(int& x,int y){
 if((x+=y)>=mod)x-=mod;
}
void append(int n,int w){
 int p;
 for(p=lst;s[n]!=s[n-len[p]-1];p=fail[p]);
 if(!nxt[p][w]){
 int x=++cnt,k=fail[p];
 for(;s[n]!=s[n-len[k]-1];k=fail[k]);
		len[x]=len[p]+2;
		fail[x]=nxt[k][w];
		nxt[p][w]=x;
		diff[x]=len[x]-len[fail[x]];
		anc[x]=diff[x]==diff[fail[x]]?anc[fail[x]]:fail[x];
 }
	lst=nxt[p][w];
} 
int main(){
	scanf("%s",A+1);
	n=strlen(A+1);
 for(int i=1;i<=n/2;++i){
		s[i*2-1]=A[i];
		s[i*2]=A[n+1-i];
 }
	f[0]=1;
	lst=cnt=1;
	fail[0]=1,fail[1]=0;
	len[1]=-1;
 for(int i=1;i<=n;++i){
		append(i,s[i]-'a');
 for(int x=lst;x;x=anc[x]){
	    	g[x]=f[i-len[anc[x]]-diff[x]];
 if(anc[x]!=fail[x])upd(g[x],g[fail[x]]);
 if(i%2==0)upd(f[i],g[x]);
 }
 }
	printf("%d",f[n]);
}
