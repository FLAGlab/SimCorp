#include <stdio.h>
 
void solve(){
 char s[15];
    scanf("%s", s);
 int a = 0;
 int b = 0;
 int c = 0;
 for (int i=0; i<s[i];i++){
 if(s[i]=='A'){
            a++;
 }
 else if(s[i]=='B'){
            b++;
 }else {
            c++;
 }
 }
 
 int d = a + c;
 
 if(d==b){
        printf("YES\n");
 }else{
        printf("NO\n");
 }
 return;
}
 
 
int main(){
 int tc;
    scanf("%d", &tc);
 for(int i = 0; i < tc; i++){
        solve();
 }
 return 0;
}
