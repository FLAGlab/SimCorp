#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int judge(string s){
 int a=0,b=0,c=0;
 for (int i=0;s[i]!='\0';i++){
 if (s[i]=='A'){
			a++;
 }else if (s[i]=='B'){
			b++;
 }else{
			c++;
 }
 }
 if (b%(a+c)==0 && b!=0){
 return 1;
 }else {
 return 0;
 }
}
 
int main(){
 int n;
	string s;
	cin>>n;
 for (int i=1;i<=n;i++){
		cin>>s;
 if (judge(s)){
			cout<<"Yes\n"; 
 }else {
			cout<<"No\n";
 }
 }
 return 0; 
} 
