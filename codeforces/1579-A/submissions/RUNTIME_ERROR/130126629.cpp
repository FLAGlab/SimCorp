 #include <iostream>
 using namespace std;
 
 int main() {
 int t;
    	cin>>t;
 while(t--){
 char s[50];
    		cin>>s;
 int a[3]={0};
 for(int i=0;s[i]!='\0';i++)
    		a[s[i]-'A']++;
 if(a[1]==a[0]+a[2])
    		cout<<"YES\n";
 else
    		cout<<"NO\n";
 }
 return 0;
 }
