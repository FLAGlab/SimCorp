#include <bits/stdc++.h>
 
using namespace std;
bool IsPalindrome(string str, int j)
{
 if (str.empty())
 return false;
 int i = 0;
 while (i < j)
 {
 if (str[i] != str[j])
 {
 return false;
 }
        i++;
        j--;
 }
 return true;
}
int n;
string s;
bool l = 1;
 
int main ()
{
  cin >> n >> s;
 for (int i = 1; i < n; i++) 
 {
 if (l)
 {
      l = IsPalindrome(s, i);
 break;
 }
 }
 if (!l) cout << 2;
 else cout << -1;
 return 0;
}
