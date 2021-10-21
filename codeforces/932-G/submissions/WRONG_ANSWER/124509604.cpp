#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
#define ll long long
const int mod = (int) 1e9 + 7;
static int dp[501][501];
bool isPalindrome(string s, int i, int j) {
 while (i < j) {
 if (s[i] != s[j])
 return false;
		i++;
		j--;
 }
 return true;
}
int solve(string s, int i, int j) {
 if (dp[i][j] != -1)
 return dp[i][j];
 
 if (i >= j || isPalindrome(s, i, j)) {
		dp[i][j] = 0;
 return 0;
 }
 
 int ans = INT_MAX; int left = 0, right = 0;
 for (int k = i; k <= j - 1; k++) {
 int temp_ans = solve(s, i, k) + solve(s, k + 1, j) + 1;
		ans = min(ans, temp_ans);
 }
 return ans;
}
int main() {
#ifndef ONLINE_JUDGE
 //for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
 //for writing output to output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif
	memset(dp, -1, sizeof(dp));
	string s;
	cin >> s;
	cout << solve(s, 0, s.size() - 1) << endl;
 return 0;
}
