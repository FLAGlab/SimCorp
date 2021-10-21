#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
 
const int mxn = 200000;
int n, k;
int a[mxn], b[mxn], f[mxn], ff[mxn], dp[mxn], dpf[mxn];
 
void answer(){
	cin >> n;
 
 for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		f[i] = ff[i] = dp[i] = dpf[i] = 0;
 } 
 
	sort(b, b + n);
	k = unique(b, b + n) - b;
 
 for(int i = 0; i < n; i++) f[a[i] = lower_bound(b, b + k, a[i]) - b]++;
 
 for(int i = 0; i < n; i++){
 if(!(ff[a[i]]++) && a[i]){
 if(f[a[i] - 1] == ff[a[i] - 1]) dp[a[i]] = dp[a[i] - 1] + f[a[i] - 1];
 else dp[a[i]] = ff[a[i] - 1];
			dpf[a[i]] = dp[a[i]];
 }
		dpf[a[i]]++;
 if(a[i]) dpf[a[i]] = max(dpf[a[i]], 1 + ff[a[i] - 1]);
 }
 
	cout << (n - *max_element(dpf, dpf + k)) << endl;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
 int t;
	cin >> t;
 
 for(int i = 0; i < t; i++) answer();
 
 return 0;
}
