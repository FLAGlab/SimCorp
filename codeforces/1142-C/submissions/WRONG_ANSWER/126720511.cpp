#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct node{
 int x,y;
};
node p[maxn];
bool cmp(node a,node b){
 if(a.y==b.y) return a.x<b.x;
 return a.y<b.y;
}
int cross(node a,node b,node c){
 return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int n;
int q[maxn];
int ans;
signed main(){
	cin>>n;
 for(int i=1;i<=n;i++){
 int x,y;
		cin>>x>>y;
		p[i].x=x;
		p[i].y=y-x*x;
 }
	sort(p+1,p+n+1,cmp);
 int top=0;
	q[++top]=n;
 for(int i=n-1;i>=0;i--){
 while(top>1&&cross(p[q[top-1]],p[q[top]],p[i])<=0) top--;
		q[++top]=i;
 }
 for(int i=1;i<top;i++){
 if(p[q[i]].x!=p[q[i+1]].x) ans++;
 }
	cout<<ans;
} 
 
