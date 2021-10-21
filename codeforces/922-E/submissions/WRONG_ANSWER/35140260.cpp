#include <iostream>
#include <map>
using namespace std;
 
const int N = 1e4+5, M = 1e3+5;
int n,w,b,x;
map<int,int> dp[N][M];
int birds[M], cost[M];
 
int go(int mana,int ix,int avail) {
 if(ix > n || (!avail) || cost[ix] > mana) return 0;
 auto it = dp[avail][ix].find(mana);
 if(it != dp[avail][ix].end()) return it->second;
 int ans = 1+go(mana - cost[ix] + b,ix,avail-1);
    ans = max(ans,go(mana + x,ix+1,birds[ix+1]));
    dp[avail][ix][mana] = ans;
 return ans;
}
 
int main() {
    cin >> n >> w >> b >> x;
 for(int i=1;i<=n;i++) cin >> birds[i];
 for(int i=1;i<=n;i++) cin >> cost[i];
    cout << go(w,1,birds[1]);
}
 
 
