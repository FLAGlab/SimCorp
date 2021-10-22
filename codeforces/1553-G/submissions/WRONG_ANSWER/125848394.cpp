#include<bits/stdc++.h>
#define pa pair<int,int>
#define mp make_pair
using namespace std;
const int mm=1e5+5,mx=1e6;
int n,q,st,t,s1,ma,t1,a[mm],fa[mx],pos[mx],pr[mm],b[mm],col[mx];
set<pa> s;
inline int find(int x){
 if(x==fa[x]) return x;
 return fa[x]=find(fa[x]);
}
signed main(){
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		pos[a[i]]=1;
		ma=max(ma,a[i]);
 }
 for(int i=1;i<=ma+1;++i) fa[i]=i;
 for(int i=2;i<=ma+1;++i){
 if(pr[i]) continue;
 for(int j=i;j<=ma+1;j+=i){
			pr[j]=i;
 if(!pos[j]) continue;
 int f1=find(i),f2=find(j);
			fa[f1]=f2;
 }
 }
 for(int i=2;i<=ma+1;++i) if(pr[i]==i) col[i]=find(fa[i]);
 for(int i=1,sum=0,j;i<=n;++i,sum=0){
		b[++sum]=find(a[i]),j=a[i]+1;
 while(j>1){
			b[++sum]=col[pr[j]];
 int x=pr[j];
 while(!(j%x)) j/=x;
 }
		sort(b+1,b+sum+1);
 for(int k=1;k<=sum;++k)
 for(int l=k+1;l<=sum;++l)
				s.insert(mp(b[k],b[l]));
 }
 for(int i=1;i<=q;++i){
		scanf("%d%d",&st,&t);
		s1=find(a[st]),t1=find(a[t]);
 if(s1>t1) swap(s1,t1);
 if(s1==t1) printf("0\n");
 else if(s.count({s1,t1})) printf("1\n");
 else printf("2\n");
 }
 return 0;
}
