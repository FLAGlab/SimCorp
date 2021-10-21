#include <cstdio>
#include <algorithm>
const int N = 1e5+5;
typedef long long ll;
struct P {
    ll x, y;
    P(ll x=0, ll y=0): x(x), y(y){}
    P operator - (P p) { return {x-p.x, y-p.y}; }
    ll operator ^ (P p) { return x*p.y-y*p.x; }
 bool operator < (P p) {
 if(x == p.x) return y > p.y;
 return x < p.x;
 }
} p[N], q[N], stk[N];
 
int n, m, top;
int main() {
    scanf("%d", &n);
 for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
        p[i].y -= p[i].x*p[i].x;
 }
    std::sort(p+1, p+n+1);
    q[m = 1] = p[1];
 for(int i = 2; i <= n; i++) if(p[i].x != p[i-1].x) q[++m] = p[i];
 for(int i = 1; i <= m; i++) {
 while(top > 1 && ((stk[top]-stk[top-1])^(q[i]-stk[top-1])) >= 0) top--;
        stk[++top] = q[i];
 }
    printf("%d\n", top-1);
 return 0;
}
 
