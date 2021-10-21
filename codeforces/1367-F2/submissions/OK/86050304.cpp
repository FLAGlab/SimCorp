#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 2e6 + 5;
 
int a[MAXN], b[MAXN], la[MAXN], fi[MAXN], num1[MAXN], num2[MAXN], s[MAXN], n;
bool bg[MAXN]; 
int main() {
 int T; cin >> T;
 while (T--) {
		scanf("%d", &n);
 for (int i = 1; i <= n; i++) s[i] = 0, bg[i] = 0, num1[i] = num2[i] = 0;
 for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
		sort(b + 1, b + n + 1); 
 int l = unique(b + 1, b + n + 1) - 1 - b, t = 0;
 for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + l + 1, a[i]) - b;
 for (int i = 1; i <= n; i++) la[a[i]] = i;
 for (int i = n; i >= 1; i--) fi[a[i]] = i; 
 for (int i = 1; i <= n; i++) num1[a[i]] ++;
 int ans = 0;
 for (int i = 1; i <= n; i++) {
			s[a[i]] = s[a[i]] + 1;
 
 if (a[i] > 1 && i == fi[a[i]]) {
 				s[a[i]] = max(s[a[i]], num2[a[i] - 1] + 1);
 }
 if (a[i] > 1 && i == fi[a[i]] && la[a[i] - 1] < i){
				s[a[i]] = max(s[a[i]], s[a[i] - 1] + 1);
 }
 
 if (la[a[i] - 1] < i) {
				ans = max(ans, num1[a[i]] + s[a[i] - 1]);
				ans = max(ans, s[a[i]]);
 } else {
				ans = max(ans, num1[a[i]] + num2[a[i] - 1]);
 }
 
			num1[a[i]]--;
			num2[a[i]]++;
 }
 
//		printf("%d\n", ans);
//		for (int i = 1; i <= n; i++) 
//			printf("%d: %d\n", i, s[i]); 
		printf("%d\n", n - ans); 
 }
 return 0;
}
