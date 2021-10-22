#include<bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);
 int n;
    ll W, B, X;
    cin >> n >> W >> B >> X;
 priority_queue<long long>PQ;
    ll val, capacity=W;
 int birds=0;
 vector<ll>bir(n);
 for (int i=0;i<n;i++){
        cin >> bir[i];
 }
 for (int i=0;i<n;i++){
        cin >> val;
 while(bir[i]>0 and ((PQ.empty() and W>=val) or (val<PQ.top() or W>=val))){
 if (W>=val){
                W-=val;
                birds++;
                PQ.push(val);
                capacity+=B;
                bir[i]--;
 }
 else if (!PQ.empty()){
                ll v=PQ.top();
 if (v>val){
                    W+=(v-val);
                    PQ.pop();
                    PQ.push(val);
                    W=min(W, capacity);
                    bir[i]--;
 }
 }
 }
        W+=X;
        W=min(W, capacity);
 }
    cout << birds << "\n";
 return 0;
}
