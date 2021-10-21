#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
typedef long long ll;
 
struct Point
{
    ll x, y;
 
 Point(ll _x, ll _y): x(_x), y(_y) {};
 Point() {};
 
 void scan()
 {
        scanf("%lld%lld", &x, &y);
 }
 void print()
 {
        printf("%lld %lld\n", x, y);
 }
 
 bool operator < (const Point & A)
 {
 if (x != A.x) return x < A.x;
 return y < A.y;
 }
 Point operator - (const Point & A)
 {
 return Point(x - A.x, y - A.y);
 }
    ll operator ^ (const Point & A)
 {
 return x * A.y - A.x * y;
 }
};
 
 
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
 
 int n;
    scanf("%d", &n);
 Point* p = new Point[n];
 for (int i = 0; i < n; ++i)
 {
        p[i].scan();
        p[i].y -= p[i].x * p[i].x;
 }
    sort(p, p + n);
 int start = 0;
 while(start < n && p[start].x == p[0].x)
 ++start;
 --start;
    p += start;
 
 vector<Point> hull;
    hull.push_back(p[0]);
 for (int i = 1; i < n; ++i)
 {
 if (((p[n - 1] - p[0]) ^ (p[i] - p[0])) < 0)
 continue;
 
 for (int j = (int)hull.size() - 1; j > 0 && ((p[i] - hull[j]) ^ (hull[j] - hull[j - 1])) <= 0; --j)
            hull.pop_back();
        hull.push_back(p[i]);
 }
 
    printf("%d", (int)hull.size() - 1);
}
