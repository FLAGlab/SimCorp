#include<bits/stdc++.h>
 
using namespace std;
 
signed main()
{
 int x[10001]={0};
 
 int n ;
    cin>>n;
 int arr[n];
 for(int i=0 ;i<n ;i++)
 {
        cin>>arr[i];
        x[arr[i]]++;
 }
 
 
 int mx=0;
 
 for(int i=0 ;i<10001 ;i++)
 {
 if(x[i]>0&& x[i]>=mx)
 {
            mx=i-1;
 }
 
 }
 int index;
 for(int i=0 ;i<n ;i++)
 {
 if(arr[i]==mx){
            cout<<arr[i]<<" ";
            index=i+1;
 break;
 }
 }
 int j=-1 ;
 for(int i=index ;i<n ;i++)
 {
 if(arr[i]==mx)
 {
            j=i+1;
 }
 }
 
    cout<<j<<endl;
 
 //cout<<mx<<endl;
 
 return 0;
}
