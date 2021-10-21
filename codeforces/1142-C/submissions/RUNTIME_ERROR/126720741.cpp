#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
 
long long n, cur, ans;
 
struct point
{
 long long x, y;
}p[1000005];
 
deque<long long> dys;
 
double dis( long long x1, long long y1, long long x2, long long y2 )
{
 return sqrt( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
}
 
double getslope( long long x1, long long y1, long long x2, long long y2 )
{
 return ( y2 - y1 ) / ( x2 - x1 );
}
 
bool cmp( point a, point b )
{
 double anga = acos( a.x / dis( 0, 0, a.x, a.y ) );
 double angb = acos( b.x / dis( 0, 0, b.x, b.y ) );
 if( anga == angb )
 {
 return a.x < b.x;
 }
 return anga < angb;
}
 
int main()
{
    p[0].x = 2e9;
    p[0].y = 2e9;
    cin >> n;
 for( long long i = 1; i <= n; i++ )
 {
        cin >> p[i].x >> p[i].y;
 if( p[i].y < p[cur].y )
 {
            cur = i;
 }
 else if( p[i].y == p[cur].y )
 {
 if( p[i].x < p[cur].x )
 {
                cur = i;
 }
 }
 }
    swap( p[1], p[cur] );
 for( long long i = 2; i <= n; i++ )
 {
        p[i].x -= p[1].x;
        p[i].y -= p[1].y;
 }
    p[1].x = 0;
    p[1].y = 0;
    sort( p + 2, p + n + 1, cmp );
 // for( long long i = 1; i <= n; i++ )
 // {
 //     cout << p[i].x << " " << p[i].y << endl;
 // }
    dys.push_back( 1 );
 for( long long i = 2; i <= n; i++ )
 {
 while( dys.size() )
 {
 long long num = 114514;
 if( dys.size() > 1 )
 {
                num = ( p[dys[dys.size() - 2]].x - p[i].x ) * ( p[dys[dys.size() - 1]].y - p[i].y ) - ( p[dys[dys.size() - 2]].y - p[i].y ) * ( p[dys[dys.size() - 1]].x - p[i].x );
 }
 if( num >= 0 )
 {
                dys.push_back( i );
 break;
 }
 else
 {
                dys.pop_back();
 }
 }
 }
    dys.push_back( dys.front() );
 for( long long i = 0; i < dys.size(); i++ )
 {
 if( p[dys[i]].y + ( p[n].x - p[dys[i]].x ) * getslope( p[dys[i]].x, p[dys[i]].y, p[dys[i + 1]].x, p[dys[i + 1]].y ) >= p[n].y )
 {
            ans++;
 }
 }
    cout << ans;
 return 0;
}
 
