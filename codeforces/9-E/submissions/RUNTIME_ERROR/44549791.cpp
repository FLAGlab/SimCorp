#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
#define maxn 2555
int father[maxn];
int rank[maxn];
 
void init(int n) {
 for (int i = 0; i <= n; ++i) {
        father[i] = i;
        rank[i] = 0;
 }
}
 
int find(int u) {
 return father[u] == u ? u : father[u] = find(father[u]);
}
 
void join(int u, int v) {
 int fatheru = find(u);
 int fatherv = find(v);
 if (fatheru == fatherv) return;
 else if (rank[u] > rank[v]) father[fatherv] = fatheru;
 else {
        father[fatheru] = fatherv;
 if (rank[u] == rank[v])rank[v]++;
 }
}
 
struct edge {
 int u, v;
 
    edge(int x, int y) : u(x), v(y) {};
 
 bool operator<(const edge &b) const {
 if (u < b.u) {
 return true;
 } else if (u == b.u) {
 return v < b.v;
 }
 return false;
 }
};
 
int degree[maxn];
 
std::vector<edge> edgeset;
std::vector<int> zoodeg;
 
int main() {
      freopen("in.txt", "r", stdin);
 int n, m;
    scanf("%d%d", &n, &m);
    init(n);
 int u, v;
 for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        degree[u]++;
        degree[v]++;
 if (find(u) != find(v)) {
            join(u, v);
 }
 }
 bool flag = true;
 for (int j = 1; j <= n; ++j) {
 if (degree[j] > 2) {
            flag = false;
 break;
 } else if (degree[j] == 1 || degree[j] == 0) {
            zoodeg.push_back(j);
 }
 }
 if (!flag) {
        printf("NO\n");
 } else {
        std::sort(zoodeg.begin(), zoodeg.end());
 if (!zoodeg.empty()) {
 int sz = int(zoodeg.size());
 for (int i = 0; i < sz; ++i) {
 if (degree[zoodeg[i]] < 2) {
 for (int j = 0; j < sz; ++j) {
 if (degree[zoodeg[j]] < 2 && find(zoodeg[i]) != find(zoodeg[j])) {
                            edgeset.push_back(edge(zoodeg[i], zoodeg[j]));
                            join(zoodeg[i], zoodeg[j]);
                            degree[zoodeg[i]]++;
                            degree[zoodeg[j]]++;
 break;
 }
 }
 }
 if (degree[zoodeg[i]] < 2) {
 for (int j = 0; j < sz; ++j) {
 if (degree[zoodeg[j]] < 2 && find(zoodeg[i]) != find(zoodeg[j])) {
                            join(zoodeg[i], zoodeg[j]);
                            edgeset.push_back(edge(zoodeg[i], zoodeg[j]));
                            degree[zoodeg[i]]++;
                            degree[zoodeg[j]]++;
 break;
 }
 }
 }
 if (degree[zoodeg[i]] == 2) {
                    zoodeg.erase(zoodeg.begin() + i);
                    i--;
 }
 }
 }
 for (int i = 1; i <= n; i++) {
 if (degree[i] == 2) continue;
 for (int j = 1; j < i; ++j) {
 if (degree[j] == 1) {
                    join(i, j);
                    edgeset.push_back(edge(j, i));
                    degree[i]++;
                    degree[j]++;
 }
 }
 }
 //      for (auto &it:zoodeg) {
 //          std::cout << it << std::endl;
 //      }
 for (int i = 1; i <= n; i++) {
 if (degree[i] == 0) {
                edgeset.push_back(edge(i, i));
 }
 }
 //      for (int it = 1;it <=n ; it++) {
 //         std::cout << it << std::endl;
 //     }
 //    int parent = find(1);
 //     for (int k = 1; k <= n; ++k) {
 //         if (find(k) != parent ) {
 //              printf("NO\n");
 //              return 0;
 //          }
 //      }
//        for (int i = 1; i <= n; ++i) {
//            std::cout << i << ":" << degree[i] << std::endl;
 //       }
 //   std::sort(edgeset.begin(), edgeset.end());
        printf("YES\n");
        printf("%d\n", int(edgeset.size()));
 if (!edgeset.empty()) {
 for (auto &it:edgeset) {
                printf("%d %d\n", it.u, it.v);
 }
 }
 }
}
