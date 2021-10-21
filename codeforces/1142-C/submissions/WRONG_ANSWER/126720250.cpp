#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int q[1000001],tail,ans;
struct node
{
 int x,y;
}a[1000001];
inline int cmp(node a,node b)
{
 if(a.x==b.x) return a.y>b.y;
 return a.x<b.x;
}
inline int slope(node a,node x,node y)
{
 return (x.x-a.x)*(y.y-a.y)+(x.y-a.y)*(y.x-a.x);
}
int n;
signed main()
{
	cin>>n;
 for(int i=1;i<=n;i++)
 {
		cin>>a[i].x>>a[i].y;
		a[i].y-=a[i].x*a[i].x;
 }
	sort(a+1,a+n+1,cmp);
 for(int i=n;i>=1;i--)
 {
 while(tail>1&&slope(a[q[tail-1]],a[q[tail]],a[i])<=0) tail--;
		q[++tail]=i;
 }
	cout<<tail;
 return 0;
} 
 
