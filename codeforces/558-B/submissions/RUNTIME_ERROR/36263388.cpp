#include <bits/stdc++.h>
#define piii pair< pair<int ,int>,int >
using namespace std;
 
int main()
{
 vector<piii> arr;
 int freq[100005] = { 0 };
 int n, num, first;
	cin >> n;
	arr.assign(n, { { 0,0 },0 });
 for (int i = 1; i <= n; ++i)
 {
		cin >> num;
 if (freq[num] == 0)
 {
			first = i;
 }
 else
 {
			first = arr[num].first.second;
 }
		freq[num]++;
		arr[num] = { { freq[num],first },i }; //count , first appearance , last apperance
 }
	sort(arr.begin(), arr.end(), greater<piii>());
	cout << arr[0].first.second << " " << arr[0].second;
}
