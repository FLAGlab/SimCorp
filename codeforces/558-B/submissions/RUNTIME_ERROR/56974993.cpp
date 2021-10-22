#include<bits/stdc++.h>
 
using namespace std;
struct node
{
 int x;
 int y;
 int cnt=0;
}p[100005];
 
signed main()
{
 int n;
	scanf("%d",&n);
 int q;
	scanf("%d",&q);
	p[q].x=1;
	p[q].y=1;
	p[q].cnt++;
 int l=p[q].x;int r=p[q].y;
 int cntnum=p[q].cnt;
 for(int i=2;i<=n;i++)
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
 if(p[q].cnt>p[cntnum].cnt)
 {
			cntnum=q;
			l=p[q].x;
			r=p[q].y;
 }
 else if(p[q].cnt==p[cntnum].cnt)
 {
 if(p[q].y-p[q].x<r-l||q==cntnum)
 {
				cntnum=q;
				l=p[q].x;
				r=p[q].y;
 }
 }
 } 
	printf("%d %d\n",l,r);
 return 0 ;
} 
 
