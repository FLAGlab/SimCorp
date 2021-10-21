#include <bits/stdc++.h>
#define ll  long long
#define ld  long double
#define endl "\n"
#define ull  unsigned long long
#define pb push_back
#define all(v) ((v).begin()),((v).end())
#define vi   vector<ll>
#define M ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int main()
{
	M
	ll n; cin>>n;
	ll m[n+1]={},ans[n+1]={};
	ll mx=0,mn=0,ch=0;
 for(int i=0;i<n;i++){
		ll in; cin>>in;
 if(m[in]==0)
 {
			ans[in]=i;
			m[in]=1;
 }
 else
			m[in]++;
 if(m[in]>mx){
			mx=m[in];
		mn=i-ans[in]+1;
		ch=ans[in]+1;
 }
 }
	cout<<ch<<" "<<ch+mn-1;
 return 0;
}
 
 
