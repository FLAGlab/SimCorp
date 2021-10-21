#include<bits/stdc++.h>
 
using namespace std;
map<int,int>A;
int AA[1000000];
int main()
{
 int n,M=0,a,l,r;
 
	cin>>n;
 
 for(int i=0;i<n;i++)
 {
		cin>>a;
		A[a]++;
 
 if(A[a]==1)
			AA[a]=i+1;
 
 if(A[a]==M)
 {
 if(r-l>i-AA[a]+1)
			l=AA[a],r=i+1;
 }
 
 else if(M<A[a])
 {
			M=A[a];
			l=AA[a];
			r=i+1;
 }
 
 } 
 
	cout<<l<<" "<<r;
}
