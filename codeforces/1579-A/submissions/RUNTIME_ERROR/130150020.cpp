#include <bits/stdc++.h>
#include <iomanip>
#include <sstream>
#define  ei                          else if
#define  pi                          3.14159265358979323846D
#define  vi                          vector<int>
#define  gcd(x,y)                    __gcd(x,y)
#define  lcm(x,y) ((x*y)/__gcd(x,y))
#define  vll                         vector<ll>
#define  ll                          long long
#define  all(x)                      x.begin(),x.end()
#define  pb                          push_back
#define  yes                         cout << "YES" << endl
#define  no                          cout << "NO" << endl
#define  fori(i,l,n) for(i=l ; i<n ; i++)
#define  forj(j,l,n) for(j=l ; j<n ; j++)
 
using namespace std;
 
 
int main(){
    ll t, x, n, a, b,c,d,i,j; 
 
    cin >> t; 
    string s ;
 while(t--)
 {
        cin >> n ;
        ll arr[n];
 
 for(i=0; i<n; i++){
            cin >> arr[i];
 if(arr[i]==1)
                a=i;
 }
        vll v ;
 for(i=a-1; i>=0;i--){
            v.pb(arr[i]);
 }
 for(j=a+1; j<n; j++){
            v.pb(arr[j]);
 }
        cout << 1 ;
 for(i=0; i<n-1;i++){
            cout <<" "<< v[i];
 }
        cout << endl;
 
 }
 return 0;
}
