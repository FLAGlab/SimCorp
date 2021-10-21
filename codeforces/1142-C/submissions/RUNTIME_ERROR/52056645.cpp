#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
 int n;
	scanf("%d",&n);
 map<LL,LL> m;
 for(int i =0;i<n;i++){
		LL x=i,y=0;
		scanf("%lld %lld",&x,&y);
 if(m.find(x)!=m.end())
		m[x]=max(m[x],y);
 else
 {
			m[x]=y; 
 }
 }
 vector<pll> v;
 for(auto it:m)
	v.pb(it);
 int last=0;
 int ans=0;
 for(int i =0;i<v.size()-1;i++){
 //nowv[i+1]
		pll now=v[last];
 
		LL A=now.y-now.x*now.x;
		LL B=now.x;
		LL C=1;
		LL D=v[i+1].y-v[i+1].x*v[i+1].x;
		LL E= v[i+1].x;
		LL F=1;
 //	printf("%lld %lld %lld %lld %lld %lld\n",A,B,C,D,E,F);
 long double b=(long double)(A*F-C*D)/(B*F-C*E);
 long double c=(long double)(B*D-A*E)/(B*F-C*E);
 int ok=1;
 for(int j =i+2;j<v.size();j++){
 long double myy=v[j].x*v[j].x+b*v[j].x+c;
 //printf("%d %d %d %lf %lf %lf\n",last,i+1,j,myy,b,c);
 if(myy<v[j].y+1e-5){
				ok=0;
 break;
 }
 if(myy>1e7){
 break;
 }
 }
 if(ok){
			ans++;
 //printf("%d %d\n",last,i+1);
			last=i+1;
 } 
 }
 if(ans==0)
		assert(v.size()==0);
	printf("%d\n",ans);
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc
