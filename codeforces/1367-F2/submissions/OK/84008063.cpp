#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ip pair<ll,ll>
#define ff first
#define ss second
#define MAX 100005
const ll MOD = 1000000007;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
 
 int t;
	cin>>t;
 while(t--){
 int n;
		cin>>n;
 int a[n];
 map<int,int> f;
 for(int i=0;i<n;i++){
			cin>>a[i];
			f[a[i]] = 1;
 }
 
 map<int,int>::iterator it;
 int cnt = 0;
 for(it = f.begin(); it != f.end(); it++)
			it->ss = cnt++;
 
 vector<int> st(n,-1),fi(n,-1),total(n,0);
 for(int i=0;i<n;i++){
			a[i] = f[a[i]];
 if(st[a[i]] == -1)
				st[a[i]] = i;
			fi[a[i]] = i;
 ++total[a[i]];
 }
 
 int dp[2][n];
		memset(dp,0,sizeof(dp));
 
 // dp[0][i] means i is starting element
 int ans = 0;
 for(int i=0;i<n;i++){
 if(a[i] == 0)
				dp[0][0]++;
 else{
				dp[0][a[i]]++;
 
 if(fi[a[i]-1] < i)
					ans = max(ans,max(dp[1][a[i]-1],dp[0][a[i]-1])+total[a[i]]);
 else
					ans = max(ans,dp[0][a[i]-1]+total[a[i]]);
 
 if(i == st[a[i]]){
 if(fi[a[i]-1] < i)
						dp[1][a[i]] = max(dp[1][a[i]-1],dp[0][a[i]-1])+1;
 else
						dp[1][a[i]] = dp[0][a[i]-1]+1;
 }
 else
 ++dp[1][a[i]];
 }
 
 --total[a[i]];
 }
 
 
 for(int i=0;i<n;i++){
 // cout<<"i="<<i<<": ";
 // cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
			ans = max(ans,max(dp[0][i],dp[1][i]));
 }
 
		cout<< n-ans <<endl;
 }
}
