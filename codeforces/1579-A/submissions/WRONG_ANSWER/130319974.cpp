#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t; cin>>t;
 while(t--)
 {
		string str;
		cin>>str;
 int na=0;
 int nb=0;
 int nc=0;
		na=count(str.begin(),str.end(),'A');
		nb=count(str.begin(),str.end(),'B');
		nc=count(str.begin(),str.end(),'C');
 if(((na+nc)-nc)==0)cout<<"YES";
 else cout<<"NO";
 }
 return 0;
}
