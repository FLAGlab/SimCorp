#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 999;
int saveori[maxn];
int temp[maxn];
map<int, int>pos;
int len[maxn];
void solve(){
 int n;
    scanf("%d", &n);
    pos.clear();
 for(int i = 1; i<=n;i++){
        scanf("%d", &saveori[i]);
        pos[saveori[i]] = i;
        temp[i] = saveori[i];
 }
    sort(temp + 1, temp + 1 + n);
    len[1] = 1;
 int ans = 1;
 for(int i =2; i<=n;i++){
 if(pos[temp[i-1]] < pos[temp[i]]){
            len[i] = len[i-1] + 1;
 }
 else{
            len[i] = 1;
 }
        ans = max(ans, len[i]);
 }
    printf("%d\n", n - ans);
}
 
signed main(){
 // freopen("in.txt", "r", stdin);
 int T;
    cin>>T;
 while(T--)
    solve();
}
