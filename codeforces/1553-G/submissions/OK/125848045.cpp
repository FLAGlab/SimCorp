#include<bits/stdc++.h>
using namespace std;
const int N = 3e6;
int n,q,a[N+5],pre[N+5],id[N+5],b[N+5],col[N+5],d[N+5];
vector<pair<int, int> > res;
 
inline int read(){
 int x=0;char c=getchar();
 while(c>'9'||c<'0') c=getchar();
 while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
 return x;
}
inline int findr(int x){
 return pre[x]==x?x:pre[x]=findr(pre[x]);
}
signed main(){
	n=read(),q=read();
 for(register int i=1;i<=n;++i)
		a[i]=read(),id[a[i]]=i,pre[i]=i;
 for(register int i=2;i<=N;++i)
 if(!b[i])
 for(register int j=i,p=-1;j<=N;j+=i){
 if(id[j]){
 if(p==-1)
						col[i]=findr(id[j]);
 else pre[findr(p)]=findr(id[j]);
					p=id[j];
 }
				b[j]=i;
 }
 for(register int i=2;i<=N;++i)
 if(b[i]==i)
			col[i]=findr(col[i]);
 for(register int i=1,temp=a[i]+1,len=0;i<=n;temp=a[++i]+1,len=0){
		d[++len]=findr(i);
 while(temp>1){
			d[++len]=col[b[temp]];
			temp/=b[temp];
 }
		sort(d+1,d+len+1);
		len=unique(d+1,d+len+1)-d-1;
 for(register int j=1;j<len;++j)
 for(register int k=j+1;k<=len;++k)
				res.push_back(make_pair(d[j],d[k]));
 }
	sort(res.begin(),res.end());
 while(q--){
 int x=findr(read()),y=findr(read());
 if(x>y) x^=y^=x^=y;
 if(x==y)
			puts("0");
 else{ 
			pair<int,int> temp=make_pair(x,y);
 vector<pair<int,int> >::iterator it = lower_bound(res.begin(),res.end(),temp);
			puts((it!=res.end()&& *it==temp )?"1":"2");
 }
 }
 return 0;
}
