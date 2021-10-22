#include<bits/stdc++.h>
using namespace std;
 
signed main() {
 int tests;
    string t[50];
    cin >> tests;
 for(int test = 0; test < tests; ++test) {
        string s;
        cin >> s;
 int counter_a = 0;
 int counter_b = 0;
 int counter_c = 0;
 for (int i = 0; i < 50; ++i){
 if (s[i] == 'A')
                counter_a += 1;
 if (s[i] == 'B')
                counter_b += 1;
 if (s[i] == 'C')
                counter_c += 1;
 if (s[i] == '\0')
 break;
 }
 if ((counter_a + counter_c) == counter_b) t[test] = "YES";
 else t[test] = "NO";
 }
 for (int j = 0; j < 50; ++j) {
        cout << t[j] << endl;
 if ((t[j] != "YES") && (t[j] != "NO"))
 break;
 }
}
