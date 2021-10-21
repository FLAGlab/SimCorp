#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string a,b;
	cin>>a;
	b=a[0];
 for(int i=1;i<a.size();i+=2)
 {
		b+=a[i];
 }
	cout<<b;
}
int main()
{
 long long int cse;
	cin>>cse;
 while(cse--)
 {
		solve();
		cout<<"\n";
 }
}
