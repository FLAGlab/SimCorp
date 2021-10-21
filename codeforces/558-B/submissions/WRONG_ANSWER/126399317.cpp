#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main(){
 int n,m,l,r,maxn=-1,sum1=0x3f3f3f3f;
	cin>>n;
 for(int i=1;i<=n;i++){
		cin>>m;
		a[m]++;
 if(a[m]==1){
			l=i;
			b[m]=i;
 }
 if(a[m]>maxn){
			maxn=a[m];
			sum1=i-b[m];
			r=i;
			l=b[m];
 }
 else if(a[m]==maxn){
 if(i-b[m]<sum1){
				l=b[m];
				r=i;
				sum1=r-l;
				maxn=a[m];
 }
 }
 }
	cout<<l<<" "<<r<<endl;
 return 0;
} 
 
