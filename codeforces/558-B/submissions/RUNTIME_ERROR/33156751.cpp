#include<bits/stdc++.h>
 
using namespace std;
int n ;
long int a[100100] ;
int cnt[100100] ;
signed main()
{
 int maxoccurence=0 ;
    cin>>n ;
 int l=0,r=n ;
 for(int i=0 ; i<n ; i++)
 {
        cin>>a[i] ;
        cnt[a[i]]++ ;
 if(cnt[a[i]]>cnt[maxoccurence])
            maxoccurence=a[i] ;
 if(a[i]==maxoccurence)
            r=i ;
 }
 for(int i=0 ; i<n ; i++)
 {
 if(a[i]==maxoccurence)
 {
            l=i ;
 break ;
 }
 }
    cout<<l+1<<" "<<r+1<<endl ;
}
