#include<bits/stdc++.h>
 
using namespace std;
 
const int   mod = 1e9 + 7;
const int   MX  = 1e6 + 1;
 
typedef long long   ll;
typedef vector<int> VI;
 
string s;
int D[MX];
int S[MX];
 
struct Eetree {
 int N, res;
 vector<map<int,int> >   nxt;
    VI  len;
    VI  diff;
    VI  link;
    VI  slik;
 
 Eetree(): N(0), res(0) {
 NewNode();  N++;
 NewNode();  N++;
        len[0] = -1;
 }
 
 void NewNode() {
        link.push_back(0);
        slik.push_back(0);
        diff.push_back(0);
        len.push_back(0);
        nxt.push_back({});
 }
 
 void addLetter(int i) {
 while(1) {
 if(i > len[res] && s[i - len[res] - 1] == s[i])
 break;
            res = link[res];
 }
 
 if(nxt[res].find(s[i]) != nxt[res].end()) {
            res = nxt[res][s[i]];
 return;
 }
 
 NewNode();
        nxt[res][s[i]] = N;
        len[N] = len[res] + 2;
 
 if(len[N] == 1) {
            link[N] = 1;
            slik[N] = 1;
            diff[N] = 1;
            res = N++;
 return;
 }
 
 while(1) {
            res = link[res];
 if(i > len[res] && s[i - len[res] - 1] == s[i])
 break;
 }
 
        link[N] = nxt[res][s[i]];
        diff[N] = len[N - 1] - len[link[N - 1]];
 if(diff[N] == diff[link[N]])
            slik[N] = slik[link[N]];
 else
            slik[N] = link[N];
        res = N++;
 }
}   pt;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string t;   cin >> t;
 int n = t.size();
 for(int i = 0 ; i < n / 2 ; ++i) {
        s.push_back(t[i]);
        s.push_back(t[n - i - 1]);
 }
 
    D[0] = 1;
 
 for(int i = 1 ; i <= n ; ++i) {
        pt.addLetter(i - 1);
 
 for(int v = pt.res ; v > 1 ; v = pt.slik[v]) {
            S[v] = D[i - pt.len[pt.slik[v]] - pt.diff[v]];
 if(pt.slik[v] != pt.link[v])
                S[v] = (S[v] + S[pt.link[v]]) % mod;
            D[i] = (D[i] + S[v]) % mod;
 }
 
 if(i & 1)   D[i] = 0;
 }
 
    cout << D[n] << endl;
}
