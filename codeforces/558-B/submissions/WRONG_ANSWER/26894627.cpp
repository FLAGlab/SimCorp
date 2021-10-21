#include <bits/stdc++.h>
using namespace std;
#define mx   1000060
map<int,int> start,End,cnt;
 
int main()
{
 int n;cin >> n;
 int keep;
 int maxx = -1;
 for(int i = 1;i <= n;i++){
 int x;cin >> x;
 if(!start[x]) start[x] = i;
 End[x] = i;
        cnt[x]++;
 if(cnt[x] > maxx){
            maxx = cnt[x];
            keep = x;
 }
 }
    cout << start[keep] <<" " << End[keep] << endl;
 return 0;
}
