#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
int main()
{
 int n;
	scanf("%d",&n);
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
	printf("%d %d\n",p[1].x,p[1].y);
 return 0 ;
} 
 
