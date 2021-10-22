#include<bits/stdc++.h>
using namespace std;
inline int read(){
 int x=0,f=1; char s;
 while((s=getchar())<'0'||s>'9') if(s=='-') f=-1;
 while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^'0'),s=getchar();
 return x*f;
}
const int N=1.5e5+5;
int n,q,tot;
int a[N],fa[2000005],num[1000005];
bool ok[1000005];
int find(int x){
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
//	cout<<u<<" - "<<v<<endl;
	u=find(u),v=find(v);
 if(u!=v) fa[u]=v;
}
bool con(int num){
 int u=find(num),v=find(2);
 return u==v;
}
bool cone(int u,int v){
 for(int j=2;j*j<=v+1;++j){
 if((v+1)%j==0){
 if(find(j)==find(u)) return 1;
 if(find((v+1)/j)==find(u)) return 1;
 }
 }
 for(int j=2;j*j<=u+1;++j){
 if((u+1)%j==0){
 if(find(j)==find(v)) return 1;
 if(find((u+1)/j)==find(v)) return 1;
 }
 }
}
signed main(){
	n=read(),q=read(),tot=0;
 for(int i=1;i<=1000000;++i) fa[i]=i;
 for(int i=1;i<=n;++i){
		a[i]=read();
 for(int j=2;j*j<=a[i];++j){
 if(a[i]%j==0){
				merge(a[i],j);
				merge(a[i],a[i]/j);
 }
 }
 }
 while(q--){
 int s=read(),t=read();
 int u=find(a[s]),v=find(a[t]);
 if(u==v){puts("0");continue;}
 if(con(a[s])||con(a[t])||a[t]%(a[s]+1)==0||a[s]%(a[t]+1)==0){
			puts("1"); continue;
 }
		puts("2");
 }
 return 0;
}
/*
5 1
3 8 7 6 25
3 5
*/
