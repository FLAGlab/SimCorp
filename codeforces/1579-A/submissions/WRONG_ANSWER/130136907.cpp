#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
 int t;
	cin>>t;
 while(t--)
 {
 char a[55];
 int A=0,B=0,C=0,flag=0;
		cin>>a;
 for(int i=0;i<strlen(a);i++)
 {
 if(a[i]=='A')
			A++;
 if(a[i]=='B')
			B++;
 if(a[i]=='C')
			C++;
 }
 if(A+C==B&&(A>1||C>1))
		cout<<"YES"<<endl;
 else
		cout<<"NO"<<endl;
 }
 return 0;
}
