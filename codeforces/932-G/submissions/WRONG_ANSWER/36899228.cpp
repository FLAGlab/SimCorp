#include <cstdio>
#include <algorithm>
#include <map>
const int MOD = 1000000007;
int N, f[500002], p[30], L, new_p[30], new_L, new_last;
char a[1000002], b[500002];
std::map < int, int > R[1000001];
int main()
{
	scanf("%s", a + 1);
 while (a[N + 1])
		N++;
	N >>= 1;
 for (int i = 1; i <= N; i++)
		b[i] = a[N + N + 1 - i];
	a[N + 1] = '\0';
	f[0] = 1;
	L = -1;
 for (int i = 1; i <= N; i++)
 {
 // p[0]
 // p[0] - p[1], p[0] - p[1] * 2, ..., p[0] % p[1]
 // p[0] % p[1] - p[2], p[0] % p[1] - p[2] * 2, ..., p[0] % p[1] % p[2]
 // ...
 // ..., p[0] % p[1] % p[2] % ... % p[L]
 // 0
		new_L = new_last = -1;
 if (L != -1)
 {
 if (p[0] <= i - 2 && a[i] == b[i - p[0] - 1] && b[i] == a[i - p[0] - 1])
 {
				new_last = new_p[0] = p[0] + 2;
				new_L = 0;
 }
 for (int last = p[0], j = 1; j <= L; j++)
 {
 if (a[i] == b[i - (last - p[j]) - 1] && b[i] == a[i - (last - p[j]) - 1])
 {
 if (new_L == -1)
 {
						new_p[0] = last - p[j] + 2;
						new_L = 0;
 }
 else
						new_p[++new_L] = new_last - (last - p[j] + 2);
 if (last > p[j] + p[j])
						new_p[++new_L] = p[j];
					new_last = (last - 1) % p[j] + 3;
 }
				last = (last - 1) % p[j] + 1;
 }
 }
 if (a[i] == b[i - 1] && b[i] == a[i - 1])
 {
 if (new_L == -1)
 {
				new_last = new_p[0] = 2;
				new_L = 0;
 }
 else
				new_p[++new_L] = new_last - 2;
			new_last = 2;
 }
 if (a[i] == b[i])
 {
 if (new_L == -1)
 {
				new_last = new_p[0] = 1;
				new_L = 0;
 }
 else
				new_p[++new_L] = new_last - 1;
			new_last = 1;
 }
		std::copy(new_p, new_p + (L = new_L) + 1, p);
 if (L > 0)
			L = std::unique(p + 1, p + L + 1) - p - 1;
 if (L != -1)
 {
			f[i] = f[i - p[0]];
 for (int last = p[0], j = 1, nxt; j <= L; j++)
 {
				f[i] = (f[i] + (R[i][p[j]] = ((last > p[j] + p[j] ? R[i - p[j]][p[j]] : 0) + f[i - (nxt = (last - 1) % p[j] + 1)]) % MOD)) % MOD;
				last = nxt;
 }
 }
 }
	printf("%d\n", f[N]);
 return 0;
}
