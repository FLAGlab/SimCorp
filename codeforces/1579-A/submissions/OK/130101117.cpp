#include<iostream>
#include<cstring>
using namespace std;
char c[100];
int main(){
 int t;
	cin>>t;
 while(t--){
		cin>>c;
 int a=0,b=0;
 for(int i=0;i<strlen(c);i++){
 if(c[i]=='B') a++;
 else b++;
 }
 if(a==b) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
}
