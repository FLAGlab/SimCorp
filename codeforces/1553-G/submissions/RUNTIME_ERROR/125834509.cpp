#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define pii pair<int,int>
#define mp make_pair
int n,q,a[N],buc[N],flg[N],f[N],col[N],c,d[N];
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
vector<pii>s;
void pre(){
 for(int i=2;i<N;++i){
 if(flg[i])continue;
 for(int j=i,pre=-1;j<N;j+=i){
 if(buc[j]){
 if(pre==-1)col[i]=get(buc[j]);
 else f[get(pre)]=get(buc[j]);
				pre=buc[j];
 }flg[j]=i;
 }
 }
 for(int i=2;i<N;++i){
 if(flg[i]==i)col[i]=get(col[i]);
 }
 for(int i=1,p=a[1]+1;i<=n;p=a[++i]+1,c=0){
		d[++c]=get(i);
 while(p>1)d[++c]=col[flg[p]],p/=flg[p];
		sort(d+1,d+c+1);c=unique(d+1,d+c+1)-d-1;
 for(int i=1;i<c;++i)
 for(int j=i+1;j<=c;++j){
				s.push_back(mp(d[i],d[j]));
 }
 }sort(s.begin(),s.end());
}
int main() {
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;++i)scanf("%d",a+i),buc[a[i]]=f[i]=i;pre();
 while(q--){
 int x,y;
		scanf("%d%d",&x,&y);x=get(x),y=get(y);
 if(x==y){puts("0");continue;}
		pii tt=mp(min(x,y),max(x,y));
 vector<pii>::iterator z=lower_bound(s.begin(),s.end(),tt);
		puts(z!=s.end()&&*z==tt?"1":"2");
 }
 return 0;
}
