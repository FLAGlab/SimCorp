#include<bits/stdc++.h>
using namespace std;
 
int num[3];
 
int main(){
 //ios::sync_with_stdio(false);
 
 int t;
    string a;
    cin >> t;
 while(t--){
        cin >> a;
 if(a.length()%2)cout<<"NO\n";
 else{
            num[0] = num[1] = num[2] = 0;
 for(int i = 0; i < a.length(); i++){
                num[a[i]-'A']++;
 }
 if(num[1] == a.length() / 2) cout << "YES\n";
 else cout << "NO\n";
 }
 }
 
    system("pause");
 return 0;
}
