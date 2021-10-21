#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int maxn = 1e3+7;
const int MAXN = 1e4+7;
const ll INF = -1e18;
ll n,w,z,x,sz;
ll a[maxn],b[maxn];
ll dp[MAXN];
P sta[MAXN];
int p,h;
 
 
int main() {
    cin>>n>>w>>z>>x;
 for(int i=1;i<=n;i++) cin>>a[i];
 for(int i=1;i<=n;i++) cin>>b[i];
 for(int i=0;i<MAXN;i++) dp[i] = INF;
    dp[0] = w-x;
    p=-1;
 for(int i=1;i<=n;i++) {
        sz += a[i];
 for(int j=0;j<=sz;j++) {
            dp[j] += x;
            dp[j] = min(dp[j],w+j*z);
 while(h<=p && (sta[h].fir<j-a[i] || sta[h].sec-(j-sta[h].fir)*b[i] <0)) h++;
 if(j<=sz-a[i]) {
 while(h<=p && dp[j] >= sta[h].sec - (j-sta[h].fir)*b[i]) h++;
                sta[++p] = P(j,dp[j]);
 }
 if(h <= p ) dp[j] = sta[h].sec - (j-sta[h].fir)*b[i];
 }
 }
 for(int i=sz;i>=0;i--) {
 if(dp[i] >=0) {
            printf("%d\n",i);
 break;
 }
 }
 return 0;
}
 
