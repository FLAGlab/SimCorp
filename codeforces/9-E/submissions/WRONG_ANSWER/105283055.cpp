#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORU(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
 
#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define PROB "9E"
void Fi(){
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
}
 
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
 
const int N = 51;
int deg[N];
 
int par[N];
 
int root(int v){
 return (par[v] < 0 ? v : par[v] = root(par[v]));
}
 
bool unionn(int x, int y){
 if((x = root(x)) == (y = root(y))){
 return false;
 }
 if(-par[x] < -par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
 return true;
}
 
int main(){
 Fi();
 int n, m;
    cin >> n >> m;
    FORU(i, 1, m){
 int u, v;
        cin >> u >> v;
 ++deg[u];
 ++deg[v];
 if(deg[u] > 2 || deg[v] > 2){
            cout << "NO";
 return 0;
 }
 }
    FORU(i, 1, n) par[i] = -1;
 vector<pii> ans;
    FORU(i, 1, n) FORU(j, 1, n){
 if(deg[i] < 2 && deg[j] < 2 && unionn(i, j)){
            ans.eb(mp(i, j));
 }
 }
    cout << "YES\n";
    cout << ans.size() << "\n";
 for(auto x: ans) cout << x.fi << " " << x.se << "\n";
 return 0;
}
