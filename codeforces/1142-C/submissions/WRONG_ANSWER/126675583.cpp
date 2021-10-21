#include<iostream>
#include<cstdio>
#include<algorithm>
const int N=1e6+1;
using namespace std;
int n,tp,stk[N],used[N];
struct abc{
 int x,y;
 int operator*(abc a)const{
 return x*a.y-y*a.x;
 } 
	abc operator-(abc&a)const{
		a.x=x-a.x;
		a.y=y-a.y;
 return a;
 }
}p[1000001];
 
bool cmp(abc x,abc y){
 return x.x<y.x;
}
 
int main(){
	cin>>n;
 for(int i=1;i<=n;i++){
		scanf("%d %d",&p[i].x,&p[i].y);
		p[i].y-=p[i].x*p[i].x;
 }
	tp = 0;
	sort(p + 1, p + 1 + n,cmp); 
	stk[++tp] = 1;
 int tmp=tp; 
 for (int i = n - 1; i > 0; --i)
 if (!used[i]) {
 while (tp > tmp && (p[stk[tp]] - p[stk[tp - 1]]) * (p[i] - p[stk[tp]]) <= 0)
	      used[stk[tp--]] = 0;
	    used[i] = 1;
	    stk[++tp] = i;
 }
 int ans = tp;
	cout<<ans<<endl;
}
 
