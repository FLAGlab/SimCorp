#if (__APPLE__)
#include "/Users/zhaofuqing/c++_head/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define N (100010)
#define INF (2100000000)
#define mod (1000000007)
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
 int n, p, last, len[N], fail[N], nxt[N][26], cnt[N], num[N], s[N], pos[N];
 inline int newnode(int l) {len[p] = l; return p++;}
 inline void init() {
		newnode(0); newnode(-1); s[n] = -1; fail[0] = 1;
 }
 inline int get(int x) {
 while (s[n - len[x] - 1] != s[n]) x = fail[x]; return x;
 }
 inline void add(int c) {
		c -= 'a'; s[++n] = c;
 int cur = get(last); 
 if (!nxt[cur][c]) {
 int now = newnode(len[cur] + 2);
			fail[now] = nxt[get(fail[cur])][c];
			nxt[cur][c] = now; //num[now] = num[fail[now]] + 1;
 }
		pos[n] = last = nxt[cur][c]; cnt[last]++;
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
 for (int i = 0; i < p; ++i) printf("%d : %c %d %d %d\n", i, s[i - 1] + 'a', fail[i], cnt[i], len[i]);
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
 //printf("%d : ", i);
 for (int j = box.pos[i]; j > 1; j = box.fail[j]) 
 if ((box.len[j] & 1) == 0) {
 //printf("%d *%d ", i - box.len[j], box.fail[j]);
 (f[i] += f[i - box.len[j]]) %= mod;
 }
 //printf("\n");
 }
 //for (int i = 1; i <= n; ++i) printf("%lld ", f[i]);
	printf("%lld\n", f[n]);
 return 0;
}
