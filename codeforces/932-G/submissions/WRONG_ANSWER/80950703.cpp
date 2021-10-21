//
#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)
 
typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pint;
 
const int N = 1e6 + 5 + 1;
const int C = 26 + 2;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
 
namespace PAM {
 int ch[N][C], pa[N] = {1}, len[N] = {0, -1};
 int top[N], det[N];
 int idx = 1, pre = 0;
 
 void Insert(const char s[], int pos) {
 int p = pre, c = s[pos] - 'a';
 while (s[pos - len[p] - 1] != s[pos]) p = pa[p];
 if (ch[p][c] == 0) {
 int q = pa[p], np = ++idx;
			len[np] = len[p] + 2;
 while (s[pos - len[q] - 1] != s[pos]) q = pa[q];
			pa[np] = ch[q][c];
			ch[p][c] = np;
 
			det[np] = len[np] - len[pa[np]];
			top[np] = (det[np] == det[pa[np]]) ? top[pa[np]] : pa[np];
 }
		pre = ch[p][c];
 }
 
 void Update(int i, ll f[], ll g[]) {
 for (int o = idx; o > 1; o = top[o]) {
			g[o] = f[i - len[top[o]] - det[o]];
 if (det[o] == det[pa[o]])
				g[o] = (g[o] + g[pa[o]]) % MOD;
 if (i % 2 == 0)
				f[i] = (f[i] + g[o]) % MOD;
 }
 }
}; // namespace PAM
 
ll f[N], g[N];
 
int main() {
	ios::sync_with_stdio(0);
 
	string s;
	cin >> s;
 int l = 0, r = s.size() - 1;
	string t = "";
 while (l < r)
		t = t + s[l++] + s[r--];
 
 int n = t.size();
	t = " " + t;
 
	f[0] = 1;
 for (int i = 1; i <= n; i++) {
		PAM::Insert(t.c_str(), i);
		PAM::Update(i, f, g);
 }
	cout << f[n] << endl;
 
 return 0;
}
