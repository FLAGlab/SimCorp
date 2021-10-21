#include<bits/stdc++.h>
#define N 1111111
#define M 1000000007
using namespace std;
int n,i,j,p,id,R,L[N],F[N],c[N][26],df[N],sk[N],f[N],_f[N];
char s[N],ss[N];
void add(int z,int n){
 for(;s[n-L[p]-1]!=s[n];p=F[p]);
 if(!c[p][z]){
 int q=++id,k=F[p];
		L[q]=L[p]+2;
 for(;s[n-L[k]-1]!=s[n];k=F[k]);
		F[q]=c[k][z];c[p][z]=q;
		df[q]=L[q]-L[F[q]];
		sk[q]=(df[q]==df[F[q]]?sk[F[q]]:F[q]);
 }
	p=c[p][z];
}
int main(){
	scanf("%s",ss+1);R=strlen(ss+1);
 for(i=1,j=R;i<=j;i++,j--)s[++n]=ss[i],s[++n]=ss[j];
	id=F[0]=1;L[1]=-1;_f[0]=1;f[0]=1;
 for(i=1;i<=n;i++){
		add(s[i]-'a',i);
 for(int x=p;x;x=sk[x]){
			_f[x]=f[i-L[sk[x]]-df[x]];
 if(df[F[x]]==df[x])_f[x]=(_f[x]+_f[F[x]])%M;
			f[i]=(f[i]+_f[x])%M;
 }
 if(i&1)f[i]=0;
 }
	printf("%d\n",f[n]);
}
