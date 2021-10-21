#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
const int maxn=150005,maxv=1000005;
int n,q,mx,ps;
int a[maxn],c[maxv],p[maxv],f[maxn],mn[maxv],lst[maxv];
map<int,int>mp[maxv];
vector<int>v;
int find(int x){
 return f[x]==x? x:f[x]=find(f[x]);
}
void sieve(int n){
	c[1]=1;
 for(int i=2;i<=n;i++){
 if(c[i]==0)
			p[++ps]=i,mn[i]=i;
 for(int j=1;j<=ps&&i*p[j]<=n;j++){
			c[i*p[j]]=1,mn[i*p[j]]=mn[i];
 if(i%p[j]==0)
 break;
 }
 }
}
int main(){
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx=max(mx,a[i]),f[i]=i;
	mx++,sieve(mx);
 for(int i=1;i<=n;i++){
 int tmp=a[i];
 while(tmp>1){
 int p=mn[tmp];
 while(tmp%p==0)
				tmp/=p;
 if(lst[p]==0)
				lst[p]=i;
 else f[find(i)]=find(lst[p]);
 }
 }
 for(int i=1;i<=n;i++){
 int tmp=a[i]+1;
		v.clear();
 while(tmp>1){
 int p=mn[tmp];
 while(tmp%p==0)
				tmp/=p;
 if(lst[p])
				v.push_back(find(lst[p]));
 }
		v.push_back(find(i));
 for(int a=0;a<v.size();a++)
 for(int b=0;b<v.size();b++)
 if(v[a]!=v[b])
					mp[v[a]][v[b]]=1;
 }
 for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y),x=find(x),y=find(y);
		puts(x==y? "0":((mp[x].count(y)||mp[y].count(x))? "1":"2"));
 }
 return 0;
}
