#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node
{
 long long x;
 long long y;
 long long cnt=0;
}p[100005];
bool cmp(const node &a,const node &b)
{
 if(a.cnt==b.cnt)
 return a.y-a.x <b.y-b.x;
 else
 return a.cnt>b.cnt;
 
}
 
signed main()
{
	LL n;
	scanf("%lld",&n);
	LL l=0;LL r=0;
 for(LL i=1;i<=n;i++)
 {
		LL q;
		scanf("%lld",&q);
 
 if(p[q].cnt)
 {
			p[q].y=i;
 }
 else
 {
			p[q].x=i;
			p[q].y=i;
 }
		p[q].cnt++;
 
 }
	sort(p+1,p+n+1,cmp);
	l=p[1].x;
	r=p[1].y;
	printf("%lld %lld\n",l,r);
 return 0 ;
} 
 
