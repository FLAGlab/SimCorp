#include <bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
int a[1000010],n,l[1000010],fa[1000010],anc[1000010],lst,p,f[1000010],g[1000010],ch[1000010][26],d[1000010];
char t[1000010];
void qmo(int &x){
	x+=(x>>31)&mod;
}
void ins(int c,int id){
 int x=lst;
 for(;c!=a[id-l[x]-1];x=fa[x]);
 if(!ch[x][c]){
		l[++p]=l[x]+2;
 int y=fa[x];
 for(;c!=a[id-l[y]-1];y=fa[y]);
		d[p]=l[p]-l[fa[p]=ch[y][c]],ch[x][c]=p;
 if(d[p]==d[fa[p]]) anc[p]=anc[fa[p]];
 else anc[p]=fa[p];
 }
	lst=ch[x][c];
}
int main(){
	scanf("%s",t+1),n=strlen(t+1);
 for(int i=1;i<=n/2;i++) a[2*i-1]=t[i]-'a',a[2*i]=t[n-i+1]-'a';
	a[0]=l[1]=-1,l[0]=fa[1]=0,fa[0]=f[0]=lst=p=1;
 for(int i=1;i<=n;i++){
		ins(a[i],i);
 for(int j=lst;j;j=anc[j]){
			g[j]=f[i-l[anc[j]]-d[j]];
 if(anc[j]!=fa[j]) qmo(g[j]+=g[fa[j]]-mod);
 if(!(i&1)) qmo(f[i]+=g[j]-mod);
 }
 }
	printf("%d\n",f[n]);
}
//test
 
