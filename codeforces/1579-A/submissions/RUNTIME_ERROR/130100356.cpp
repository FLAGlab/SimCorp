#include<bits/stdc++.h>
 
inline int read() {
 int x = 0, f = 1; char ch = getchar();
 while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
 while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
 return x * f;
}
 
char s[100]; int a[3];
 
void Solve() {
    std::scanf("%s",s);
    a[0] = a[1] = a[2] = 0;
 for(int i = 0;s[i];i++) a[s[i] - 'a']++;
 if(a[1] == a[0] + a[2]) std::puts("YES");
 else std::puts("NO");
 return;
}
 
signed main() {
 int t = read();
 while(t--) Solve();
 return 0;
}
