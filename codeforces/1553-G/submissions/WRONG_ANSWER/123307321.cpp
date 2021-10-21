#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
 
using namespace std;
 
int main(){
 // freopen("sample.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 // int t;
 // cin>>t;
 // while(t--){
 int n, m;
        cin>>n>>m;
 // cout<<n<<m<<endl;
        ll arr[n];
 for(int i=0;i<n;i++) cin>>arr[i];
 vector<pair<ll,int>> a, b;
 set<int> ev;
 for(int i=0;i<n;i++){
 if(arr[i]%2==0){
                a.push_back({arr[i],i}); ev.insert(i+1);
 }
 else b.push_back({arr[i],i});
 }
 for(auto i:b){
 bool flag = false;
 for(auto j:a){
 
 if(__gcd(i.first,j.first)>1){
                    flag = true;
                    ev.insert(i.second+1);
 }
 }
 }
 
 for(int i=0;i<m;i++){
 int p,q;
            cin>>p>>q;
 int count =2;
 if(ev.find(p)!=ev.end()) count--;
 if(ev.find(q)!=ev.end()) count --;
            cout<<count<<endl;
 }
 
 // }
 
}
