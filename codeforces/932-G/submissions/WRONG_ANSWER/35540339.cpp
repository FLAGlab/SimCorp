#if (__APPLE__)
#include "/Users/zhaofuqing/c++_head/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define N (1000010)
#define INF (2100000000)
using namespace std;
typedef long long ll;
inline void __JUDGE__() {
	string __local = "/Users/zhaofuqing/IO_desktop/", __program = "test";
 #if (__APPLE__) 
	__program = __local + __program;
 #endif 
	string __in = __program + ".in", __out = __program + ".out";
	freopen(__in.c_str(), "r", stdin);  freopen(__out.c_str(), "w", stdout);
}
int n;
ll f[N], cnt[N];
char c[N], s[N];
struct palindromic_tree {
 int n, p, last, len[N], fail[N], nxt[N][26], cnt[N], num[N], s[N];
 inline int newnode(const int &l) {
 for (int i = 0; i < 26; ++i) nxt[p][i] = 0;
		cnt[p] = num[p] = 0; len[p] = l; return p++;
 }
 inline void init() {
		p = n = last = 0; newnode(0); newnode(-1); s[0] = -1; fail[0] = 1;
 }
 inline int get(int x) {
 for (; s[n - len[x] - 1] != s[n]; x = fail[x]) void(); return x;
 }
 inline void add(int c) {
		s[++n] = (c -= 'a');
 int cur = get(last); 
 if (!nxt[cur][c]) {
 int now = newnode(len[cur] + 2);
			fail[now] = nxt[get(fail[cur])][c];
			nxt[cur][c] = now; num[now] = num[fail[now]] + 1;
 }
		last = nxt[cur][c]; cnt[last]++;
 }
 inline void count() {
 for (int i = p - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
 }
 inline void print() {
 for (int i = 2; i < p; ++i) 
			printf("%c %d %d %d\n", s[i - 1] + 'a', cnt[i], num[i], fail[i]);
		puts("\n");
 for (int i = 0; i < p; ++i) {
			printf("%d : \n", i);
 for (int j = 0; j < 26; ++j) 
 if (nxt[i][j]) printf("  %c %d\n", s[nxt[i][j] - 1] + 'a', nxt[i][j]);
 }
		puts("\n");
 for (int i = 0; i < p; ++i) printf("%d : %d %d %d\n", i, fail[i], cnt[i], len[i]);
 }
} box;
int main() {
 #if (! ONLINE_JUDGE)
	__JUDGE__();
 #endif
 //insert code here...
	scanf("%s", c+1); n = (int)strlen(c+1);
 if (n & 1) return puts("0"), 0;
 for (int i = 1, now; i <= (n >> 1); ++i) {
		now = i << 1; s[now] = c[i]; s[now - 1] = c[n - i + 1];
 } 
 //printf("%s\n", s+1);
	box.init();
 for (int i = 1; i <= n; ++i) box.add(s[i]);
	box.count(); //box.print(); 
	f[0] = 1;
 for (int i = 1; i <= n; ++i) {
 int now = i + 1;
 for (int j = i + 1; j; j = box.fail[j]) 
 if ((box.len[j] & 1) == 0) f[i] += f[i - box.len[j]];
 }
	printf("%lld\n", f[n]);
 return 0;
}
