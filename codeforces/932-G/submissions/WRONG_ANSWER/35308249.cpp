#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int q = 0;
void feee(string str){
 int k = 0;
 int n = str.length();
    string a = "", b = "";
 for (int i = 1; i < n / 2 + 2; i++){
        a += str[0];
        b = str[str.length() - 1] + b;
 if (str.length() == 2) str = "";
 else str = str.substr(1, str.length() - 2);
 //cout << a << " " << b << endl << str << endl << endl;
 if (str.length() == 0){
 if (k % 2 == 0) q++;
 break;
 }
 if (a == b){
            feee(str);
            k++;
 }
 }
 //cout << "!-------------------- " << k << endl;
}
 
main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    feee(str);
    cout << q;
}
