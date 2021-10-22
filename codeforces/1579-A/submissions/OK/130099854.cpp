#include<bits/stdc++.h>
using namespace std;

signed main() {
    int t = 0;
    vector<string> v;
    cin >> t;
    while(t--) {
        int arr[5] = {0};
        string str = "";
        cin >> str;
        for(int i = 0; i < str.length(); i++)
            arr[str[i]-'A']++;
        v.push_back(arr[1] == arr[0] + arr[2] ? "YES" : "NO");
    }
    for(auto i: v)
        cout << i << "\n";
    return 0;
}

