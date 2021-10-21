/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
char s[SIZE],s2[SIZE];
int end_id;
struct node{
 int nxt[26];
 int len;
 int fail;
 void init(int _len,int _fail=-1){
        MS1(nxt);
        fail=_fail;
        len=_len;
 }
}d[SIZE];
int find_fail(int lt,int id,char c){
 while(id!=-1&&(lt-d[id].len-1<0||s[lt-d[id].len-1]!=c))id=d[id].fail;
 return id;
}
int add(int lt,int id,char c){
 if(d[id].nxt[c-'a']!=-1)return d[id].nxt[c-'a'];
    id=find_fail(lt,id,c);
 if(id==-1)return d[id].nxt[c-'a']=0;
 int jump=find_fail(lt,d[id].fail,c);
    d[end_id].init(d[id].len+2,jump==-1?0:d[jump].nxt[c-'a']);
 return d[id].nxt[c-'a']=end_id++;
}
LL dp[SIZE];
void solve(int n){
    dp[0]=1;
 int now=end_id++;
    d[now].init(0);
    VI suffix;
    REP(i,n){
        now=add(i,now,s[i]);
        suffix.PB(d[now].len);
 for(int it=now;it>0;it=d[it].fail){
            ADD(dp[i+1],dp[i-d[it].len+1]);
 }
 }
    W(dp[n]);
}
int main(){
    RS(s2);
 int n=LEN(s2);
 {
 int it=0;
        REP(i,n/2){
            s[it++]=s2[i];
            s[it++]=s2[n-1-i];
 }
 }
    solve(n);
 return 0;
}
