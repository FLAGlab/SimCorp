#include <bits/stdc++.h>
 
using namespace std;
 
#define link abaaalal
 
const int maxn = 1e6 + 42, sigma = 26;
int len[maxn], link[maxn], to[maxn][sigma];
int slink[maxn], diff[maxn], series_ans[maxn][2][2];
int sz, last, n;
char s[maxn];
 
void init() {
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    sz = 2;
}
 
int get_link(int v) {
 while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
 return v;
}
 
void add_letter(char c) {
    s[n++] = c -= 'a';
    last = get_link(last);
 if(!to[last][c])
 {
        len[sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        diff[sz] = len[sz] - len[link[sz]];
 if(diff[sz] == diff[link[sz]])
            slink[sz] = slink[link[sz]];
 else
            slink[sz] = link[sz];
        to[last][c] = sz++;
 }
    last = to[last][c];
}
 
const int mod = 1e9 + 7;
 
 
int min_pal(string s) {
    init();
 int n = s.size();
 int ans[n + 1][2];
    memset(ans, 0, sizeof(ans));
    ans[0][0] = 1;
 //cout << s << endl;
 for(int i = 1; i <= n; i++) {
        add_letter(s[i - 1]);
 for(int v = last; len[v] > 0; v = slink[v]) {
 int mn_len = len[slink[v]] + diff[v];
            series_ans[v][mn_len % 2][0] = ans[i - mn_len][0];
            series_ans[v][mn_len % 2][1] = ans[i - mn_len][1];
 if(diff[v] == diff[link[v]]) {
 for(int z = 0; z <= 1; z++) {
                    series_ans[v][z][0] += series_ans[link[v]][z ^ (diff[v] % 2)][0];
                    series_ans[v][z][1] += series_ans[link[v]][z ^ (diff[v] % 2)][1];
 }
 }
            ans[i][0] += series_ans[v][0][1];
            ans[i][1] += series_ans[v][0][0];
            ans[i][0] %= mod;
            ans[i][1] %= mod;
            series_ans[v][0][0] %= mod;
            series_ans[v][0][1] %= mod;
            series_ans[v][1][0] %= mod;
            series_ans[v][1][1] %= mod;
 }
 }
    cout << (ans[n][0] + ans[n][1]) % mod << endl;
}
 
signed main() {
 //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a;
    b = string(a.rbegin(), a.rend());
    string c;
 for(int i = 0; i < a.size() / 2; i++) {
        c += a[i];
        c += b[i];
 }
    min_pal(c);
 return 0;
}
 
