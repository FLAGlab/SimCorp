#include<bits/stdc++.h>
#define N 1000005
using namespace std;
inline int read(){
 int x=0,f=1;
 char ch=getchar();
 while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
 return x*f;
}
int n,q,a[N],t[N],pr[N];
int f[N],col[N],d[N],c;
int find(int x){
 return f[x]==x?x:f[x]=find(f[x]);
}
vector <pair<int,int> > res;
signed main(){
	n=read(),q=read();
 for(int i=1;i<=n;i++) a[i]=read(),f[i]=i,t[a[i]]=i;
 for(int i=2;i<N;i++){
 if(pr[i])continue;
 for(int j=i,pre=-1;j<N;j+=i){
 if(t[j]){
 if(pre==-1)col[i]=find(t[j]);
 else f[find(pre)]=find(t[j]);
				pre=t[j];
 } pr[j]=i;
 }
 }
 // for(int i=1;i<=n;++i) cout<<find(i)<<' ';
 // cout<<endl;
 for(int i=2;i<N;i++)if(pr[i]==i)col[i]=find(col[i]);
 for(int i=1,p=a[1]+1;i<=n;p=a[++i]+1,c=0){
		d[++c]=find(i);
 while(p>1) d[++c]=col[pr[p]],p/=pr[p];
		sort(d+1,d+c+1);
		c=unique(d+1,d+c+1)-d-1;
 for(int i=1;i<c;i++){
 for(int j=i+1;j<=c;j++){
				res.push_back({d[i],d[j]});
 }
 }
 }
	sort(res.begin(),res.end());
 for(int i=1;i<=q;i++){
 int x=read(),y=read();
		x=find(x),y=find(y);
 if(x==y)puts("0");
 else{
			pair<int,int> cur={min(x,y),max(x,y)};
 auto it=lower_bound(res.begin(),res.end(),cur);
			puts(it!=res.end()&&*it==cur?"1":"2");
 // cout<<(*it).first<<' '<<(*it).second<<endl;
 } 
 }
 return 0;
}
