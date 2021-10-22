#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long 
using namespace std;
const double eps=1e-8;
struct N{
 long long x,y;
}p[MAXN],S[MAXN];
int n,x,y,t,ans;
 
bool cmp(N a,N b){
 if(a.x==b.x)return a.y<b.y;
 return a.x<b.x;
}
 
int chk(N a,N b,N c){
	N A,B;A.x=b.x-a.x;A.y=b.y-a.y;B.x=c.x-a.x;B.y=c.y-a.y;
 return A.x*B.y-B.x*A.y>=0;
}
void add(N a){
 while(t>0&&a.x==S[t-1].x)t--;
 while(t>1&&chk(S[t-2],S[t-1],a))t--;
	S[t++]=a;
}
 
signed main(){
	cin>>n;
 for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		p[i].y=y-(ll)x*x;
		p[i].x=x;
 }
	sort(p,p+n,cmp);
 for(int i=0;i<n;i++)add(p[i]);
 for(int i=0;i<t;i++)if(i==0||S[i].x!=S[i-1].x)ans++;
	printf("%d",ans-1);
}
 
