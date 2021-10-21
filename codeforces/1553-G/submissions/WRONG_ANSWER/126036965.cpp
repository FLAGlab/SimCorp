#include <bits/stdc++.h>
#define ppp pair<int,int>
using namespace std;
const int n=1e6+5;
int nn,q,a[n],wei[n],p[n];
int f[n],color[n],d[n],top;
int find(int x){
 if(x==f[x])
 return x;
 return f[x]=find(f[x]);
}
ppp k1[100000];
int main(){
 int i,j,k;
	cin>>nn>>q;
 for(i=1;i<=nn;i++)
		cin>>a[i],f[i]=i,wei[a[i]]=i;
 for(i=2;i<n;i++){
 if(p[i])continue;
 for(int j=i,pp=-1;j<n;j+=i){
 if(wei[j]){
 if(pp==-1)color[i]=find(wei[j]);
 else f[find(pp)]=find(wei[j]);
				pp=wei[j];
 }
			p[j]=i;
 }
 }
 for(i=2;i<n;i++)
 if(p[i]==i)
			color[i]=find(color[i]);
 int c=0;
 for(i=1;i<=nn;i++,c=0){
 int az=a[i]+1;
		d[++c]=find(i);
 while(az>1)
			d[++c]=color[p[az]],az/=p[az];
		sort(d+1,d+c+1);
		c=unique(d+1,d+c+1)-d-1;
 for(k=1;k<c;k++)
 for(j=k+1;j<=c;j++)
				k1[++top]=make_pair(d[k],d[j]);
 }
	sort(k1+1,k1+top+1);
 for(int i=1;i<=q;i++){
 int x,y;
		cin>>x>>y;
		x=find(x);
		y=find(y);
 if(x==y)
			cout<<0<<'\n';
 else{
			ppp ask=make_pair(min(x,y),max(x,y));
 int jz=lower_bound(k1+1,k1+top+1,ask)-k1;
 if(1<=jz&&jz<=top&&k1[jz]==ask)
				cout<<1<<'\n';
 else
				cout<<2<<'\n';
 } 
 }
 return 0;
}
