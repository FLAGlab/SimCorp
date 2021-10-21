#include<iostream>
using namespace std;
int i,n,o,x,x1;
string s;
main(){
    cin >> n;
 for (i = 0; i < n; i++)
 {
        cin >> s;
        x = 0; x1 = 0;
 for (o=0; o<s.size(); o++){
 if(s[o] == 'B'){ x++; } else { x1++; }
 }
 if(x == x1) cout << "YES";
 else cout << "NO";
 }
}
