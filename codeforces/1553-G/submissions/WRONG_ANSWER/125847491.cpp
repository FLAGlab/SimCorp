#include<bits/stdc++.h>
#define pa pair<int,int>
#define mp make_pair
using namespace std;
const int mm=1e5+5,mx=1e6+5;
int n,q,st,t,s1,ma,t1,a[mm],fa[mm],pos[mx],pr[mx],b[mm],col[mx];
set<pa> s;
inline int find(int x){
 if(x==fa[x]) return x;
 return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		fa[i]=i;
		pos[a[i]]=i;
		ma=max(ma,a[i]);
 }
 for(int i=2;i<=ma+1;++i){
 if(pr[i]) continue;
 for(int j=i,pre=-1;j<=ma+1;j+=i){
			pr[j]=i;
 if(!pos[j]) continue;
 if(pre==-1) col[i]=find(pos[j]);
 else fa[find(pre)]=find(pos[j]);
			pre=pos[j];
 }
 }
 for(int i=2;i<=ma+1;++i) if(pr[i]==i) col[i]=find(col[i]);
 for(int i=1,sum=0,j;i<=n;++i,sum=0){
		b[++sum]=find(i),j=a[i]+1;
 while(j>1){
			b[++sum]=col[pr[j]];
 int x=pr[j];
 while(!(j%x)) j/=x;
 }
 for(int k=1;k<=sum;++k)
 for(int l=k+1;l<=sum;++l)
				s.insert(mp(b[k],b[l]));
 }
 for(int i=1;i<=q;++i){
		scanf("%d%d",&st,&t);
		s1=find(st),t1=find(t);
 if(s1<t1) swap(s1,t1);
 if(s1==t1) printf("0\n");
 else if(s.count({s1,t1})) printf("1\n");
 else printf("2\n");
 }
 return 0;
}
