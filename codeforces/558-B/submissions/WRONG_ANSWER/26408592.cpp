#include<bits/stdc++.h>
 
using namespace std;
 
int mp[1000005];
int ar[100005];
 
signed main()
{
 int n, i, ans, l, r, mx=0;
    cin >> n;
 for(i=1; i<=n; i++)
 {
        cin >> ar[i];
        mp[ar[i]]++;
 if(mp[ar[i]] > mx)
 {
            mx = mp[ar[i]];
            ans = ar[i];
 }
 }
 
 for(l=1; l<=n; l++)
 if(ar[l]==ans)
 break;
 
 for(r=n; r>=1; r--)
 if(ar[r]==ans)
 break;
 
    cout << l << " " << r << endl;
}
 
