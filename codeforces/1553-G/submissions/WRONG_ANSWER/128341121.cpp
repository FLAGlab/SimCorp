#include<bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=15e4;
const int Maxm=1e6+1;
vector<int>v[Maxm+5];
int minn[Maxm+5],mark[Maxm+5],prime[Maxm+5],cnt;
int a[Maxn+5],visit[Maxm+5],n,m;
int gcd(int a,int b) {
 if(b==0)return a;
 return gcd(b,a%b);
}
void euler() {
 for(ri i=2;i<=Maxm;i++) {
 if(!mark[i])prime[++cnt]=i,minn[i]=i;
 for(ri j=1;j<=cnt&&i<=Maxm/prime[j];j++) {
			mark[i*prime[j]]=1;
			minn[i*prime[j]]=prime[j];
 if(!(i%prime[j]))break;
 }
 }
}
void add(int x) {
 int t=x;
 while(t!=1) {
		v[x].push_back(minn[t]);
		t/=minn[t];
 }
}
bool check(int s,int t) {
 int lx=(int)v[s].size();
 for(ri i=0;i<lx;i++)visit[v[s][i]]=1;
 int ly=(int)v[s+1].size();
 for(ri i=0;i<ly;i++)visit[v[s+1][i]]=1;
 int lz=(int)v[t].size(),ans=0;
 for(ri i=0;i<lz;i++)
 if(visit[v[t][i]]) {
			ans=1;break;
 }
 for(ri i=0;i<lx;i++)visit[v[s][i]]=0;
 for(ri i=0;i<ly;i++)visit[v[s+1][i]]=0;
 return ans;
}
signed main() {
	scanf("%d%d",&n,&m);
	euler();
 for(ri i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		add(a[i]);
		add(a[i]+1);
 }
 for(ri i=1;i<=m;i++) {
 int s,t;
		scanf("%d%d",&s,&t);
 if(gcd(s,t)>1)printf("0\n");
 else if(check(a[s],a[t])||check(a[t],a[s]))printf("1\n");
 else printf("2\n");
 }
 return 0;
}
