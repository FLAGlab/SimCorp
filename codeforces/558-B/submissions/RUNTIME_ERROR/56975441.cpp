#include<cstdio>
#include<algorithm>
 
using namespace std;
struct node
{
 int x;
 int y;
 int cnt;
	node()
 {
		x=0;
		y=0;
		cnt=0;
 }
}p[100005];
 
int main()
{
 int n;
	scanf("%d",&n);
 int maxcnt=0;
 int num=0;
 int dis=1000005;
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
 if(p[q].cnt>maxcnt)
 {
			maxcnt=p[q].cnt;
			num=q;
			dis=p[q].y-p[q].x;
 }
 else if(p[q].cnt==maxcnt)
 {
 if(p[q].y-p[q].x<dis)
 {
				num=q;
				maxcnt=p[q].cnt;
				dis=p[q].y-p[q].x;
 }
 }
 } 
	printf("%d %d\n",p[num].x,p[num].y);
 return 0 ;
} 
 
