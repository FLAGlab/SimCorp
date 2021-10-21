#include<iostream>
using namespace std;
 
bool check(string l);
 
int main(){
 int n;
 cin>>n;
 int i;
 
string arr[n];
 
for(i=1;i<=n;i++){
    cin>>arr[i];
}
 
for(i=1;i<=n;i++){
 if(arr[i].length() %2==0){
 if(check(arr[i])==1){cout<<"YES"<<endl;}
 else{cout<<"NO"<<endl;}
 }
 else{
        cout<<"NO"<<endl;
 }
}
 
return 0;
}
 
 
bool check(string l){
 int a,b,c;
    a=0;b=0;c=0;
 for(int j=0;j<l.length();j++){
 if(l[j]='A'){a++;}
 else if(l[j]='B'){b++;}
 else if(l[j]='C'){c++;}
 }
 if(b=a+c){
 return 1;
 }
 else{
 return 0;
 }
}
