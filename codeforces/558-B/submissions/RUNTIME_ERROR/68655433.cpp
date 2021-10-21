#include <bits/stdc++.h>
 
 using namespace std;
 
int n, x[100007],p[1000007],b=0,e=1000002,m=0,c;
 
int
main () 
{cin >> n;
for(int i=1;i<=n;i++){cin>>c;
 if(p[c]==0){p[c]=i;}
x[c]++;
if(x[c]>m||x[c]==m&&i-p[c]<e-b){m=x[c];b=p[c];e=i;}
}
 
cout<<b<<" "<<e;
}
