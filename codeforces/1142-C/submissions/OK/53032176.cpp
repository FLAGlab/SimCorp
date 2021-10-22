#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
int n, st[100010], top;
pair<ll,ll> p[100010];
ll ccw(pair<ll,ll> &a, pair<ll,ll> &b, pair<ll,ll> &c) {
 return (ll)(b.X-a.X)*(c.Y-a.Y) - (ll)(b.Y-a.Y)*(c.X-a.X);
}
signed main() {
	scanf("%d", &n);
 for(int i=1; i<=n; i++) {
 int x, y;
		scanf("%d%d", &x, &y);
		p[i] = {x, y - (ll)x*x};
 }
	sort(p+1, p+n+1);
 
 for(int i=1; i<=n; i++) {
 while(top >= 2 && ccw(p[st[top-1]], p[st[top]], p[i]) >= 0) top--;
		st[++top] = i;
 }
 if(top >= 2 && p[st[top]].X == p[st[top-1]].X) top--;
 if(top >= 2 && p[st[1]].X == p[st[2]].X) top--;
	printf("%d", top - 1);
 return 0;
}
