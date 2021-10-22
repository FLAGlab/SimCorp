#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,k,i,l,o,j,nt;
string s;
 
signed main()
{
    cin >>nt;
 for (j=1;j<nt;j++) {
cin>>s;
n=s.size();
b=0;
for (i=0;i<n;i++) {
if (s[i]=='B') b++;
}
if (n%2!=0) cout<<"NO"<<endl;
else {
 if (b==n/2)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}
}
 return 0;
}
