#include<bits/stdc++.h>
using namespace std;
struct node
{
 int x;
 int y;
 int cnt=0;
};
node p[100005];
bool cmp(const node &a,const node &b)
{
 if(a.cnt==b.cnt)
 return a.y-a.x <b.y-b.x;
 else if(a.cnt<b.cnt)
 return false;
 else if(a.cnt>b.cnt)
 return true;
}
signed main()
{
 int n;
	scanf("%d",&n);
 int max=0;
 for(int i=1;i<=n;i++)
 {
 int q;
		scanf("%d",&q);
 if(q>max) max=q;
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
	sort(p+1,p+max,cmp);
	printf("%d %d\n",p[1].x,p[1].y);
 return 0 ;
} 
 
