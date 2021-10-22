#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 100005;
 
int num[N];
int freq[N];
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 int n;
  cin >> n;
 int mx = 0;
 int numb = -1;
 for(int i = 0; i < n; i++) {
    cin >> num[i];
    freq[num[i]]++;
 if(freq[num[i]] > mx) {
      mx = freq[num[i]];
      numb = num[i];
 }
 }
 int i__ = -1;
 int j__ = -1;
 for(int i = 0; i < n; i++) {
 if(num[i] == numb) {
      i__ = i + 1;
 }
 }
 for(int i = n - 1; i >= 0; i--) {
 if(num[i] == numb) {
      j__ = i + 1;
 }
 }
  cout << j__ << " " << i__ << "\n";
 return 0;
}
