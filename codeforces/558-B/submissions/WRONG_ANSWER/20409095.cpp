#include<iostream>
using namespace std; 
long long n, x, l[1000005], c[1000005], mx, mxi,mni;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n; mx = -1;
 for (long long i = 0; i < n; ++i){
		cin >> x;
 if (c[x] == 0){
			l[x] = i + 1; c[x] = 1;
 }
 else ++c[x];
 if (c[x] > mx){
			mx = c[x]; mxi = i + 1; mni = l[x];
 }
 else if (c[x] == mx){
 if (i+1 - l[x] < mxi - l[mni]){
				mx = c[x]; mxi = i + 1; mni = l[x];
 }
 }
 }
	cout << mni << " " << mxi << endl;
 return 0;
}
