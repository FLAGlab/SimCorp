#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
 
typedef pair<int, int> pii;
 
vector<pii> numvec;
 
const int maxn = 1e6;
int nums[maxn];
int dp[maxn];
int gett[maxn];
 
int main(int argc, char const *argv[])
{
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 int t = 0;
	cin >> t;
 while(t--){
		numvec.clear();
 int n = 0;
		cin >> n;
 for(int i = 1;i <= n;i ++){
		    dp[i] = 0;
		    gett[i] = 0;
			cin >> nums[i];
			pii temp = {nums[i], i};
			numvec.push_back(temp);
 }
		sort(numvec.begin(), numvec.end());
 
 int now = 1;
		nums[numvec[0].second] = 1;
 for(int i = 1;i < numvec.size();i ++){
 if (numvec[i].first == numvec[i - 1].first) {
				now++;
				nums[numvec[i].second] = nums[numvec[i - 1].second];
 }
 else {
				now++;
				nums[numvec[i].second] = now;
 }
 }
 // for (int i = 1; i <= n;i++) {
 // 	cout << nums[i] << endl;
 // }
 
 for (int i = 1; i <= n; i++) {
			gett[nums[i]]++;
 }
 
 for (int i = 1; i <= n; i++) {
 for (int j = gett[nums[i]] - 1; j >= 0; j--) {
				dp[j + nums[i]] = dp[j + nums[i] - 1] + 1;
 }
 }
 
 int maxx = dp[1];
 for (int i = 1; i <= n; i++) {
			maxx = max(maxx, dp[i]);
 }
		cout << n - maxx << "\n";
 }
 return 0;
}
