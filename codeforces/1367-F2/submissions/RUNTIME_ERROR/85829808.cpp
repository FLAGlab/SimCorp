#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define LT "A"
#define endl "\n"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define maxn 200005
 
int i , j , n , m , k;
int a[maxn] , b[maxn] , nb = 0 ;
int d[maxn] , f[maxn] , g[maxn];
int x[maxn] , y[maxn];
vector <int> ke[maxn];
 
void nhap()
{
    cin >> n; For( i , 1 , n ) cin >> a[i];
}
 
void nen()
{
 For( i , 1 , n ) b[i] = a[i];  sort( b+1 , b+n+1 );
    nb = 0;
 For( i , 1 , n )
 {
 while( b[i] == b[i+1] && i < n ) i++;
        b[++nb] = b[i];
 }
}
 
int chat( int s )
{
 int l = 1 , r = nb;
 while( l <= r )
 {
 int mid = (l+r) >> 1;
 if( b[mid] <= s ) l = mid + 1;
 else r = mid - 1;
 }
 return l - 1;
}
 
void process()
{
 For( i , 1 , n )
 {
        ke[i].clear();
        d[i] = 0; f[i] = 0; g[i] = 0;
        x[i] = -1; y[i] = 1e8;
 }
}
 
int bs1( int s, int vt )
{
 int l = 0 , r = ke[s].size()-1;
 while( l <= r )
 {
 int mid = (l+r) >> 1;
 if( ke[s][mid] >= vt ) r = mid - 1;
 else l = mid + 1;
 }
 return r + 1;
}
 
void xuli()
{
    process();
    nen();
 For( i , 1 , n ) a[i] = chat(a[i]);
 For( i , 1 , n ) ke[a[i]].pb(i);
 
 int ans = 0;
 
 For( i , 1 , n )
 {
 int tam = a[i]; d[tam]++;
 if( x[tam-1] == -1 ) x[tam-1] = d[tam-1];
 if( d[tam] == ke[tam].size() ) y[tam+1] = d[tam+1];
 }
 For( i , 1 , n ) d[i] = 0;
 
 For( i , 1 , n )
 {
 int tam = a[i]; d[tam]++;
 
        g[tam] = max( d[tam-1] , g[tam] ) + 1;
        ans = max( ans , g[tam] );
 
 if( g[tam] == d[tam] + d[tam-1] ) f[tam] = max ( f[tam] , f[tam-1] + d[tam] );
 else f[tam] = max( f[tam] , d[tam] + x[tam-1] );
        ans = max ( ans , f[tam] );
 
 int tam1 = bs1( tam , ke[tam-1][ ke[tam-1].size()-1 ]+1 );
        ans = max ( ans , f[tam-1] + d[tam] - tam1 );
 }
    cout << n - ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
 int t; cin >> t;
 while( t-- )
 {
        nhap();
        xuli();
 }
}
 
 
