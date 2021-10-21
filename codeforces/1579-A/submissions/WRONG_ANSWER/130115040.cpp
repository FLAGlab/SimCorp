#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
int a1=0,a2=0,a3=0,i;
string b;
cin>>b;
for(i=0;i<b.length();i++){
 if(b[i]=='A')
    a1++;
 else if(b[i]=='B')
    a2++;
 else
    a3++;
}
if(a2==(a1+a3))
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
return 0;
}
