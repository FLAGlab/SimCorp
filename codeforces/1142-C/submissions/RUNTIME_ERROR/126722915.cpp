#include<bits/stdc++.h>
using namespace std;
int n;
int x[6000] ,y[6000];
struct abc{
 int x ,y;
}p[2000000];
int cross(int a,int b,int c)
{
 return (p[a].x-p[c].x)*(p[b].y-p[c].y)-(p[a].y-p[c].y)*(p[b].x-p[c].x);
}
bool cmp(abc a ,abc b){
 if(a.x==0){
 if(b.x==0)
 return a.y<b.y;
 return b.x<0;
 }
 if(b.x==0){
 if(a.x==0)
 return b.y<a.y;
 return a.x<0;
 }
 double k=a.y*1./(a.x+1e-12)*1. ,kk=b.y*1./(b.y+1e-12)*1.;
 if(k==kk){
 return a.x<b.x;
 }
 if((a.x<0&&b.x<0)||(a.x>0&&b.x>0))return k>kk;
 return k<kk;
}
signed main()
{
	cin >> n;
 for(int i=1;i<=n;i++){
		cin >> p[i].x >> p[i].y;
		p[i].y-=p[i].x*p[i].x;
 if(i>1&&(p[i].y<p[1].y||(p[i].y==p[1].y&&p[i].x<p[1].x))){
			swap(p[i] ,p[1]);
 }
 }
//	cout << "debug" << endl;
//	for(int i=1;i<=n;i++){
//		cout << p[i].x << ' '<< p[i].y << endl;
//	} 
//	cout << "end" << endl;
 for(int i=2;i<=n;i++){
		p[i].x-=p[1].x ,p[i].y-=p[1].y;
 }
	p[1].x=p[1].y=0;
	sort(p+2 ,p+n+1 ,cmp);
//	cout << "debug" << endl;
//	for(int i=1;i<=n;i++){
//		cout << p[i].x << ' '<< p[i].y << endl;
//	} 
//	cout << "end" << endl;
 int q[6000]={0 ,1 ,2} ,top=2;
 for(int i=3;i<=n;i++){
 int a=q[top] ,b=q[top-1];
 while(cross(b ,a ,i)>=0&&top){
			top--;
			a=q[top] ,b=q[top-1];
 }
		q[++top]=i;
 }
 int a=1 ,b=1;
 for(int i=1;i<=top;i++){
 if(p[q[a]].x>p[q[i]].x||(p[q[a]].x==p[q[i]].x&&p[q[a]].y<p[q[i]].y))a=i;
 if(p[q[b]].x<p[q[i]].x||(p[q[b]].x==p[q[i]].x&&p[q[b]].y<p[q[i]].y))b=i;
//		cout << i << ' ' << p[q[i]].x << ' ' << p[q[i]].y << endl; 
 }
//	cout << a << ' ' << b << endl;
 if(a>b)swap(a ,b);
 int ans=1;
 for(int i=a+1;i<b;i++){
 double k=(p[q[i+1]].y-p[q[i]].y)*1.*((p[q[i]].x-p[q[i-1]].x));
 double kk=(p[q[i]].y-p[q[i-1]].y)*1.*((p[q[i+1]].x-p[q[i]].x));
//		cout << i << ' ' << kk << ' ' << k << endl;
 if(kk!=k)
			ans++;
 }
	cout << ans << endl;
}
