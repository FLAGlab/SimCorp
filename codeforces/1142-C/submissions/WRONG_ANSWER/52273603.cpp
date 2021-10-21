#include<bits/stdc++.h>
#define MAXN 100005
#define eps 1e8
using namespace std;
struct N{
 double x,y;
}p[MAXN],S[MAXN];
int n,x,y,t;
int dcmp(double a,double b){
 if(fabs(a-b)<eps)return 0;
 if(a>b)return 1;
 return -1;
}
bool cmp(N a,N b){
 if(dcmp(a.x,b.x))return a.x<b.x;
 return a.y>b.y;
}
 
int chk(N a,N b,N c){
	N A={b.x-a.x,b.y-a.y},B={c.x-a.x,c.y-a.y};
 return A.x*B.y-B.x*A.y<=0;
}
void add(N a){
 while(t>0&&a.x==S[t-1].x)t--;
 while(t>1&&chk(S[t-2],S[t-1],a))t--;
	S[t++]=a;
}
 
int main(){
	cin>>n;
 for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		p[i].y=y-x*x;
		p[i].x=x;
 }
	sort(p,p+n,cmp);
 for(int i=0;i<n;i++)add(p[i]);
	printf("%d",t-1);
}
 
