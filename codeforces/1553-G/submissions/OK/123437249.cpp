#include<iostream>
#include<vector>
#include<set>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 150100
#define M 1001000
using namespace std;
 
int frt[M], fa[M], a[N];
int n, q;
vector<int> prime;
set<int> conn[M];
 
void euler(){
    frt[1] = 1;
    rep(i,2,M-1){
 if(!frt[i]) prime.push_back(i), frt[i] = i;
 for(int j : prime){
 if(i*j >= M) break;
            frt[i*j] = j;
 if(i%j == 0) break;
 }
 }
    rep(i,1,M-1) fa[i] = i;
}
 
int find(int x){ return fa[x] == x ? x : (fa[x] = find(fa[x])); }
 
vector<int> get(int x){
 vector<int> ret;
 while(x > 1){
 int div = frt[x];
 while(x%div == 0) x /= div;
        ret.push_back(div);
 }
 return ret;
}
 
int main(){
    ios::sync_with_stdio(false);
    euler();
    cin>>n>>q;
    rep(i,1,n){
        cin>>a[i];
 vector<int> all = get(a[i]);
        rep(i,0,(int)all.size()-2) fa[find(all[i])] = find(all[i+1]);
 }
    rep(i,1,n){
 vector<int> all = get(a[i]+1);
 set<int> group;
        group.insert(find(frt[a[i]]));
 for(int k : all) group.insert(find(k));
 for(int a : group) for(int b : group) if(a != b)
            conn[a].insert(b);
 }
 
 int s, t;
    rep(i,1,q){
        cin>>s>>t;
 int x = find(frt[a[s]]), y = find(frt[a[t]]);
 if(x == y) cout<<"0\n";
 else if(conn[x].count(y)) cout<<"1\n";
 else cout<<"2\n";
 }
 return 0;
}
