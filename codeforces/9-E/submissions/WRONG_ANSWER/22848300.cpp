#include<bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 50 + 5;
 
int n, m;
vector<int>	adj[MAXN], sec;
bool vis[MAXN];
int cv, ce;
 
void dfs(int v){
	cv++;
	vis[v] = 1;
	ce += adj[v].size();
 for (int u:adj[v])
 if (!vis[u])
			dfs(u);
}
 
bool ok(int u, int v){
	memset(vis, 0, sizeof(vis));
	dfs(u);
 return !vis[v];
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
 for (int i = 0; i < m; i++){
 int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
 }
 for (int i = 0; i < n; i++)
 if (adj[i].size() > 2){
			cout << "NO\n";
 return 0;
 }
 int cc = 0;
 for (int i = 0; i < n; i++)
 if (!vis[i]){
			cv = ce = 0;
			dfs(i);
 if (ce > cv + cv - 2){
				cout << "NO\n";
 return 0;
 }
			cc++;
 }
 
	cout << "YES\n";
	cout << n-m << "\n";
 if (n == 1 && m == 0){
		cout << "1 1\n";
 return 0;
 }
 if (cc == 1){
 int a, b;
 for (int i = 0; i < n; i++) if (adj[i].size() == 1){	a = i; break;}
 for (int i = a +1; i < n; i++) if (adj[i].size() == 1){	b = i; break;}
		cout << a+1 << " " << b+1 << endl;
 return 0;
 }
 
 while (m < n){
		sec.clear();
 for (int i = 0; i < n; i++)
 if (adj[i].size() < 2)	sec.push_back(i);
 for (int i = 1; i < sec.size(); i++)
 if (ok(sec[0], sec[i])){
				cout << sec[0]+1 << " " << sec[i]+1 << "\n";
				adj[sec[0]].push_back(sec[i]);
				adj[sec[i]].push_back(sec[0]);
				m++;
 break;
 }
 }
 return 0;
}
