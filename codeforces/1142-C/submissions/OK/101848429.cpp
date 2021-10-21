#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
struct point {
 int x;
 int y;
} a[maxn];
point ans[maxn];
int cur=0;
int n;
bool cmp(point a, point b) {
 if(a.x!=b.x) return a.x<b.x;
 return a.y<b.y;
}
int ccw(point a, point b, point c) {
 return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
signed main() {
    cin>>n;
 for(int i=1 ; i<=n ; i++) {
        cin>>a[i].x>>a[i].y;
        a[i].y-=(a[i].x*a[i].x);
 }
    sort(a+1,a+1+n,&cmp);
 for(int i=1 ; i<=n ; i++) {
 if(i!=n&&a[i].x==a[i+1].x) continue;
 while(cur>=2&&ccw(ans[cur-1],ans[cur],a[i])>=0) {
            cur--;
 }
        ans[++cur]=a[i];
 }
    cout<<cur-1;
}
