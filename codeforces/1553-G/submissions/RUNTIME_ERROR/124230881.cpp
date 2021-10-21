#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
 vector<int> parent;
 
    DSU(int m) {
        parent.resize(m + 1);
 for(int i = 0; i <= m + 1; i++)
            parent[i] = i;
 }
 
 int find(int k) {
 if(parent[k] == k)
 return k;
 return parent[k] = find(parent[k]);
 }
 
 void uni(int a, int b) {
        parent[find(a)] = find(b);
 }
};
 
int main() {
 int n, q;
	cin >> n >> q;
 vector<int> a(n);
 for(int i = 0; i < n; i++)
	    cin >> a[i];
 int m = *max_element(a.begin(), a.end());
 vector<vector<int>> prime_divisors(m + 2);
 
 for(int i = 2; i <= m + 1; i++)
 if(prime_divisors[i].empty())
 for(int j = i; j <= m + 1; j += i)
	            prime_divisors[j].push_back(i);
 
	DSU dsu(m + 1);
 for(int x: a)
 for(int p: prime_divisors[x])
	        dsu.uni(x, p);
 
 set<pair<int, int>> edges; 
 for(int x: a) {
 vector<int> nodes = prime_divisors[x + 1];
	    nodes.push_back(x);
 for(int& node: nodes)
	        node = dsu.find(node);
 for(int i = 0; i < nodes.size(); i++)
 for(int j = i + 1; j < nodes.size(); j++) {
 int one = nodes[i], two = nodes[j];
 if(one != two) {
 if(one > two)
	                    swap(one, two);
	                edges.insert({one, two});
 }
 }
 }
 
 int s, t;
 for(int i = 0; i < q; i++) {
	    cin >> s >> t;
	    s--, t--;
	    s = dsu.find(a[s]), t = dsu.find(a[t]);
 if(s == t) cout << 0;
 else if(edges.count({min(s, t), max(s, t)})) cout << 1;
 else cout << 2;
	    cout << '\n';
 }
 
 return 0;
}
