#include<iostream>
using namespace std;
int main(){
 int N;
	cin >> N;
	string s[N];
 for(int i=0;i<N;i++){
		cin >> s[i];
 int count = 0;
 for( int j=0; j<=(s[i].size()/2)-1;j++){
 if (s[i][j]!=s[i][s[i].size()-j-1]){
				count++;
 }
 }
		string c = count>1 ? "NO" : "YES";
		cout << c << endl;
 }
 return 0;
}
