#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000000;
int N, i, j, k, A[1005], T;
long long DP[10005], C[1005], W, B, X, P;
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>W>>B>>X;
 for (i=0;i<N;i++) {
		cin>>A[i];
 }
 for (i=0;i<N;i++) {
		cin>>C[i];
 }
	DP[0]=W;
 for (i=0;i<N;i++) {
 for (j=T;j>=0;j--) {
			P=DP[j];
 for (k=1;k<=A[i];k++) {
				P-=C[i];
 if (P<0) {
 break;
 }
				DP[j+k]=max(DP[j+k],P);
				T=max(T,j+k);
 }
 }
 for (j=1;j<=T;j++) {
			DP[j]=min(DP[j]+X,W+B*j);
 }
 }
	cout<<T<<'\n';
 return 0;
}
