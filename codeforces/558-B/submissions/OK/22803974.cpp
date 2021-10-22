#include<bits/stdc++.h>
// In the name of GOD!
// 08 / 12 / 2016
// 1395 / 09 / 18
 
 
#define F first
#define S second
 
using namespace std;
 
typedef pair<int , int> pii;
 
const int A = 1e6 + 5;
 
pii num[A];
 
signed main() {
 int n, m = 0, l, r;
 
	cin >> n;
 for (int i = 0; i < n; i++) {
 int a;
		cin >> a;
 if (!num[a].F) num[a].S = i;
		num[a].F++;
 if (m < num[a].F ||
 (m == num[a].F && i - num[a].S < r - l)) {
			 m = num[a].F;
			 l = num[a].S, r = i;
 }
 }
 
	cout << l + 1 << ' ' << r + 1 << '\n';
 
 return 0;
}
