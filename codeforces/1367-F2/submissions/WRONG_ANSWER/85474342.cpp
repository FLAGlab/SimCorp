#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 2000 + 2;
 
int hp[maxN];
int n, M;
 
bool check(long long P)
{
 long long moves = 0;
 
 for(int i=0; i<n; i++) {
        moves += (hp[i] + P - 1) / P;
 if(moves > M)
 return 0;
 }
 
 return 1;
}
 
int main()
{
 int q;
    scanf("%d %d", &n, &q);
 
 long long sum = 0;
 
 for(int i=0; i<n; i++) {
        scanf("%d", &hp[i]);
        sum += hp[i];
 }
 
 while(q --) {
        scanf("%d", &M);
 
 long long lo = 1, hi = sum, ans;
 
 while(lo <= hi) {
 long long mid = (lo + hi) / 2;
 if(check(mid)) {
                ans = mid, hi = mid - 1;
 } else {
                lo = mid + 1;
 }
 }
 
        printf("%lld\n", ans);
 }
}
