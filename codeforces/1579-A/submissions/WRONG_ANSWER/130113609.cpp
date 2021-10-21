#include <bits\stdc++.h>
 
using namespace std;
 
int main()
{
 int t;
	cin>>t;
 while(t--)
 {
		string s;
		cin>>s;
 int i=0,count=0;
 for(i=0;s[i]!='\0';i++)
 {
 if(s[i]=='B')
 {
				count++;
 }
 }
 if(count==((i/2)+(i%2)))
 {
			cout<<"YES"<<"\n";
 }
 else
 {
			cout<<"No"<<"\n";
 }
 }
}
