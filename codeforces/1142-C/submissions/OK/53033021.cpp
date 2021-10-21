#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100010
 
struct point {
 long long x, y;
 
 bool operator < (point o) const {
 if(x != o.x) return x < o.x;
 return y > o.y;
 }
};
 
bool ccw(point p1, point p2, point p3){
 long long ax = p2.x - p1.x, ay = p2.y - p1.y;
 long long bx = p3.x - p2.x, by = p3.y - p2.y;
 return ax*by - ay*bx >= 0;
}
 
point P[MAXN], H[MAXN];
 
int main(){
 int n;
 while(scanf("%d", &n) > 0){
 for(int i=0; i<n; i++){
      scanf("%lld%lld", &P[i].x, &P[i].y);
      P[i].y -= P[i].x * P[i].x;
 }
 
    sort(P, P+n);
 
 int q = 0;
 
 for(int i=0; i<n; i++){
 if(q >= 1 and P[i].x == H[q-1].x) continue;
 while(q >= 2 and ccw(H[q-2], H[q-1], P[i])) q--;
      H[q++] = P[i];
 }
 
    printf("%d\n", q-1);
 }
}
