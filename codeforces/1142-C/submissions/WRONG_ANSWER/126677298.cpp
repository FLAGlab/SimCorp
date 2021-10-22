#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
long long t;
struct abc{
 int x,y;
}stk[N],p[N];
 
bool cmp(abc a,abc b){
 return (a.x==b.x)?(a.y>b.y):(a.x<b.x);
}
 
signed main(){
	cin>>n;
 for(int i=1;i<=n;i++){
		scanf("%d %d",&p[i].x,&p[i].y);
		p[i].y-=p[i].x*p[i].x;
 }
	sort(p+1,p+n+1,cmp);
	stk[++t]=p[1];
 for (int i=2;i<=n;i++)
 {
 while (t>1&&(stk[t].y-stk[t-1].y)*(p[i].x-stk[t].x)-(p[i].y-stk[t].y)*(stk[t].x-stk[t-1].x)<=0)
            t--;//(p[i]-stk[t])*(stk[t]-stk[t-1])<=0,不满足要求 
        stk[++t]=p[i];
 }
	printf("%lld\n",t-1);
}
 
