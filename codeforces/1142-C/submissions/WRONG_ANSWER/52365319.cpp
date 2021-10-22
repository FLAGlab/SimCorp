#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define ld long double
 
int n,t,i;
ll x,y;
 
struct ff{
 ll x,y;
 bool operator <(const ff& w)const{
 if(x==w.x)return y<w.y;
 return x<w.x;
 }
}p[N],s[N];
 
ld slope(ff x,ff y){return (ld)(x.y-y.y)/(x.x-y.x);}
 
signed main(){
	scanf("%d",&n);
 for(i=1;i<=n;++i){
		scanf("%lld%lld",&x,&y);
		y-=(ll)x*x;
		p[i]=(ff){x,y};
 }
	sort(p+1,p+1+n);
 for(i=1;i<=n;++i){
 while(t&&s[t].x==p[i].x) t--;
 while(t>1&&slope(p[i],s[t-1])>=slope(s[t],s[t-1])) t--;
		s[++t]=p[i];
 }
	printf("%d\n",t-1);
 return 0;
}
