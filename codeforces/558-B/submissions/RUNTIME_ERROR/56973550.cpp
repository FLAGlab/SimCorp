#include<bits/stdc++.h>
using namespace std;
struct node
{
 int x;
 int y;
 int cnt=0;
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
 int n;
	scanf("%d",&n);
 int l=0;int r=0;
 for(int i=1;i<=n;i++)
 {
 int q;
		scanf("%d",&q);
 
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
	printf("%d %d\n",l,r);
 return 0 ;
} 
 
