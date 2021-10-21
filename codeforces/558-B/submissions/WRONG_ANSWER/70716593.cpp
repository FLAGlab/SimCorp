#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
 long n,val,max1=0,index=0;
	cin>>n;
 long arr[n];
 map<long,long>m2,mp;
 for(long i=0;i<n;i++)
 {
	    cin>>arr[i];
 }
 for(long i=0;i<n;i++)
 {
 if(mp.find(arr[i])==mp.end())
 {
	        m2[arr[i]]=i+1;
 }
 
 
 
	    mp[arr[i]]++;
 if(mp[arr[i]]>max1)
 {
	        max1=mp[arr[i]];
	        index=i;
	        val=arr[i];
 }
 }
	cout<<m2[val]<<" "<<index+1<<endl;
 
 return 0;
}
