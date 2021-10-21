#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
using namespace std;
typedef long long LL;
typedef double DB;
typedef unsigned int ui;
typedef unsigned long long ULL;
int f[1000005], g[1000005];
char S[1000005], T[1000005];
const int mod = 1000000007;
struct p_auto_machine {
 int ch[1000005][26], le[1000005], fl[1000005], la, tt, dc[1000005], rt[1000005];
 int get(int x, int wz) {
 while(S[wz] != S[wz - le[x] - 1]) x = fl[x];
 return x;
 }
 void push(int w, int id) {
 int cr = get(la, id);
 int np = ch[cr][w];
 if(cr == 1) {la = 0; return;}
 if(np == 0) {
			np = ++tt;
			le[np] = le[cr] + 2;
			fl[np] = ch[get(fl[cr], id)][w];
			ch[cr][w] = np;
			dc[np] = le[np] - le[fl[np]];
 if(dc[np] == dc[fl[np]]) rt[np] = rt[fl[np]];
 else rt[np] = np;
 }
		la = np;
 }
 void upd(int id) {
 int cr = la;
 while(cr) {
			g[cr] = ((rt[cr] != cr) * g[fl[cr]] + f[id - le[rt[cr]]]) % mod;
			f[id] = (f[id] + g[cr]) % mod;
			cr = fl[rt[cr]];
 }
 }
 void build(char *S) {
		le[1] = -(tt = fl[0] = fl[1] = 1);
		le[0] = la = 0;
		rt[0] = 1;
		f[0] = 1;
 int ls = strlen(S + 1);
		rep(i, 1, ls) {
			push(S[i] - 'a', i);
			upd(i);
 }
		printf("%d\n", f[ls]);
 }
 
}PAM;
int main() {
	scanf("%s", T + 1);
 int lt = strlen(T + 1);
 int ls = 0;
	reverse(T + 1 + lt / 2, T + 1 + lt);
	rep(i, 1, lt >> 1) {
		S[++ls] = T[i];
		S[++ls] = T[i + (lt >> 1)];
 }
	PAM.build(S);
 return 0;
}
