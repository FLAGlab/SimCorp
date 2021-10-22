#include<bits/stdc++.h>
using namespace std;
signed main(){
 long long a=0,b=0,n,m,i,j,k,l,o,cnt=0;
    string s;
 for(i=0; i<n; i++){
    	cin>>s;
 for(int j=0; j<s.size(); j++){
 if(s[j]=='B')
    		a++;
 else
    		b++;
 }
 if(a==b)
		cout<<"YES"<<endl;
 else
		cout<<"NO"<<endl;
		a=0;
		b=0;
 }
}
