#include<bits/stdc++.h>
using namespace std;
int a[10005];
struct node
{
 int x;
 int y;
 int cnt=0;
};
node p[10005];
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
 for(int i=1;i<=n;i++)
 {
		scanf("%d",&a[i]);
 if(p[a[i]].cnt)
 {
			p[a[i]].y=i;
 }
 else
 {
			p[a[i]].x=i;
			p[a[i]].y=i;
 }
		p[a[i]].cnt++;
 }
	sort(p+1,p+n+1,cmp);
	printf("%d %d\n",p[1].x,p[1].y);
 return 0 ;
} 
 
