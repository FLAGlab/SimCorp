#include<bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
map<int, int>m;
 
signed main(){
 int n, i, x, mx=-1;
    cin>>n;
 for(i=1;i<=n;i++){
        cin>>x;
 if(m[x]==0){ m[x]++; a[x]=i; b[x]=i;}
 else{ m[x]++; b[x]=i;}
 }
 
 vector<int>v;
 for(auto i=m.begin(); i!=m.end(); i++){
 int a, b;
        a=i->second;
 if(a>mx){
            mx=a;
            b=i->first;
            v.clear();
            v.push_back(b);
 }
 else if(a==mx){b=i->first;  v.push_back(b);}
 }
 
 int mn=INT_MAX, mnx=-1;
 for(i=0;i<v.size();i++){
 int x=v[i];
 int dif=b[x]-a[x];
 if(mn>dif){
            mn=dif;
            mnx=x;
 }
 }
 
    cout<<a[mnx]<<' '<<b[mnx]<<endl;
}
