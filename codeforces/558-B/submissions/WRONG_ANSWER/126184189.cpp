#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,int> st,ed,sum;
signed main(){
	cin>>n;
 for (int i=1;i<=n;i++){
		cin>>m;
		sum[m]++;
 if (st[m]==0){
			st[m]=i;
			ed[m]=i;
 }
 if (st[m]!=0){
			ed[m]=i;
 }
 }
 int max_=0,id=0,c=INT_MAX;
 for (auto i:sum){
 if (i.second>=max_){
 if (ed[i.first]-st[i.first]<c){
				max_=i.second;
				id=i.first;
				c=ed[i.first]-st[i.first];
 }
 }
 }
	cout<<st[id]<<" "<<ed[id]<<endl;
}
