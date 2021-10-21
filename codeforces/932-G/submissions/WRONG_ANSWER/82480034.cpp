#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
using namespace std;
typedef long long LL;
typedef double DB;
const int mod = 998244353;
const int g = 3189;
inline int MOD(int x) {
 return x >= mod ? x - mod : x;
}
int qpow(int a, int b) {
 int as = 1;
 for(; b; a = 1ll * a * a % mod, b >>= 1) if(b & 1) as = 1ll * as * a % mod;
 return as;
}
struct r_e_d {
 inline int gti() {
 int x = 0, w = 1; char ch = getchar();
 while((ch < '0' || ch > '9') && ch != '-') ch = getchar();
 if(ch == '-') w = -1, ch = getchar();
 while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
 return x * w;
 }
 inline LL gtl() {
		LL x = 0, w = 1; char ch = getchar();
 while((ch < '0' || ch > '9') && ch != '-') ch = getchar();
 if(ch == '-') w = -1, ch = getchar();
 while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
 return x * w;
 }
 inline string gts() {
		string S; char ch = getchar();
 while(ch == ' ' || ch == '\n' || ch == '\r') ch = getchar();
 while(ch != ' ' && ch != '\n' && ch != '\r') S.push_back(ch), ch = getchar();
 return S;
 }
}RD;
/*---------------------------------------------------------------------------------------------*/
int ps[1000005], f[1000005];
char T[1000005], S[2000005];
//struct p_automachine {
//	int la, le[1000005], fl[1000005], ch[1000005][26], tt;
//	void init() {
//		tt = la = 1;
//		fl[1] = 1;
//		le[1] = 0;	
//	}
//	void push(int w, int wz) {
//		while(la != 1 && S[wz - le[la] - 1] != S[wz]) la = fl[la];
//		if(S[wz - le[la] - 1] != S[wz]) {ps[wz] = 1; return;}
//		if(ch[la][w]) la = ch[la][w];
//		else {
//			++tt;
//			int cr = la;
//			la = fl[la];
//			while(la != 1 && !ch[la][w]) la = fl[la];
//			if(!ch[la][w]) fl[tt] = 1;
//			else fl[tt] = ch[la][w];
//			le[tt] = le[cr] + 2;
//			ch[cr][w] = tt;
//			la = tt;
//		}
//		ps[wz] = la;
//	}
////	void work() {
////		
////	}
//}PAM;
struct P_automachine {
 int la, tt; 
 int fl[500005], ch[500005][26], le[500005], ct[500005];
 void push(int w, int wz) {
 while(S[wz - le[la] - 1] != S[wz]) la = fl[la];
 int np = ch[la][w];
 if(np == 0) {
			np = ++tt;
 int cr = la;
			la = fl[la];
 while(S[wz - le[la] - 1] != S[wz]) la = fl[la];
			fl[np] = ch[la][w];
			ct[np] = ct[fl[np]] + 1;
			ch[cr][w] = np;
			le[np] = le[cr] + 2;
 }
		la = np;
		ps[wz] = la;
 }
 void init() {
		tt = 1;
		fl[1] = fl[0] = 1;
		le[1] = -1;
		la = 0; 
 }
}PAM;
int ls, lt;
int main() {
	scanf("%s", T + 1);
	lt = strlen(T + 1);
	PAM.init();
	rep(i, 1, lt >> 1) {
		S[++ls] = T[i];
		S[++ls] = T[lt - i + 1]; 
 }
 
	rep(i, 1, ls) PAM.push(S[i] - 'a', i); 
	f[0] = 1;
	rep(i, 1, ls) {
 int x = ps[i];
 while(x > 1) { 
 if((PAM.le[x] & 1) == 0)f[i] += f[i - PAM.le[x]];
			x = PAM.fl[x];
 }
 }
	cout << f[ls] << endl;
 return 0;
}
