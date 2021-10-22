#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
 int t, k, i;
	string s;
	cin >> t;
 while (t--) {
		k = 0;
		cin >> s;
 for (i = 0; i < s.size(); i++)
 if (s[i] == 'B')
				k++;
 if (k == s.size() - k)
			cout << "YES\n";
 else
			cout << "NO\n";
 }
 return 0;
}
