#include<bits/stdc++.h>
using namespace std;
struct node{
 long long l;
 long long r;
 int flag=0;
 long long sum1;
 long long num;
}s[1000005];
bool cmp(node x,node y){
 if(x.sum1==y.sum1){
 return x.num<y.num;
 }
 return x.sum1>y.sum1;
}
signed main(){
 int n,m;
	cin>>n;
 for(int i=1;i<=n;i++){
		cin>>m;
 if(s[m].flag==0){
			s[m].l=i;
			s[m].flag=1;
 }
 else{
			s[m].r=i;
			s[m].num=s[m].r-s[m].l;
 }
		s[m].sum1++;
 }
	sort(s+1,s+n+1,cmp);
	cout<<s[1].l<<" "<<s[1].r<<endl;
 return 0;
}
 
