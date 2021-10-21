#include<algorithm>
#include<cmath>
#include<cstdio>
const int maxn=100005;
int n;
struct Point{
 long long x,y;
}p[maxn];
bool operator<(Point a,Point b){
 return a.x!=b.x?a.x<b.x:a.y<b.y;
}
Point operator-(Point a,Point b){
 return Point{a.x-b.x,a.y-b.y};
}
double cp(Point a,Point b){
 return a.x*b.y-a.y*b.x;
}
int stack[maxn],top;
void Andrew(){
 register int i;
	std::sort(p+1,p+n+1);
 stack[++top]=n;
 for(i=n-1;i>=1;i--){
 while(top>1&&cp(p[stack[top]]-p[stack[top-1]],p[i]-p[stack[top-1]])<=0)top--;
 stack[++top]=i;
 }
}
int main(){
	scanf("%d",&n);
 for(int i=1;i<=n;i++){
		scanf("%lld%lld",&p[i].x,&p[i].y);
		p[i].y-=p[i].x*p[i].x;
 }
 Andrew();
 int answer=0;
 for(int i=1;i<top;i++)
 if(p[stack[i]].x!=p[stack[i+1]].x)
			answer++;
	printf("%d",answer);
 return 0;
}
 
