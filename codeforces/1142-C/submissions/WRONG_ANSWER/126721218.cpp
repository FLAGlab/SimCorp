#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int cntt=0; 
struct nd{
 int x;
 int y;
}aa[1000006],ans[1000006];
inline int cmp1(nd a,nd b){
 if(a.x!=b.x){
 return a.x<b.x;
 }else{
 return a.y>b.y;
 }
}
inline int work(nd a,nd b,nd c){
 return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
signed main(){
	cin>>n;
 for(int i=1;i<=n;i++){
		cin>>aa[i].x>>aa[i].y;
		aa[i].y-=aa[i].x*aa[i].x;
 }
	sort(aa+1,aa+n+1,cmp1);
 int k=0;
	aa[0].x=-2e9;
 for(int i=1;i<=n;i++){
 if(aa[i].x==aa[i-1].x){
 continue;
 }
 while(k>1&&work(aa[i],ans[k],aa[k-1])<=0)k--;
		ans[++k]=aa[i];
 }
	cout<<k-1;
 
 
 return 0;
}
