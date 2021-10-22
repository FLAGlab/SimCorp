#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code()
{
    fast_io;
 #ifndef READ_WRITE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 #endif 
}
 
signed main() 
{
   init_code();
 int t = 0;
   cin >> t;
 while(t--)
 {
        string s;
        cin >> s;
 
 int a = 0;
 int b = 0;
 int c = 0;
 
 for(int i = 0; i < s.size(); i++)
 {
 if(s[i] == 'A') a++;
 else if(s[i] == 'B')b++;
 else c++; 
 }
 
 if(b == a + c) cout << "YES\n";
 else cout << "NO\n";
 }
 return 0;
}
