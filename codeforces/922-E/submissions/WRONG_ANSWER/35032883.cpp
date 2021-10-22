#include<bits/stdc++.h>
 
signed main() {
 int N, W, B, X, n[1010], c[1010], w[10100] = {}, b[10100] = {}, t[10100] = {}, back, i, j, k, ww, bb;
 for (scanf("%d%d%d%d", &N, &W, &B, &X), i = 1; i <= N; i++)
		scanf("%d", n+i);
 for (i = 1; i <= N; i++)
		scanf("%d", c+i);
 for (w[0] = W, b[0] = W, t[0] = 1, back = 0, i = 1; i <= N; i++)
 for (j = back; j >= 0; j--)
 for (k = 1; k <= n[i]; k++)
				ww = ((i-t[j])*X+w[j] < b[j] ? (i-t[j])*X+w[j] : b[j])-k*c[i], ww >= 0 && (!t[j+k] || w[j+k] < ww) && (w[j+k] = ww, b[j+k] = b[j]+B*k, t[j+k] = i, back < j+k && (back = j+k));
	printf("%d\n", back);
}
