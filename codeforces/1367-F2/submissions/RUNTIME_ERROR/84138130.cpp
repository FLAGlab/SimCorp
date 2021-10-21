#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
typedef long long int ll;
int binsearch(vector<ll> &v,int low,int high,ll key){
 if(low<=high){
 int mid=low+high;
        mid/=2;
 if(v[mid]==key){
 return mid;
 }
 else if(v[mid]>key){
 return binsearch(v,low,mid-1,key);
 }
 else{
 return binsearch(v,mid+1,high,key);
 }
 }
 return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 int T;
    cin>>T;
 while(T--){
 int n;
        cin>>n;
 vector<ll> a(n),b,c,arr(n);
 for(int i=0;i<n;i++){
            cin>>a[i];
 }
        b=a;
        sort(b.begin(),b.end());
 for(int i=0;i<b.size();i++){
 int j=i;
 while(j<b.size()&&b[j]==b[i]){
                j++;
 }
            c.push_back(b[i]);
            i=j-1;
 }
 vector<ll> d(c.size()),e(c.size(),0),start(c.size(),-1),last(c.size(),-1),dp(n,-1),cnt(c.size(),0),f(c.size(),0);
 for(int i=0;i<d.size();i++){
            d[i]=i;
 }
 for(int i=0;i<n;i++){
 int j=binsearch(c,0,c.size()-1,a[i]);
            arr[i]=d[j];
            f[arr[i]]++;
 }
        ll mx=0;
 for(int i=0;i<n;i++){
 if(start[arr[i]]==-1){
                start[arr[i]]=i;
 }
 if(last[arr[i]]==-1){
 if(arr[i]==0){
                    dp[i]=1LL;
 }
 else{
                    dp[i]=max(1LL,cnt[arr[i]-1]+1);
 }
 }
 else{
 if(arr[i]==0){
                    dp[i]=dp[last[arr[i]]]+1;
 }
 else{
                    dp[i]=max(dp[last[arr[i]]]+1,cnt[arr[i]-1]+1);
 }
 }
 if(cnt[arr[i]-1]==f[arr[i]-1]&&start[arr[i]-1]!=-1){
                dp[i]=max(dp[i],f[arr[i]-1]+dp[start[arr[i]-1]]);
 }
            mx=max(mx,dp[i]);
            last[arr[i]]=i;
            cnt[arr[i]]++;
 }
        cout<<n-mx<<endl;
 }
}
 
 
 
