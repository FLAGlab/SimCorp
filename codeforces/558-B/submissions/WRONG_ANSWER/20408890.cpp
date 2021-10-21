#include<iostream>
using namespace std; 
int n, x, l[1000005], r[1000005], c[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
 for (int i = 0; i < n; ++i){
		cin >> x;
 if (c[x] == 0)l[x] = i + 1;
 else r[x] = i + 1;
 ++c[x];
 }
 int mx=-1, mxi;
 for (int i = 1; i <= 1000000; ++i){
 if (c[i]>mx){ mx = c[i]; mxi = i; }
 else if (c[i] == mx){
 if (r[i] - l[i]<r[mxi] - l[mxi]) mx = c[i]; mxi = i;
 }
 }
	cout << l[mxi] << " " << r[mxi] << endl;
 return 0;
}
