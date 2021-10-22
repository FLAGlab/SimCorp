#include<bits/stdc++.h>
#define maxn 1000010
#define ll long long 
using namespace std;
 
int a[maxn],r[maxn],l[maxn];
ll n,i,k,ansr,ansl;
 
signed main()
{
	ll ma=-1;
 for(cin>>n;i<=n-1;i++)
 {
		ll m;
		cin>>m;
		a[m]++;
 if(a[m]==1)
 {
			l[m]=i;
 }
		r[m]=i;
 if(a[m]>ma)
 {
			ansl=l[m];
			ansr=r[m];
			ma=a[m];
 }
 else if(a[m]==ma)
 {
 if((r[m]-l[m])<=(ansr-ansl))
 {
				ansl=l[m];
				ansr=r[m];
 }
 }
 }
	cout<<ansl+1<<" "<<ansr+1<<endl;
return 0;
}
