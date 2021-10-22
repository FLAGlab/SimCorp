#include<bits/stdc++.h>
using namespace std;
#define owo long long
owo n,m,a[1000000];
map<owo,owo> t;
map<owo,owo> ss;
owo q,g,x,z;
signed main(){
    cin>>n;
 for(int i=1; i<=n; i++){ cin>>a[i];
 if(t[a[i]]==0){ ss[a[i]]=i;}
        t[a[i]]++; 
 if(t[a[i]]>q){ q=t[a[i]]; g=a[i];}
 if(a[i]==g){ x=i;}
 }
 
    cout<< ss[g] <<" "<< x;
 
 
}
