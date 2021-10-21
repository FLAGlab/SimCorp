#include <bits/stdc++.h>
using namespace std;
int n,m;
class Point{
 public:
 long long a,b;
 Point(long long a=0,long long b=0):a(a),b(b){}
 Point operator +(Point c){return Point(a+c.a,b+c.b);}
 Point operator -(Point c){return Point(a-c.a,b-c.b);}
}p[1000005],q[1000005];
long long Cross(Point c,Point d){return c.a*d.b-c.b*d.a;}
bool cmp(Point x,Point y){
 if(x.a==y.a) return x.b>y.b;
 return x.a<y.a;
}
int main(){
	cin>>n;
 for(int i=1;i<=n;i++){
		scanf("%lld%lld",&p[i].a,&p[i].b);
		p[i].b-=p[i].a*p[i].a;
 }
	sort(p+1,p+n+1,cmp);
	p[0].a=-10041212000;
 for(int i=1;i<=n;i++){
 if(p[i].a==p[i-1].a) continue;
		q[++m]=p[i];
 }
 for(int i=1;i<=m;i++) p[i]=q[i];
	n=m;
	m=0;
 for (int i = 1; i <= n; i++) {
 while (m > 1 && Cross( q[m] - q[m - 1],p[i] - q[m - 1]) >= 0) m--;
		q[++m] = p[i];
 }
	cout<<m-1<<endl;
 return 0;
}
 
