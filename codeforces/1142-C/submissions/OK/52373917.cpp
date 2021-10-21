#include<bits/stdc++.h>
#define M 200005
#define ll long long
using namespace std;
int n,m;
struct pos{
	ll x,y;
 bool operator <(const pos &p)const{
 if(x!=p.x) return x<p.x;
 return y<p.y;
 }
}A[M],stk[M];
bool check(pos a,pos b,pos c){
 return (c.y-a.y)*(b.x-c.x)<=(b.y-c.y)*(c.x-a.x);
}
int main() {
	scanf("%d",&n);
 for(int i=1;i<=n;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		y-=x*x,A[i]=(pos){x,y};
 }
	sort(A+1,A+n+1);
 int cnt=0;
 for(int i=1;i<=n;i++){
 if(i!=n&&A[i].x==A[i+1].x) continue;
 while(cnt>1&&check(stk[cnt-1],A[i],stk[cnt])) cnt--;
		stk[++cnt]=A[i];
 }
	printf("%d\n",cnt-1);
 return 0;
}//
