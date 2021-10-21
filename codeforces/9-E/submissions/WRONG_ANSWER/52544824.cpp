#include <bits/stdc++.h>
 
using namespace std;
 
int dsu[51];
int edge_count[51] {0};
 
int search(int x)
{
 if(dsu[x] != x) dsu[x] = search(dsu[x]);
 return dsu[x];
}
 
void join(int u, int v)
{
    dsu[search(u)] = search(v);
}
 
int main()
{
 int n, m; cin >> n >> m;
 for(int i=1; i < 51; i++) dsu[i] = i;
 
 int u, v;
 int loops = 0;
 for(int i=0; i < m; i++)
 {
        cin >> u >> v;
 if(search(u) == search(v)) ++loops;
 
 if(loops > 1 || ++edge_count[u] > 2 || ++edge_count[v] > 2)
 {
            cout << "NO" << endl;
 return 0;
 } 
 
        join(u, v);
 }
 
 if(loops)
 {
 if(n == m) cout << "YES\n" << 0 << endl;
 else cout << "NO" << endl;
 return 0;
 }
 
    cout << "YES" << '\n';
    cout << n - m << '\n';
 
 for(int u=1; u < n; u++)
 {
 for(int v=u + 1; v <= n; v++)
 {
 if(edge_count[v] == 2) continue;
 if(search(u) == search(v)) continue;
 
            cout << u << ' ' << v << '\n';
 
            join(u, v);
            edge_count[v]++;
 if(++edge_count[u] == 2) break;
 }
 }
 
 for(int u=1; u <= n; u++)
 {
 if(edge_count[u] == 2) continue;
 
 if(edge_count[u] == 0)
 {
            cout << u << ' ' << u << endl;
 return 0;
 }
 
 for(int v = u + 1; v <= n; v++)
 {
 if(edge_count[v] == 2) continue;
            cout << u << ' ' << v << endl;
 return 0;
 }
 }
}
