#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define owo long long
owo n,m,a[1000000];
map<int,int> t;
map<int,int> ss;
map<int,int> s3;
 
owo q,g,x,z;
int main(){
    cin>>n;
 for(int i=1; i<=n; i++){ cin>>a[i];
 if(t[a[i]]==0){ ss[a[i]]=i;}
        t[a[i]]++; 
 if(t[a[i]]>q){ q=t[a[i]]; g=a[i];}
 if(a[i]==g){ x=i;}
 }
 
    cout<< ss[g] <<" "<< x;
 
 
}
