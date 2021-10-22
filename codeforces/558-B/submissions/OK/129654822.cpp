#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000005],l[1000005],r[1000005];
signed main() {
	ll sum=0,i,max=0,ch,n;
	cin>>n;
 for(i=1; i<=n; i++) {
 int x;
		cin>>x;
		a[x]++;
 if(a[x]==1)
 {
			l[x]=i;
 }
		r[x]=i-l[x];
 if(a[x]>max)
 {
			max=a[x];
			ch=x;
 }
 else if(a[x]==max)
 {
 if(r[x]<r[ch])
 {
				ch=x;
 }
 }
 }
	cout<<l[ch]<<' '<<l[ch]+r[ch]<<endl;
 return 0;
}
 
