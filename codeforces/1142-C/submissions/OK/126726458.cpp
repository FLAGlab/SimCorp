//Andrew算法
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#define int long long
using namespace std;
int n;
struct abc{
 int x ,y;
}p[100005] ,p2[100005];
bool cmp(abc a, abc b){
 if(a.x!=b.x)return a.x<b.x;
 return a.y<b.y;
}
int cross(abc a ,abc b){
 return a.x*b.y-b.x*a.y;
}
abc vectorr(abc a ,abc b){
 return (abc){a.x-b.x ,a.y-b.y};
}
abc q[100005];
int top=0;
main()
{
	cin >> n;
 for(int i=1;i<=n;i++){
		cin >> p[i].x >> p[i].y;
		p[i].y-=p[i].x*p[i].x;
 }
	sort(p+1 ,p+n+1 ,cmp);
 int nn=1;
	p2[1]=p[n];
 for(int i=n-1;i>=1;i--){
 if(p[i].x!=p[i+1].x)p2[++nn]=p[i]; 
 }
	q[1]=p2[1];
	top=1;
 for(int i=2;i<=nn;i++){
 while(top>=2&&cross(vectorr(q[top-1] ,q[top]) ,vectorr(p2[i] ,q[top]))>=0){
			top--;
 }
		q[++top]=p2[i];
 }
	cout << top-1 << endl;
}
