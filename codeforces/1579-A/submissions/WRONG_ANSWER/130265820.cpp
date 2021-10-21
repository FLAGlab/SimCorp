#include<iostream>
using namespace std;
int main(){
 int t;
	cin>>t;
 while(t--){
		string s;
		cin>>s;
 int ctr = 0;
 for(int i=0;i<s.size();i++){
 if(s[i]=='b'){
				ctr++;
 }
 }
 if(ctr == s.size() - ctr){
			cout<<"YES"<<endl;
 }
 else{
			cout<<"NO"<<endl;
 }
 }
 return 0;
}
