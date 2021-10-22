#include<bits/stdc++.h>
 
 
using namespace std;
 
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cf.inp","r",stdin);
    freopen("cf.out", "w", stdout);
 int t,a,b,c;
    a=0;
    b=0;
    c=0;
    string s;
    cin >> t;
 while (t>0)
 {
            a=0;
            b=0;
            c=0;
            t--;
            cin >> s;
 for (int i=0; i<s.length(); i++)
 {
 if (int(s[i])==65) a++;
 else if (int(s[i])==66) b++;
 else if (int(s[i])==67) c++;
 }
 if (b==a+c) cout << "YES\n";
 else cout << "NO\n";
 }
}
