#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll n,s[100001],pok[100001];
 
signed main()
{
 /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    memset(pok,0,sizeof(pok));
    cin>>n;
    ll maxi=0, q;
 for (ll i=1; i<=n; ++i)
 {
        cin>>s[i];
        pok[s[i]]++;
 if (pok[s[i]]>maxi){
            maxi=pok[s[i]];
            q=s[i];}
 }
    ll l=1, r=n;
 while(true)
 {
 while(s[r]!=q)
            r--;
 while(s[l]!=q)
            l++;
 break;
 }
    cout<<l<<" "<<r;
 
 return 0;
}
