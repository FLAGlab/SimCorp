#include <bits/stdc++.h>
 
using namespace std;
 
int read(){
 int x, f = 1;
 char ch;
 while(ch = getchar(), ch < '0' || ch > '9') if(ch == '-') f = -1;
	x = ch - '0';
 while(ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - 48;
 return x * f;
}
 
const int N = 2e5 + 5;
int f[N], a[N], b[N], cnt[N], tot[N], fir[N], las[N];
 
int main(){
 int i, j, x, n, m, T, ans;
	T = read();
 while(T--){
		n = read(); ans = 0;
 for(i = 1; i <= n; i++) a[i] = b[i] = read();
		sort(b + 1, b + i);
		m = unique(b + 1, b + n + 1) - b - 1;
 for(i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b, cnt[a[i]]++;
 for(i = 1; i <= n; i++){
			x = a[i];
 
 if(tot[x - 1] == cnt[x - 1]) f[i] = max(f[i], f[fir[x - 1]] + tot[x - 1]);
 
 if(las[x]) f[i] = max(f[i], f[las[x]] + 1);
 
 if(las[x - 1]) f[i] = max(f[i], tot[x - 1] + 1);
 
			f[i] = max(f[i], 1);
 
			ans = max(ans, f[i]);
			las[x] = i;
 if(!fir[x]) fir[x] = i;
			tot[x]++;
 }
		printf("%d\n", n - ans);
 for(i = 1; i <= n; i++) cnt[i] = tot[i] = f[i] = fir[i] = las[i] = 0;
 }
 return 0;
}
 
