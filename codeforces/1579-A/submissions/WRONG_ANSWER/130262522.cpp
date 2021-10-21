#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
 int t;
	cin>>t;
 while(t--)
 {
		string s;
		cin>>s;
 int _=0;
 for(int i=0;i<s.size();i++)
 {
 if(s[i]=='B') _++;
 }
 if(_==(s.size()+1)/2) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
}
