#include<bits/stdc++.h>
 
using namespace std;
using i64 = long long;
using i32 = int;
 
const i64 INF = LLONG_MAX /4;
const int MAX_BIRDS = 10004;
template<typename T> T load() { T x; cin >> x; return x; }
template<typename T> vector<T> loadN(int s) { vector<T> vt(s); for(auto& el : vt) el = load<T>(); return vt; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& vt) { for(auto& el : vt) os << el << ' '; return os; }
 
signed main() {
    ios::sync_with_stdio(false);
 auto treeNum = load<int>();
 auto startLimit = load<i64>();
 auto gain = load<i64>();
 auto restore = load<int>();
 auto lives = loadN<i64>(treeNum);
 auto costs = loadN<i64>(treeNum);
 auto lastRange = 0;
 auto newRange = 0;
 auto curr = vector<i64>(MAX_BIRDS + 77, -INF);
 auto next = vector<i64>(MAX_BIRDS + 77, -INF);
    curr[0] = startLimit - restore;
 
 for(int tree = 0 ; tree < treeNum ; ++tree) {
 auto single = costs[tree];
 for(int birds = 0 ; birds <= lastRange ; ++birds) {
            i64 mana = min((curr[birds] + restore), (startLimit + birds * gain));
 if(curr[birds] != -INF) {
 auto canBuy = min(mana / single, lives[tree]);
 for(int buying = 0 ; buying <= canBuy ; ++buying) {
                    next[birds + buying] = max(next[birds + buying], mana - buying * single);
                    newRange = max(newRange, birds + buying);
 }
 }
 }
        lastRange = max(lastRange, newRange);
        swap(curr, next);
 }
 auto result = 0;
 for(int i = 0 ; i < MAX_BIRDS; ++i) {
 if(curr[i] != -INF) 
            result = i;
 }
    cout << result << '\n';
}
