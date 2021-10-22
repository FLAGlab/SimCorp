#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
 
ll qmi(ll a, ll b, ll p = 1e9 + 7){
	ll res = 1;
 while(b){
 if(b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
 }
 return res;
}
 
void solve(){
 
}
 
signed main(){
 int T; scanf("%d", &T);
 while(T --){
		solve();
 }
 return 0;
}
