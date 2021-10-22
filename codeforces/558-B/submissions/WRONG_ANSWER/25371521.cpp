#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int sz=1000005;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
 
int arr[sz], b[sz], e[sz];
 
signed main()
{	boost
 int max = 0, el, n;
	cin >> n;
 for (int i = 0; i < n; i++)
 {
		cin >> el;
		arr[el] += 1;
 if (b[el] == 0) b[el] = i + 1;
		e[el] = i + 1;
 if (arr[el] > max) max = el;
 }
	cout << b[max] << " " << e[max];
}
