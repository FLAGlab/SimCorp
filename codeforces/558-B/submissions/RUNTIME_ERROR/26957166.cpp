#include<bits/stdc++.h>
using namespace std;
 
int n, m, k, i, l, o, x, y,ans, mx;
int a[100000+10];
struct my
{
 int l;
 int r;
};
my b[100000+10];
signed main()
{
    cin>>n;
 map<int, int> mp;
 for (i=1;i<=n;i++)
 {
        cin>>a[i];
 if (mp[a[i]]==0) {b[a[i]].l=i;}
        b[a[i]].r=i;
        mp[a[i]]++;
        mx=max(mx, mp[a[i]]);
 }
    ans=INT_MAX;
 for (i=1;i<=n;i++)
 if (mp[a[i]]==mx)
 {
 if (ans>b[a[i]].r-b[a[i]].l+1)
 {
            ans=b[a[i]].r-b[a[i]].l+1;
            x=b[a[i]].l;
            y=b[a[i]].r;
 }
 
 }
    cout<<x<<" "<<y;
 
}
