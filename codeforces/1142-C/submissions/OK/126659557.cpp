#include<cstdio>
#include<algorithm>
int n;
const int maxn=1e6+100;
typedef long long ll;
struct point{
	ll x,y;
 bool operator<(const point& rhs)const{
 return x==rhs.x?y>rhs.y:x<rhs.x;
 }
	ll operator*(point rhs)const{
 return x*rhs.y-y*rhs.x;
 }
	point operator-(point rhs)const{
 return point{x-rhs.x,y-rhs.y};
 }
}p[maxn];
int st[maxn],tp=0;
int main(){
	scanf("%d",&n);
 for(int i=1;i<=n;i++){
		scanf("%lld%lld",&p[i].x,&p[i].y);
		p[i].y-=p[i].x*p[i].x;
 }
	std::sort(p+1,p+n+1);
	st[++tp]=1;
 for(int i=2;i<=n;i++){
 while(tp>1&&(p[st[tp-1]]-p[st[tp]])*(p[i]-p[st[tp]])<=0){
			tp--;
 }
		st[++tp]=i;
 }
 int l=1,r=tp;
 while(l<r&&p[st[l]].x==p[st[l+1]].x)l++;
 while(r>l&&p[st[r]].x==p[st[r-1]].x)r--;
	printf("%d\n",r-l);
 return 0;
}
 
