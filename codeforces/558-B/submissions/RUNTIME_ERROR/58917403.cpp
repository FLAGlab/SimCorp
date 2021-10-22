#include<bits/stdc++.h>
#define SZ 1000001
 
using namespace std;
 
signed main() {
 int n;
	cin >> n;
 int a[n], left[SZ], right[SZ], count[SZ], _max = 0;
 for(int i = 0; i < SZ; i++) {
 if(i < n)
			cin >> a[i];
		left[i] = right[i] = -1;
		count[i] = 0;
 }
 for(int i = 0; i < n; i++) {
		count[a[i]]++;
		right[a[i]] = i;
		_max = max(_max, count[a[i]]);
 if(left[a[i]] == -1)
			left[a[i]] = i;
 }
 
 int l = -1, r = -1;
 for(int i = 0; i < n; i++) {
 if(count[a[i]] == _max && (right[a[i]] - left[a[i]] + 1 < r - l + 1 || l == -1 && r == -1)) {
			r = right[a[i]];
			l = left[a[i]];
 }
 }
	cout << l + 1 << " " << r + 1 << endl;
 return 1;
}
