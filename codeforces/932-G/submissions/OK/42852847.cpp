#include <bits/stdc++.h>
using namespace std;
#define N 1110010
#define M 1000000007
char s[N],t[N];
int ch[N][27],fail[N],diff[N],anc[N],f[N],g[N],Len[N],id,p;
void add(int c,int n){
 for (;s[n-Len[p]-1]!=s[n];p=fail[p]);
 if (!ch[p][c]){
 int q=++id,k=fail[p];
 Len[q]=Len[p]+2;
 for (;s[n-Len[k]-1]!=s[n];k=fail[k]);
		fail[q]=ch[k][c];
		ch[p][c]=q;
		diff[q]=Len[q]-Len[fail[q]];
		anc[q]=(diff[q]==diff[fail[q]]?anc[fail[q]]:fail[q]);
 }
	p=ch[p][c];
}
int main(){
	scanf("%s",t+1); int len=strlen(t+1); int n=0;
 for (int i=1,j=len;i<=j;i++,j--)
		s[++n]=t[i],s[++n]=t[j];
//	printf("%s\n",s+1); printf("%d\n",n);
	fail[0]=fail[1]=1; Len[1]=-1; id=1; f[0]=1; g[0]=1;
 for (int i=1;i<=n;i++){
		add(s[i]-'a',i);
 for (int x=p;x;x=anc[x]){
			g[x]=f[i-Len[anc[x]]-diff[x]];
 if (diff[fail[x]]==diff[x]) (g[x]+=g[fail[x]])%=M;
 (f[i]+=g[x])%=M;
 }
 if (i&1) f[i]=0;
 }
	printf("%d\n",f[n]);
 return 0;
}
