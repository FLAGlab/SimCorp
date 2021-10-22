#include<bits/stdc++.h>
 
using namespace std;
 
int arr[1000009];
signed main() {
 int n,a;
    cin>>n;
 map<int,pair<int,int>>mp;//(cnt,(start,end))
 int mx=0,num=0;
 for (int i = 0; i <n ; ++i) {
        cin>>a;
 if(arr[a]==0){
            mp[a]={i+1,i+1};
            arr[a]++;
 }else{
            mp[a].second=i+1;
            arr[a]++;
 }
 if(arr[a]>mx){num=a;mx=arr[a];}
 }
 
    cout<<mp[num].first<<' '<<mp[num].second;
}
