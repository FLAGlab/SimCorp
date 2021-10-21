#include <bits/stdc++.h>
using namespace std;
int n,m,num,tag[1000005];
class Point{
 public:
 long long a,b;
 Point(int a=0,int b=0):a(a),b(b){}
 Point operator +(Point c){return Point(a+c.a,b+c.b);}
 Point operator -(Point c){return Point(a-c.a,b-c.b);}
}p[1000005],q[1000005];
long long Cross(Point x,Point y){return x.a*y.b-x.b*y.a;}
bool cmp(Point x,Point y){
 if(x.a==y.a) return x.b>y.b;
 return x.a<y.a;
}
int main(){
	cin>>n;
 for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].a,&p[i].b),p[i].b-=p[i].a*p[i].a;
	sort(p+1,p+n+1,cmp);
 for (int i = 1; i <= n; i++) {
 while (m > 1 && Cross(p[i] - q[m - 1], q[m] - q[m - 1]) <= 0) m--;
        q[++m] = p[i];
 }
	cout<<m-1;
 return 0;
}
 
