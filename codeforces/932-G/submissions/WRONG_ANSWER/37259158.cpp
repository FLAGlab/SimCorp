#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second
 
const int mod = 1e9 + 7;
 
class even_palidrome_partitions {
 struct eertree {
		string s;
 static const int SIGMA = 26;
 array<int, SIGMA> empty;
 vector<array<int, SIGMA> > go;
 vector<int> sl;
 vector<int> diff;
 vector<int> longsl;
 vector<int> pdepth;
 int last;
 static const int ODD_ROOT = 0, EVEN_ROOT = 1;
 
		eertree() {
			s = "";
			fill(all(empty), -1);
			go = { empty, empty };
			sl = { 0, 0 };
			diff = { 0, 1 };
			longsl = { 0, 0 };
			pdepth = { -1, 0 };
			last = 0;
 }
 
 void add(char c) {
 int i = s.size();
			s.pb(c);
 int v = last;
 while (pdepth[v] == i || s[i - pdepth[v] - 1] != c) {
				v = sl[v];
 }
 if (go[v][c - 'a'] == -1) {
 int u = sl[v];
 while (u != 0 && s[i - pdepth[u] - 1] != c) {
					u = sl[u];
 }
 if (go[u][c - 'a'] == -1) u = 1;
 else u = go[u][c - 'a'];
				go[v][c - 'a'] = go.size();
				go.pb(empty);
				sl.pb(u);
				pdepth.pb(pdepth[v] + 2);
				diff.pb(pdepth.back() - pdepth[u]);
				longsl.pb(u);
 if (diff.back() == diff[u])
					longsl.back() = longsl[u];
 }
			v = go[v][c - 'a'];
			last = v;
 }
 
 typedef int position;
 
 int length(position p) {
 return pdepth[p];
 }
 
		position suffix_link(position p) {
 return sl[p];
 }
 
 int sl_diff(position p) {
 return diff[p];
 }
 
		position long_suffix_link(position p) {
 return longsl[p];
 }
 
 struct walker {
			string cur;
			position cv;
			eertree &e;
 
			walker(eertree &t) : e(t) {
				cv = e.ODD_ROOT;
 }
 
			position get() {
 return cv;
 }
 
 void next(char c) {
 int i = cur.size();
				cur.pb(c);
 while (e.length(cv) == i || cur[i - e.length(cv) - 1] != c) {
					cv = e.suffix_link(cv);
 }
				cv = e.go[cv][c - 'a'];
 }
 
 void reset() {
				cur.clear();
				cv = e.ODD_ROOT;
 }
 };
 };
 
	eertree e;
 
 vector<eertree::position> largest_even;
 void calc_largest_even() {
 forn(v, e.go.size()) {
			eertree::position u = v;
 while (u != 0 && e.length(u) % 2 == 1) {
				u = e.suffix_link(u);
 }
			largest_even.pb(u);
 }
 }
 
	string s;
public:
	even_palidrome_partitions(string _s) {
		s = _s;
 for (char c : s)
			e.add(c);
		calc_largest_even();
 }
 
 int solve() {
 int n = s.size();
 vector<int> dp(n + 1, 0);
		dp[0] = 1;
 vector<vector<pair<int, array<int, 2> > > > longdp(n + 1);
		eertree::walker w(e);
 for (int i = 1; i <= n; i++) {
			w.next(s[i - 1]);
			eertree::position cur = w.get();
 while (e.length(cur) > 0) {
 //cout << i << " " << e.length(cur) << " " << e.sl_diff(cur) << " ";
 if (e.sl_diff(cur) == e.sl_diff(e.suffix_link(cur)) && e.length(cur) > 1) {
 array<int, 2> value = {0, 0};
 int ex = i - e.sl_diff(cur);
 while (!longdp[ex].empty() && longdp[ex].back().ff > e.sl_diff(cur))
						longdp[ex].pop_back();
 if (!longdp[ex].empty() && longdp[ex].back().ff == e.sl_diff(cur)) {
 if (e.sl_diff(cur) % 2 == 0) {
							value = longdp[ex].back().ss;
 } else {
							value = { longdp[ex].back().ss[1], longdp[ex].back().ss[0] };
 }
						longdp[ex].pop_back();
 } else {
 if (e.length(cur) % 2 == 0) {
							value[0] = dp[i - e.length(cur)];
 } else {
							value[1] = dp[i - e.length(cur)];
 }
 }
 int preflength = (e.length(cur) % e.sl_diff(cur) == 0 ? e.sl_diff(cur) : e.length(cur) % e.sl_diff(cur));
 int ex2 = ex - preflength;
 if (preflength != e.sl_diff(cur)) {
 if ((i - ex2) % 2 == 0) {
							value[0] = (value[0] + dp[ex2]) % mod;
 } else {
							value[1] = (value[1] + dp[ex2]) % mod;
 }
 }
 //cout << ex << " " << ex2 << " " << value[0] << " " << value[1];
					dp[i] = (dp[i] + value[0]) % mod;
					longdp[i].pb(mp(e.sl_diff(cur), value));
 } else {
 //cout << dp[i - e.length(cur)];
 if (e.length(cur) % 2 == 0)
						dp[i] = (dp[i] + dp[i - e.length(cur)]) % mod;
 }
 //cout << endl;
				cur = e.long_suffix_link(cur);
 }
			reverse(all(longdp[i]));
 }
 //for (int u : dp)
 //cout << u << " ";
 //cout << endl;
 return dp[n];
 }
};
 
const int even_palidrome_partitions::eertree::SIGMA;
const int even_palidrome_partitions::eertree::ODD_ROOT;
const int even_palidrome_partitions::eertree::EVEN_ROOT;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
 // Code here:
 
	string s;
	cin >> s;
 
	string t;
 for (int i = 0; i < (int)s.size(); i++) {
 if (i % 2 == 0)
			t.pb(s[i / 2]);
 else
			t.pb(s[s.size() - 1 - (i / 2)]);
 }
 //cerr << t << endl;
 
	even_palidrome_partitions epp(t);
 
	cout << epp.solve() << endl;
 return 0;
}
