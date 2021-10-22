#include<bits/stdc++.h>
using namespace std;
const int N =1e6+5;
int num[N],st[N];
int n,l,r;
int mx=-1,mi=N;
signed main() {
 while(cin>>n) {
 for(int i=1; i<=n; i++) {
 int x;
			cin>>x;
			num[x]++;
 if(num[x]==1) {
				st[x]=i;
 } else if(num[x]>mx) {
				mx=num[x];//最长的数字
				mi=i-st[x];//区间长度
				l=st[x];//始
				r=i;//末
 } else if(num[x]==mx) {
 if(mi>i-st[x]) {
					mi=i-st[x];
					l=st[x];
					r=i;
 }
 }
 }
		cout<<l<<" "<<r<<endl;
 }
 
 return 0;
}
 
