#include <bits/stdc++.h>
using namespace std;
 
#define pii pair <int,int>
 
const int N=1e6+5;
 
int n,q,a[N],buc[N],pr[N];
int f[N],col[N],d[N],c;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector <pii> res;
 
int main(){
	cin>>n>>q;
 for(int i=1;i<=n;i++)cin>>a[i],f[i]=i,buc[a[i]]=i;
 for(int i=2;i<N;i++){
 if(pr[i])continue;
 for(int j=i,pre=-1;j<N;j+=i){
 if(buc[j]){
 if(pre==-1)col[i]=find(buc[j]);
 else f[find(pre)]=find(buc[j]);
				pre=buc[j];
 } pr[j]=i;
 }
 }
 for(int i=2;i<N;i++)if(pr[i]==i)col[i]=find(col[i]);
 for(int i=1,p=a[1]+1;i<=n;p=a[++i]+1,c=0){
		d[++c]=find(i);
 while(p>1)d[++c]=col[pr[p]],p/=pr[p];
		sort(d+1,d+c+1),c=unique(d+1,d+c+1)-d-1;
 for(int i=1;i<c;i++)
 for(int j=i+1;j<=c;j++)
				res.push_back({d[i],d[j]});
 } sort(res.begin(),res.end());
 for(int i=1;i<=q;i++){
 int x,y; cin>>x>>y,x=find(x),y=find(y);
 if(x==y)puts("0");
 else{
			pii cur={min(x,y),max(x,y)};
 auto it=lower_bound(res.begin(),res.end(),cur);
			puts(it!=res.end()&&*it==cur?"1":"2");
 } 
 }
 return 0;
}
