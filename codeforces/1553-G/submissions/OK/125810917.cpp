#include<bits/stdc++.h>
using namespace std;
int n,q,ma,a[2000005],f[2000005],sz[2000005];
vector<int>p[2000005];
set<pair<int,int> >s;
int find(int x){
 if(x==f[x])return x;
 return f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ma=max(ma,a[i]);
 for(int i=1;i<=ma+1;i++)
		f[i]=i;
 for(int i=2;i<=ma+1;i++) 
 if(p[i].empty())
 for(int j=i;j<=ma+1;j+=i)
				p[j].push_back(i),sz[j]++;
 for(int i=1;i<=n;i++)
 for(int j=0;j<sz[a[i]];j++)
			f[find(a[i])]=find(p[a[i]][j]);
 for(int i=1;i<=n;i++){
 vector<int>pp=p[a[i]+1];
		pp.push_back(a[i]);
 int qwq=pp.size();
 for(int i=0;i<qwq;i++)
 for(int j=i+1;j<qwq;j++){
 int x=find(pp[i]),y=find(pp[j]);
 if(x!=y){
 
 if(x>y)swap(x,y);
					s.insert(make_pair(x,y));
 }
 }
 }
 int x,y;
 while(q--){
		scanf("%d%d",&x,&y);
		x=find(a[x]),y=find(a[y]);
 if(x>y)swap(x,y);
 if(x==y)puts("0");
 else if(s.count(make_pair(x,y)))puts("1");
 else puts("2");
 }
 return 0;
}
