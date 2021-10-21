#include <bits/stdc++.h>
 
const int N = 2e5 + 7;
 
int a[ N ], b[ N ], l[ N ], r[ N ], dp[ N ][ 3 ], pos[ N ], num[ N ];
int n, _;
 
int main( ) {
	std::cin >> _;
 while ( _ --> 0 ) {
		std::cin >> n;
		memset( dp, 0, sizeof dp );
		memset( l, 0, sizeof l );
		memset( r, 0, sizeof r );
		memset( num, 0, sizeof num );
 for ( int i = 1; i <= n; ++ i ) {
			std::cin >> a[ i ];
			b[ i ] = a[ i ];
 }
		std::sort( b + 1, b + 1 + n );
 int tot = std::unique( b + 1, b + 1 + n ) - b - 1;
 for ( int i = 1; i <= n; ++ i ) {
			a[ i ] = std::lower_bound( b + 1, b + 1 + tot, a[ i ] ) - b;
			r[ a[ i ] ] = i;
 if ( !l[ a[ i ] ] ) l[ a[ i ] ] = i, pos[ a[ i ] ] = i;
 ++ num[ a[ i ] ];
 }
 int max = 1;
 for ( int i = 1; i <= n; ++ i ) {
			dp[ i ][ 0 ] = dp[ pos[ a[ i ] ] ][ 0 ] + 1;
      	    dp[ i ][ 1 ] = std::max( dp[ pos[ a[ i ] ] ][ 1 ] + 1, std::max( dp[ pos[ a[i] - 1 ] ][ 0 ] + 1, 
			  dp[ pos[ a[ i ] - 1 ] ][ 2 ] + 1 ) );
 if ( i == r[ a[ i ] ] )
            	dp[ i ][ 2 ] = dp[ l[ a[ i ] ] ][ 1 ] + num[ a[ i ] ] - 1;
       			pos[ a[ i ] ] = i;
 for ( int j = 0; j < 3; ++ j ) max = std::max( max, dp[ i ][ j ] );
 }
		std::cout << n - max << '\n';
 }
}
