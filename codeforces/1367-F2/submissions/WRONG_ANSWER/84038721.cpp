#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include<bits/stdc++.h>
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);
#define ll long long
using namespace std;
int main(){
 #ifndef ONLINE_JUDGE
    freopen(“input.txt”, “r”, stdin);
    freopen(“output.txt”, “w”, stdout);
    freopen(“error.txt”, “w”, stderr);
 #endif
    _cin;
    ll t,n;
    cin>>t;
 while(t--){
        cin>>n;
        pair<int, int> arr[n];
 for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second = i;
 }
        sort(arr, arr + n);
 int cnt = 1, max = 1;
 // for(int i=0;i<n;i++){
 //     cout<<arr[i].first<<” “<<arr[i].second<<endl;
 // }
 for(int i=0;i<n-1;i++){
 if(arr[i].second - arr[i+1].second < 0)cnt++;
 else{
 if(max <= cnt)max = cnt;
                cnt = 1;
 }
 }
 if(max <= cnt)max = cnt;
        cout<<n - max<<endl;
 }
}
 
