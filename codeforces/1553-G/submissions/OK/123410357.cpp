#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int n,q,a[N],fa[N],dd[N];
set<pair<int,int>>s;
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int main()
{
 for(int i=1;i<N;i++)fa[i]=i;
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++){
 vector<int>d;
		scanf("%d",&a[i]);
 int x=a[i];
 for(int j=2;j*j<=x;j++)if(x%j==0){
			dd[i]=j;
			d.push_back(j);
 while(x%j==0)x/=j;
 }
 if(x>1)d.push_back(x),dd[i]=x;
 for(int j=1;j<d.size();j++)if(Find(d[j])!=Find(d[j-1]))fa[Find(d[j])]=Find(d[j-1]);
 }
 for(int i=1;i<=n;i++){
 int x=a[i]+1;
 vector<int>d;
 for(int j=2;j*j<=x;j++)if(x%j==0){
			d.push_back(j);
 while(x%j==0)x/=j;
 }
 if(x>1)d.push_back(x);
		d.push_back(dd[i]);
 for(int j=0;j<d.size();j++)for(int k=j+1;k<d.size();k++)
 if(Find(d[j])!=Find(d[k])){
 int p=Find(d[j]);
 int q=Find(d[k]);
 if(p>q)swap(p,q);
				s.insert(make_pair(p,q));
 }
 }
 while(q--){
 int i,j;
		scanf("%d%d",&i,&j);
		i=Find(dd[i]);
		j=Find(dd[j]);
 if(i>j)swap(i,j);
 if(i==j)printf("0\n");
 else if(s.count(make_pair(i,j)))printf("1\n");
 else printf("2\n");
 }
}
