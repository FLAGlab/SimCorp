#include<bits/stdc++.h>
 
signed main() {
 long long N, W, B, X, n[1010], c[1010], w[10100], b[10100], t[10100] = {}, back, i, j, k, ww, bb;
 for (scanf("%lld%lld%lld%lld", &N, &W, &B, &X), i = 1; i <= N; i++)
		scanf("%lld", n+i);
 for (i = 1; i <= N; i++)
		scanf("%lld", c+i);
 for (w[0] = W, b[0] = W, t[0] = 1, back = 0, i = 1; i <= N; i++)
 for (j = back; j >= 0 && !t[j+n[i]]; j--)
 for (k = 1; k <= n[i]; k++)
 (ww = ((i-t[j])*X+w[j] < b[j] ? (i-t[j])*X+w[j] : b[j])-k*c[i]) >= 0 && (!t[j+k] || (w[j+k]+(i-t[j+k])*X < b[j+k] ? w[j+k]+(i-t[j+k])*X : b[j+k]) < ww) && (w[j+k] = ww, b[j+k] = b[j]+B*k, t[j+k] = i, back < j+k && (back = j+k));
	printf("%lld\n", back);
}
