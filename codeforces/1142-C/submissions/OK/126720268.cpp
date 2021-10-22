#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m;
ll t;
struct abc{
	ll x,y;
}stk[N],a[N],p[N];
 
bool cmp(abc a,abc b){
 if(a.x!=b.x){
 return a.x<b.x;
 }
 else return a.y>b.y;
}
 
signed main(){
	cin>>n;
 for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
		a[i].y-=a[i].x*a[i].x;
 }
	sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++){
 if(a[i].x != a[i-1].x)
			p[++m]=a[i];
 }
	stk[++t]=p[1];
 for (int i=2;i<=m;i++)
 {
 while (t>1&&(stk[t].y-stk[t-1].y)*(p[i].x-stk[t].x)<=(p[i].y-stk[t].y)*(stk[t].x-stk[t-1].x))
            t--;//(p[i]-stk[t])*(stk[t]-stk[t-1])<=0,不满足要求 
        stk[++t]=p[i];
 }
	printf("%lld\n",t-1);
}
/*
3
-1 0
0 2
1 0
*/
 
