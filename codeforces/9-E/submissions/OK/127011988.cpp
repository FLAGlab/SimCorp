#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
#define uLL unsigned LL
#define INF 0x3f3f3f3f
#define LL long long
#define reg register
#define R read()
#define N 55
inline LL read(){
    LL s=0, f=1; char c=getchar();
 while(!isdigit(c)) { if(c=='-') f=-f; c=getchar(); }
 while(isdigit(c)) s=(s<<3)+(s<<1)+(c^48), c=getchar();
 return s*f;
}
int n, m, tot, d[N], f[N]; pair<int, int> ans[N];
inline int Find(int r) { return f[r]==r?r:f[r]=Find(f[r]); }
inline void Merge(int x, int y) { x=Find(x), y=Find(y), f[x]=y; }
int main(){
    n=R, m=R;
 if(m>n) { puts("NO"); return 0; }
 if(n==1&&!m) { puts("YES\n1\n1 1"); return 0; }
 for(reg int i=1; i<=n; ++i) f[i]=i;
 for(reg int i=1; i<=m; ++i){
 int x=R, y=R; Merge(x, y);
 if(++d[x]>2) { puts("NO"); return 0; }
 if(++d[y]>2) { puts("NO"); return 0; }
 }
 for(reg int i=1; i<=n; ++i)
 for(reg int j=i+1; j<=n; ++j)
 if(Find(i)!=Find(j)&&d[i]<2&&d[j]<2)
 ++d[i], ++d[j], Merge(i, j), ans[++tot]=make_pair(i, j);
 if(m+tot+1==n)
 for(reg int i=1; i<=n; ++i)
 for(reg int j=i+1; j<=n; ++j)
 if(d[i]<2&&d[j]<2) ++d[i], ++d[j], Merge(i, j), ans[++tot]=make_pair(i, j);
 for(reg int i=2; i<=n; ++i) if(Find(i)!=Find(i-1)) { puts("NO"); return 0; }
    sort(ans+1, ans+tot+1);
    puts("YES"), printf("%d\n", tot);
 for(reg int i=1; i<=tot; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
 return 0;
}
