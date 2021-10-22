#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
	cin >> t;
 while(t--){
 int x = 0;
		string a;
		cin >> a;
 for(int i = 0;i < a.size();i++){
 if(a[i]=='B'){
				x++;
 }
 }
 if(x*2==a.size()){
			cout << "YES"<<endl;
 }else{
			cout << "NO"<<endl;
 }
 }
}
