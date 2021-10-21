#include <iostream>
#include <algorithm>
 
#include <math.h>
 
using namespace std;
 
const int MAX_N = 1000 * 1000;
int n, t;
pair <long long int, int> number[MAX_N];
 
bool compare(pair<long long int, int> a, pair<long long int, int> b) {
 return a.first < b.first;
}
 
void solve() {
  sort(number, number + n, compare);
 const int temp = n;
 int m = 1;
 int start = 0;
 int end = 0;
 while(end < temp - 1) {
 while(number[end].second < number[end + 1].second && end < temp - 1) {
      end++;
 }
    m = max(m, end - start + 1);
    end++;
    start = end;
 }
  cout << temp - m << endl;
}
 
 
int main() {
  cin >> t;
 while(t--) {
    cin >> n;
 for (int i = 0; i < n; ++i) {
      cin >> number[i].first;
      number[i].second = i;
 }
    solve();
 }
 return 0;
}
