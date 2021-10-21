#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 100005;
struct point {
 double x, y;
};
 
point p[maxn], ans[maxn];
 
double slope(point x, point y){
 return (double)(y.y - x.y)/(y.x - x.x);
}
 
int main(int argc, char const *argv[])
{
 int n;
  scanf("%d", &n);
 for(int i = 1; i <= n; ++i){
    scanf("%lf %lf", &p[i].x, &p[i].y);
    p[i].y -= (p[i].x * p[i].x);
 }
  sort(p + 1, p + n + 1, [&](point x, point y){
 if(x.x != y.x)return x.x < y.x;
 else {
 return x.y < y.y;
 }
 });
 int sz = 0;
 for(int i = 1; i <= n; ++i){
 if(sz && p[i].x == ans[sz].x)--sz;
 while(sz > 1 && slope(ans[sz - 1], p[i]) >= slope(ans[sz], ans[sz - 1]))--sz; 
    ans[++sz] = p[i];
 }
  printf("%d\n", sz - 1);
 
 return 0;
}
