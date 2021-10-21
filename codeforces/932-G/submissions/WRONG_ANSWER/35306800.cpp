#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
 
#define pb push_back
#define mp make_pair
 
using namespace std;
 
template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }
 
typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;
 
const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;
 
const int N=1e6+200;
 
int gi() {
 int w=0;bool q=1;char c=getchar();
 while ((c<'0'||c>'9') && c!='-') c=getchar();
 if (c=='-') q=0,c=getchar();
 while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
 return q? w:-w;
}
 
char s1[N],s2[N];
int s[N],ans[N],fr[N],f[N];
int son[N][26],fail[N],len[N],tot,last;
int anc[N],dif[N];
int sum[N];
const int mod=1e9+7;
inline int add(int p,int k) {
 while (s[k]!=s[k-len[p]-1]) p=fail[p];
 if (!son[p][s[k]]) {
		len[++tot]=len[p]+2;
 int t=fail[p];while (s[k]!=s[k-len[t]-1]) t=fail[t];
		fail[tot]=t=son[t][s[k]],son[p][s[k]]=tot;
		dif[tot]=len[tot]-len[t],anc[tot]=dif[tot]==dif[t]?anc[t]:t;
 }
 return son[p][s[k]];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	scanf("%s",s1+1);
 int n=strlen(s1+1),nn=0,i,k;
 for (i=1;i<=n/2;i++)
		s[++nn]=s1[i]-'a',s[++nn]=s1[n+1-i]-'a';
 
	last=0,tot=1,len[1]=-1,fail[0]=fail[1]=1;
	ans[0]=1;
 for (i=1;i<=n;i++) {
		last=add(last,i);
 for (k=last;k;k=anc[k]) {
			f[k]=ans[i-len[anc[k]]-dif[k]];
 if (anc[k]!=fail[k])
 (f[k]+=f[fail[k]])%=mod;
 if (!(i&1))
 (ans[i]+=f[k])%=mod;
 }
 //if (!(i&1)&&s[i-1]==s[i]&&ans[i-2]<ans[i])
 //ans[i]=ans[i-2],fr[i]=i-2;
 }
	printf("%d\n",ans[n]);
 return 0;
}
