#include<bits/stdc++.h>
using namespace std;
#define mod  1000000007
#define int long long
 
struct DSU {
 vector<int> Arr, size;
 int root(int i){
 while(Arr[i] != i){
 Arr[i] = Arr[Arr[i]] ; 
            i = Arr[i]; 
 }
 return i;
 }
 
 void unite(int a,int b){
 int r1 = root(a), r2 = root(b);
 if(r1==r2)
 return;
 if(size[r1] < size[r2]) {
 Arr[r1] = r2;
            size[r2] += size[r1];
 }
 else {
 Arr[r2] = r1;
            size[r1] += size[r2];
 }
 }
 
 void init(int N) {
 Arr.resize(N + 1);
        size.resize(N + 1);
 for( int i=0; i <= N; i++ ) {
 Arr[i] = i;
            size[i] = 1;
 }
 }
};
 
 
void solve() {
 int N, M;
 
    cin >> N >> M;
 
    DSU dsu;
    dsu.init(N);
 
 bool flag = false;
 
 unordered_map<int,int> deg, mark;
 
 for( int i=0; i<M; i++) {
 int u, v;
        cin >> u >> v;
 
        deg[u]++;
        deg[v]++;
 
 if( deg[u] > 2 || deg[v] > 2 ) flag = 1;
 
        dsu.unite(u, v);
 }
 
 if( flag || M > N) {
        cout << "NO\n";
 return;
 }
 
 if( N == M ) {
        cout << "YES \n0 \n";
 return;
 }
 
 vector<int> vert;
 for(int i=1; i<=N; i++) {
 if( deg[i] < 2 ) vert.push_back(i);
 }
 
 vector<pair<int,int> > ans;
 
 for( auto i : vert ) 
 for( auto j : vert ) 
 if( i != j && dsu.root(i) != dsu.root(j) ) ans.push_back({i, j}), dsu.unite(i, j);
 
    cout << "YES \n";
    cout << N - M << '\n';
 
 vector<int> remain;
 
 for( int i=1; i<=N; i++) if( deg[i] == 1 ) remain.push_back(i);
 
    ans.push_back({remain[0], remain.back() });
 
    sort( ans.begin(), ans.end() );
 
 for( auto it : ans ) cout << it.first << ' ' << it.second << '\n'; 
 
}
 
signed main() {
 #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
 #endif
 
ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 int tc = 1;
 //cin >> tc;
 while( tc-- ) {
        solve();
 }
}
 
// Tarun IIITA
// "2021-02-14T19:03:59.000-05:00"
