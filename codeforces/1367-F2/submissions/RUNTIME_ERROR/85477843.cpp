#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define s second
#define f first
 
bool comp(pair<ll, ll> a, pair<ll, ll> b){
 return a.f < b.f;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
 while(t--){
        ll n;
        cin >> n;
 
 vector<pair<ll, ll>> v(n, {0, 0});
 vector<ll> vv(n, 0);
 vector<ll> cnt(n+1, 0);
 forn(i, n){
            cin >> v[i].f;
            v[i].s = i;
 }
        sort(v.begin(), v.end());
 int cntn = 0;
 forn(i, n){
 if(i == 0){
                cntn++;
                vv[0] = 0;
 continue;
 }
            vv[i] = vv[i-1];
 if(v[i].f != v[i-1].f){
                vv[i]++;
                cnt[vv[i-1]] = cntn;
                cntn = 0;
 }
            cntn++;
 }
        cnt[vv.back()] = cntn;
 
 forn(i, n)
            swap(v[i].f, v[i].s);
 forn(i, n)
            v[i].s = vv[i];
 
        sort(v.begin(), v.end(), comp);
 
 vector<int> dp(n, 1);
 vector<int> dp_(n, 1);
 vector<int> dpcnt(n, 1);
 vector<int> lu(n+1, -1);
        lu[v[0].s] = 0;
 forn(i, n){
 if(i == 0)
 continue;
 int l = lu[v[i].s];
 int pr = lu[v[i].s-1];
 if(l > -1)
                dp[i] = max(dp[i], dp[l] + 1);
 if(pr > -1 && (dpcnt[pr] == cnt[v[i].s-1] || dpcnt[pr] == dp[pr] ))
                dp[i] = max(dp[i], dp_[pr] + 1);
 if(l > -1){
                dp_[i] = dp_[l] + 1;
                dpcnt[i] = dpcnt[l] + 1;
 }else if(pr > -1){
                dp_[i] = dp[pr] + 1;
                dpcnt[i] = 1;
 }
 
            lu[v[i].s] = i;
 }
        cout << n - *max_element(dp.begin(), dp.end()) << endl;
 }
 
 
 return 0;
}
