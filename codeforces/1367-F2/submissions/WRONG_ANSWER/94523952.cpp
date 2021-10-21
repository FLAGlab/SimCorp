#include <bits/stdc++.h>
 
#define lp(i,a,b) for(int i = a ; i < b ; i++)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pb push_back
#define ll long long 
#define mk make_pair
#define debug printf
#define sz(x) (int)(x.size())
 
using namespace std ;
 
int solve()
{
 int n ;
	scanf("%d", &n) ;
 
 vector<int> a(n) , compress(n) ;
 for(int i = 0 ; i < n ; i++ ) 
 {
		scanf("%d", &a[i] ) ;
		compress[i]=a[i] ;
 }
 
	sort(all(compress) ) ;
	compress.erase(unique(all(compress)), compress.end() ) ;
	lp(i,0,n) a[i] = lower_bound(all(compress) , a[i] ) - compress.begin() ;
 
 vector<int> loc(n+1,-1) ;
 vector<int> dp(n,1) ; //essa dp eh relacionada com os indices, nao com o valor
 
 for(int i = n-1 ; i >= 0 ; i-- )
 {
 if( loc[a[i]] != -1 ) dp[i] = 1 + dp[ loc[a[i]] ] ;
 if( loc[a[i]+1] != -1 ) dp[i] = max(dp[i], 1 + dp[loc[a[i]+1]] ) ;
		loc[ a[i] ] = i ; 
 }
 
 return n - *max_element(all(dp));
 
}
 
int main()
{
 int t ;
	scanf("%d", &t ) ;
 while(t--) printf("%d\n", solve() ) ;
}
