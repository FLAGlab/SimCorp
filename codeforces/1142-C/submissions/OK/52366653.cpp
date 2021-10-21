#include<bits/stdc++.h>
#define LL long long
#define M 100005
using namespace std;
struct Poi{
	LL x,y;
 bool operator <(const Poi &_)const{
 return x<_.x||(x==_.x&&y>_.y);
 }
}P[M],stk[M];
int top,n;
int main(){
	scanf("%d",&n);
 for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		P[i]=(Poi){x,(LL)y-1LL*x*x};
 }
	sort(P+1,P+n+1);
 for(int i=1;i<=n;i++){
 if(i>1&&P[i].x==P[i-1].x)continue;
 while(top>1&&(stk[top].y-stk[top-1].y)*(stk[top].x-P[i].x)>=(stk[top].y-P[i].y)*(stk[top].x-stk[top-1].x))top--;
		stk[++top]=P[i];
 }
	printf("%d\n",top-1);
 return 0;
}
