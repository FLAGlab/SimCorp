#include <bits/stdc++.h>
using namespace std;
const int C = 26, N = 1e6 + 5, MOD = 1e9 + 7;
struct node {
	node *child[C], *fail, *slink;
 int length, cnt, diff, series;
	node(int length) : fail(NULL), slink(NULL), length(length)
 {memset(child, NULL, sizeof(child)); cnt = diff = series = 0;}
};
int size, text[N];
node *odd, *even;
node *match(node *now) {
 for (; text[size - now->length - 1] != text[size]; now = now->fail);
 return now;
}
bool extend(node *&last, int token) {
	text[++ size] = token;
	node *now = match(last);
 if (now->child[token])
 return last = now->child[token], false;
	last = now->child[token] = new node(now->length + 2);
 if (now == odd) last->fail = even;
 else {
		now = match(now->fail);
		last->fail = now->child[token];
 }
	last -> cnt ++;
	last -> diff = last -> length - last -> fail -> length;
 if (last->diff == last->fail->diff) {
		last->slink = last->fail->slink;
 }
 else {
		last->slink = last->fail;
 }
 return true;
}
void init() {
	text[size = 0] = -1;
	even = new node(0), odd = new node(-1);
	even->fail = odd;
}
node *pos[N];
int ans[N], series_ans[N];
void build(char *s) {
 int n = (int) strlen(s);
	pos[0] = odd; ans[0] = 1;
 for (int i = 1; i <= n; ++ i) {
		extend(pos[i] = pos[i - 1], s[i - 1] - 'a');
 for (node *v = pos[i]; v -> length > 0; v = v -> slink) {
			v -> series = ans[i - (v -> slink -> length + v -> diff)];
 if (v -> diff == v -> fail -> diff) {
 (v -> series += v -> fail -> series) %= MOD;
 }
 if (v -> length % 2 == 0) (ans[i] += v -> series) %= MOD;
 }
 }
 for (int i = n; i > 0; -- i) pos[i] -> fail -> cnt += pos[i] -> cnt;
}
char s[N], t[N];
int main() {
	scanf("%s", s);
 int n = (int) strlen(s);
 if (n & 1) return 0 * puts("0");
 for (int i = 0; i < n / 2; ++ i) t[i * 2] = s[i];
 for (int i = n - 1; i >= n / 2; -- i) t[(n - 1 - i) * 2 + 1] = s[i];
	init();
	build(t);
	printf("%d\n", ans[n]);
}
 
