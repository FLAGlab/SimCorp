#include<bits/stdc++.h>
#define int long long
using namespace std;////
int n,flag,ans;
struct node{
 int x,y;
}a[1145141];
bool cmp(node c,node d){
 return c.y>d.y;
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
 for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
 }
	sort(a,a+n,cmp);
 for(int j=1;j<n;j++){
 
 int b=a[0].x+a[j].x,c=a[0].y-a[0].x*a[0].x*2-a[0].x*a[j].x;
			flag=0;
 for(int k=0;k<n;k++){
 if(a[k].y>a[k].x*a[k].x+b*a[k].x+c){
					flag=1;
 }
 }
 if(!flag){
				ans++;
 }
 }
	cout<<ans;
 return 0;
}
 
