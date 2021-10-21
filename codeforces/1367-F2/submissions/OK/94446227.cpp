// W i B
#include <bits/stdc++.h>
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define bit(x,p) ((x>>p) & 1)
#define ll long long
#define pii pair<int,int>
#define Task "CF"
using namespace std;
 
const int base = 100003;
const int maxn = 200005;
 
int n,a[maxn],dp[maxn],cnt[maxn],num[maxn],preid[maxn],fi[maxn];
 
void Solve(){
    cin >> n;
 for(int i = 1;i <= n;++i) cin >> a[i];
 for(int i = 1;i <= n;++i){
        dp[i] = preid[i] = fi[i] = num[i] = cnt[i] = 0;
 }
 vector<int> v(a + 1,a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
 for(int i = 1;i <= n;++i){
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
        num[a[i]]++;
 }
 int ans = 0;
 for(int i = 1;i <= n;++i){
 int x = a[i];
        dp[i] = max(dp[i],cnt[x - 1] + 1);
 if(preid[x]) dp[i] = max(dp[i],dp[preid[x]] + 1);
 if(cnt[x - 1] == num[x - 1]) dp[i] = max(dp[i],dp[fi[x - 1]] + num[x - 1]);
        cnt[x]++,preid[x] = i;
 if(!fi[x]) fi[x] = i;
        ans = max(ans,dp[i]);
 }
    cout << n - ans << "\n";
}
 
void NumTime(){
    cerr << "Toi" << "\n";cerr << "Di" << "\n";cerr << "Chep" << "\n";cerr << "Code" << "\n";
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
 if(fopen(Task".inp","r")){
		freopen(Task".inp","r",stdin);
		freopen(Task".out","w",stdout);
 }
 int test = 1;
    cin >> test;
 NumTime();
 while(test --){
 Solve();
 }
}
 // V T An
