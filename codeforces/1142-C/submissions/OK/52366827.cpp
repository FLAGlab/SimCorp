#include<bits/stdc++.h>
#define ll long long
#define M 100005
using namespace std;
int n,top;
struct node{
	ll x,y;
 bool operator<(const node&_)const{
 if(x!=_.x)return x<_.x;
 return y<_.y;
 }
}a[M],s[M];
bool cmp(node A,node B,node C){
 return (C.y-A.y)*(C.x-B.x)>=(C.y-B.y)*(C.x-A.x);
}
signed main(){
	scanf("%d",&n);
 for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y),a[i].y-=1ll*a[i].x*a[i].x;
	sort(a+1,a+n+1);
 for(int i=1;i<=n;i++){
 if(i!=n&&a[i].x==a[i+1].x)continue;//此时的斜率肯定不及上一个大 
 while(top>1&&cmp(s[top-1],a[i],s[top]))top--;
		s[++top]=a[i];
 }
	printf("%d\n",top-1);
 return 0;
}
