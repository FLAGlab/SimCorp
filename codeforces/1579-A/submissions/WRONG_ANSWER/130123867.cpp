#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
	cin>>t;
 while(t--)
 {
 int n,lastd=0,rem;
		cin>>n;
		lastd=n%10;
 while(n>0)
 {
			rem=n%10;
			n/=10;
 }
		cout<<lastd+rem<<endl;
 }
 return 0;
 
}
