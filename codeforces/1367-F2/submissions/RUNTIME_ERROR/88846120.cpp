#include <bits/stdc++.h>
using namespace std;
class fu{
 public:
 int key;
 int ind;
};
class ful{
 public:
 int key;
 int start;
 int end;
 vector<int> num;
};
bool compfu(fu a, fu b){
 return a.key<b.key;
}
int main() {
 int t;
	cin>>t;
 while(t--){
 int n,i,max=1,count;
	    cin>>n;
 int arror[n];
		fu arr[n];
 for(i=0;i<n;i++)
 {
			cin>>arror[i];
			arr[i].key=arror[i];
			arr[i].ind=i;
 }
		sort(arr,arr+n,compfu);
 vector<ful> diff;
		diff.push_back({arr[0].key,arr[0].ind,arr[0].ind,{arr[0].ind}});
 for(i=1;i<n;i++)
 {
 if(arr[i-1].key!=arr[i].key)
			diff.push_back({arr[i].key,arr[i].ind,arr[i].ind,{arr[i].ind}});
 else{
 (diff[diff.size()-1].num).push_back(arr[i].ind);
 if(arr[i].ind>diff[diff.size()-1].end)
				diff[diff.size()-1].end=arr[i].ind;
 else if(arr[i].ind<diff[diff.size()-1].start)
				diff[diff.size()-1].start=arr[i].ind;
 }
 }
 for(i=0;i<diff.size();i++)
		sort((diff[i].num).begin(),(diff[i].num).end());
 /*for(i=0;i<diff.size();i++)
		{
			cout<<diff[i].key<<" "<<diff[i].start<<" "<<diff[i].end<<endl;
			for(int j=0;j<(diff[i].num).size();j++)
			cout<<(diff[i].num)[j]<<" ";
			cout<<endl;
		}*/
 for(i=0;i<diff.size();i++)
 {
 int count=(diff[i].num).size();
 if(i>0)
 {
 for(int j=0;j<(diff[i-1].num).size();j++)
 {
 if((diff[i-1].num)[j]<diff[i].start)
					count++;
 else break;
 }
 }
 while(i+1<n&&diff[i+1].start>diff[i].end){
 //cout<<diff[i].key<<" "<<diff[i+1].key<<endl;
				count+=(diff[i+1].num).size();
				i++;
 //cout<<count<<endl;
 }
 if(i<diff.size()-1){
 for(int j=(diff[i-1].num).size()-1;j>-1;j--)
 if((diff[i-1].num)[j]>diff[i].end)
					count++;
 else break;
 }
 if(max<count)
				max=count;
 
 }
		cout<<n-max<<endl;
 }
}
