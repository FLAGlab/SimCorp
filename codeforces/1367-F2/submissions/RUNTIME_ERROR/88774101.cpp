#include <bits/stdc++.h>
using namespace std;
 
int binS(int tar, vector<int> list) {
 int len=list.size();
 int l=0,r=len-1;
 while(l<r) {
 int mid=(l+r)/2;
 if((l+r)%2==1) mid++;
 if(list[mid]<tar) {
            l=mid;
 }
 else {
            r=mid-1;
 }
 }
 if(list[l]>=tar) return -1;
 else return l;
}
 
void solve() {
 int n;
    cin>>n;
 int arr[n];
 for(int i=0; i<n; i++) {
        cin>>arr[i];
 }
    pair<int,int> lmao[n];
 for(int i=0; i<n; i++) {
        lmao[i]={arr[i],i};
 }
    sort(lmao, lmao+n);
 int num=0;
 for(int i=0; i<n; i++) {
 if(i!=0 && lmao[i].first!=lmao[i-1].first) {
            num++;
 }
        arr[lmao[i].second]=num;
 }
    num++;
 int dp[n],maxi=0,dp2[n],dp3[n];//dp2[i]=ending at pos i without skipping, dp3[i]=ending at pos i
 vector<int> pos[num];
 for(int i=0; i<n; i++) {
        pos[arr[i]].push_back(i);
        dp[i]=pos[arr[i]].size();
 }
 for(int i=0; i<n; i++) {
        dp2[i]=1;
        dp3[i]=1;
 }
 for(int i=0; i<n; i++) {
 if(arr[i]==0) {
            dp2[i]=dp[i];
            dp3[i]=dp[i];
 }
 else {
 int prev=binS(i,pos[arr[i]-1]), cur=binS(i,pos[arr[i]]);
 if(prev!=pos[arr[i]-1].size()-1||cur!=-1) {
 if(cur==-1 && prev==-1) {
                    dp2[i]=1;
                    dp3[i]=1;
 }
 else if(cur==-1) {
                    dp2[i]=max(dp[i],dp[pos[arr[i]-1][prev]]+1);
                    dp3[i]=max(dp[i],dp[pos[arr[i]-1][prev]]+1);
 if(prev==pos[arr[i]-1].size()-1) {
                        dp3[i]=max(dp3[i], dp2[pos[arr[i]-1][prev]]+1);
 }
 }
 else if(prev==-1) {
                    dp2[i]=dp[i];
                    dp3[i]=dp3[pos[arr[i]][cur]]+1;
 }
 else {
                    dp2[i]=max(dp2[pos[arr[i]][cur]]+1,dp[pos[arr[i]-1][prev]]+1);
 if(prev==pos[arr[i]-1].size()-1) {
                        dp3[i]=max(dp2[pos[arr[i]-1][prev]]+1,dp3[pos[arr[i]][cur]]+1);
 }
 else {
                        dp3[i]=dp3[pos[arr[i]][cur]]+1;
 }
 }
 }
 else {
                dp2[i]=dp2[pos[arr[i]-1][prev]]+1;
                dp3[i]=dp2[pos[arr[i]-1][prev]]+1;
 }
 }
 if(maxi<dp3[i]) maxi=dp3[i];
 if(dp2[i]>dp3[i]) maxi=1/0;
 }
 // for(int i=0; i<n; i++) {
 //     cout << arr[i] << ' ';
 // }
 // cout << endl;
 // for(int i=0; i<n; i++) {
 //     cout << dp[i] << ' ';
 // }
 // cout << endl;
 // for(int i=0; i<n; i++) {
 //     cout << dp2[i] << ' ';
 // }
 // cout << endl;
 // for(int i=0; i<n; i++) {
 //     cout << dp3[i] << ' ';
 // }
 // cout << endl;
    cout << n-maxi << endl;
}
 
int main() {
 int t;
    cin>>t;
 while(t--) solve();
}
/*
10 9 1 7 0 8 0 7 3 6 2 5 4 5 11 6 7 12 0 6 
1  1 1 1 1 2 2 2 1 1 2 1 2 3 2  4 5 3  3 5 
 
10 9 1 7 0 8 0 7 3 6 2 5 4 5 11 6 7 12 0 6
1  1 1 1 1 1 2 2 1 1 2 1 2 2 2  2 3 3  3 3 
1  1 1 1 1 2 2 2 1 1 2 1 2 3 2  3 3 3  3 3 
Y  Y Y Y Y Y W Y Y Y Y Y Y Y 
 
 
*/
