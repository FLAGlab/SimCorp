#include<bits/stdc++.h>
using namespace std;
 
signed main() {
 int n,max = -1, ind;
	cin>>n;
 int a[n], hash[1000001]={0},st[1000001]={0},fin[1000001]={0};
 for (int i=0;i<n;i++){
		cin>>a[i];
		hash[a[i]]++;
 if(st[a[i]]==0)
			st[a[i]] = i+1;
		fin[a[i]] = i+1;
 }
 for (int i=1;i<1000001;i++){
 if (max<hash[i]){
			ind = i;
			max = hash[i];
 }else if (max ==hash[i]){
 if (fin[i]-st[i]<fin[ind]-st[ind]){
				ind = i;
 }
 }
 }
	cout<<st[ind]<<" "<<fin[ind]<<"\n";
 return 0;
}
