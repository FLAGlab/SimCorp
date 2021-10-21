#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define REP(i,s,t) for(int i=s;i<=t;i++)
using namespace std;
const int maxn=1e5+5;
typedef pair<int,int> pii;
pii inp[maxn],q[maxn];
int n,cnt;
signed main(){
#ifdef LOCAL
	freopen("C.in","r",stdin);
#endif
	cin>>n;
	REP(i,1,n){
 int x,y; cin>>x>>y;
		inp[i]=make_pair(x,y-x*x);
 }
	sort(inp+1,inp+1+n);
	REP(i,1,n){
 int j=i;
 while(j<n&&inp[j].fi==inp[j+1].fi) j++;
 int x=inp[j].fi,y=inp[j].se;
 while(cnt>=2){
 int x1=q[cnt-2].fi,y1=q[cnt-2].se,x2=q[cnt-1].fi,y2=q[cnt-1].se;
 if((y2-y1)*(x-x2)<=(y-y2)*(x2-x1)) cnt--;
 else break;
 }
		q[cnt++]=make_pair(x,y);
		i=j;
 }
	cout<<cnt-1<<endl;
 return 0;
}
