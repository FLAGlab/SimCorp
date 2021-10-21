#include<bits/stdc++.h>
using namespace std;
int moves(vector <int> a)
 {
 int n=a.size();
 vector<int> b;
   b=a;
   sort(b.begin(),b.end());
 for(int  i=0;i<n;i++)
 {
 int num=a[i];
 int idx=lower_bound(b.begin(),b.end(),num)-b.begin();
      a[i]=idx;
 }
 int count=0;
 int cur=0;
 int tc=0;
 for(int i=0;i<=n-1;i++)
 {
        tc=0;
        cur=i;
 for(int j=0;j<n;j++)
 {
 if(a[j]==cur)
 {
            cur++;
            tc++;
 }
 }
      count=max(count,tc);
 }
 return n-count;
 
}
int main()
{
 int t;
	cin>>t;
 while(t--)
 {
 int n;
		cin>>n;
 vector<int> a(n);
 for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<moves(a)<<endl;
 }
 return 0;
}
