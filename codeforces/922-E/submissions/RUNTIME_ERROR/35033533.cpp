#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, int> pii;
 
const int N = 1e3+100;
const int C = 1e4+100;
 
ll dp[N][C];
ll n , W, B , X;
ll c[N], cost[N];
vector<ll> foo[N];
 
signed main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
 
	cin >> n >> W >> B >> X;
 int sum = 0;
 for( int i = 0; i < n; i++){
		cin >> c[i];
		sum += c[i];
 }
 for( int i = 0; i < n; i++){
		cin >> cost[i];
 }
 
	memset(dp, -1 , sizeof dp);
 for( int i = 0; i <= c[0]; i++ ){
		ll cnt = W - 1LL * i * cost[0];
 if(cnt >= 0)
			dp[0][i] = cnt;
 else break;
 }
	sum++;
 
 int ans = 0;
 for( int i = 0; i < n - 1; i++ ){
 
 for(int j = 0; j < sum; j++ ){
			foo[j].clear();
 }
 for(int j = 0; j < sum; j++ ){
 if(dp[i][j] != -1){
				ll mana = dp[i][j] + X;
				foo[j].push_back({mana + cost[i + 1] * j});
 }
 }
 
 priority_queue<pii> Q;
 for(int j = 0; j < sum; j++ ){
 for(auto v : foo[j]){
				Q.push({v, j});
 }
 
 
 while(!Q.empty()){
				pii top = Q.top();
 
 int tot = j - top.second;
 if(tot > c[i + 1]){
					Q.pop();
 continue;
 }
 
 break;
 }
 
 if(!Q.empty()){
				pii top = Q.top();
 
//				cerr << j << " " << top.first << endl;
				ll cc = top.first - j * cost[i + 1];
//				cerr << j << " " << cc << endl;
//				cerr << endl;
 if(cc >= 0)
					dp[i + 1][j] = min(cc , W + 1LL * j * B);
 }
 
 if(dp[i + 1][j] != -1){
				ans = max(ans , j);
 }
 }
 
 }
 
	cout << ans << endl;
 
 return 0;
}
 
