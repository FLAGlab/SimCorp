 
#include <bits/stdc++.h> 
#define MAX 3001 
using namespace std; 
int dp[MAX][MAX];
int mss(int x[], int y[], int n, int m) 
{ 
 for (int i = 0; i <= m; i++) 
 for (int j = 0; j <= n; j++) 
			dp[i][j] = 0; 
 for (int i = 1; i <= m; i++) { 
 for (int j = 1; j <= n; j++) { 
 if (x[j - 1] == y[i - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1]; 
 else
				dp[i][j] = dp[i][j - 1]; 
 } 
 } 
 int ans = 0; 
 for (int i = 1; i <= m; i++) 
		ans = max(ans, dp[i][n]); 
 
 return ans; 
} 
int main() 
{ 
 int t;
	cin>>t;
 while(t--){
 int n;
		cin>>n;
 int x[n],y[n];
 for(int i=0;i<n;i++){
			cin>>x[i];
			y[i]=x[i];
 }
		sort(y,y+n);
		cout <<n- mss(x, y, n, n)<<endl; 
 }
 return 0; 
} 
