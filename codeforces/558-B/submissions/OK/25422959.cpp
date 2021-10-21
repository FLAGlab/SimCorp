#include<bits/stdc++.h>
using namespace std;
int N, M, i, j, A[1000000], L[1000000], X, Y, maks;
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N;
 for (i=1;i<=N;i++) {
		cin>>M;
		A[M]++;
 if (A[M]==1) {
			L[M]=i;
 }
 if (A[M]>maks) {
			maks=A[M];
			X=L[M];
			Y=i;
 }
 else if (A[M]==maks) {
 if (Y-X>i-L[M]) {
				X=L[M];
				Y=i;
 }
 }
 }
	cout<<X<<' '<<Y<<'\n';
}
