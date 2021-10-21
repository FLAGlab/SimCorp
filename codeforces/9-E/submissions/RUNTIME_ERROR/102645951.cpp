#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(a, b, c) for(int a = b;a<c;++a)
#define back(a, b, c) for(int a = b-1;a>=c;--a)
#define FOR(n) for(int i = 0;i<n;++i)
#define cnt(a, b) count(a.begin(), a.end(), b)
#define srt(a) sort(a.begin(), a.end())
#define srtb(a) sort(a.begin(), a.end(), [](int x, int y){return x > y;});
#define ea(a, b) for(auto a : b)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz size()
#define ln length()
#define ss second
#define ff first
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef queue<int> qi;
 
const int inf = 2e9;
const int nmax = 2e5+2;
int ans = 0, ats = 0, n, m, k;
 
vi adj[52];
vi cycles[1000];
 
void dfs_cycle(int u, int p, int *color, vi *mark, int *par){
 if(color[u] == 2)
 return;
 if(color[u] == 1){
        ans++;
 //
 int cur = p;
        mark[cur].pb(ans);
 while(cur != u){
            cur = par[cur];
            mark[cur].pb(ans);
 }
 return;
 }
    par[u] =p;
    color[u] = 1;
    ea(v, adj[u]){
 if(v == par[u])
 continue;
        dfs_cycle(v, u, color, mark, par);
 }
    color[u] = 2;
}
 
//void pr(int *mark){
//    rep(i, 1, m+1){
//        if(mark[i] != 0){
//            cycles[mark[i]].pb(i);
//        }
//    }
//
//    rep(i, 1, ans+1){
//        ea(next, cycles[i])
//            cout<<next<<" ";
//        cout<<endl;
//    }
//}
 
int main(){fast;
	ifstream in("duom.txt");
    cin>>n>>m;
    vii new_edges;
 for(int i = 0, u, v;i<m;++i){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
 }
 int color[52], par[52];
    vi mark[52];
    cout<<"AsdadadA";
    dfs_cycle(1, 0, color, mark, par);
    rep(i, 1, n+1){
 if(mark[i].sz > 1){
            cout<<"NO";
 return 0;
 }
 }
 
    rep(i, 1, n+1){
        rep(j, i+1, n+1){
 //cout<<i<<" "<<j<<endl;
 if(cnt(adj[i], j))
 continue;
            adj[i].pb(j);
            adj[j].pb(i);
 
            rep(k, 1, n+1){
                color[k] = 0;
                par[k] = 0;
 }
            mark[i].clear();
            mark[j].clear();
            dfs_cycle(i, 0, color, mark, par);
 if(mark[i].sz != 1 || mark[j].sz != 1){
                rep(k, 0, adj[i].sz){
 if(adj[i][k] == j){
                        adj[i].erase(adj[i].begin() + k);
 break;
 }
 }
                rep(k, 0, adj[j].sz){
 if(adj[j][k] == i){
                        adj[j].erase(adj[j].begin() + k);
 break;
 }
 }
 continue;
 }
            new_edges.pb(mp(i, j));
 }
 }
 
    rep(k, 1, n+1){
        color[k] = 0;
        par[k] = 0;
        mark[k].clear();
 }
    dfs_cycle(1, 0, color, mark, par);
    rep(i, 1, n+1){
 if(mark[i].sz != 1){
 //cout<<i<<" "<<mark[i].sz<<endl;
            cout<<"NO";
 return 0;
 }
 }
    cout<<"YES"<<endl;
    cout<<new_edges.sz<<endl;
    ea(i, new_edges){
        cout<<min(i.ff, i.ss)<<" "<<max(i.ff, i.ss)<<endl;
 }
 
}
