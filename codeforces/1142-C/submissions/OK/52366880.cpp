#include<bits/stdc++.h>
#define M 100005
#define LL long long
using namespace std;
int n;
struct node{
	LL x,y;
 bool operator < (const node& res) const{
 if(x!=res.x)return x<res.x;
 return y<res.y;
 }
}A[M],stk[M];
int top=0;
bool check(node &a,node &b,node &c){
 return 1.0*(c.y-a.y)*(b.x-c.x)<=1.0*(b.y-c.y)*(c.x-a.x);
}
signed main(){
	scanf("%d",&n);
 for(int i=1;i<=n;i++){ 
		scanf("%lld%lld",&A[i].x,&A[i].y);
		A[i].y-=A[i].x*A[i].x;
 }
	sort(A+1,A+n+1);
 for(int i=1;i<=n;i++){
 if(i!=n&&A[i].x==A[i+1].x)continue;
 while(top>1&&check(stk[top-1],A[i],stk[top]))top--;
		stk[++top]=A[i];
 }
	printf("%d\n",top-1);
 return 0;
}
