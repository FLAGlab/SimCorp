#include<bits/stdc++.h>
 
using namespace std;;
 
int ar[1000009];
int l[1000009];
int r[1000009];
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 int n,a,mx,mxi;
	mx = 0;
	cin >> n;
 for (int i = 0; i < n; i++){
		cin >> a;
 if (!ar[a])
			l[a] = i;
		ar[a]++;
		r[a] = i;
 if (ar[a] > mx || (ar[a] == mx && r[a]-l[a] < r[mxi]-l[mxi])){
			mx = ar[a];
			mxi = a;
 }
 }
	cout << l[mxi]+1 << ' ' << r[mxi]+1 << '\n';
	cout.flush();
}
