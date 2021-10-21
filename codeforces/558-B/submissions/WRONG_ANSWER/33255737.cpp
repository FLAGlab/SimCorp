#include <iostream>
using namespace std;
 
int am[1000001], l[1000001], r[1000001];
 
int main(){
 int n, i, aux, m = 0, res = 10000000, left = -1, right = -1;
  cin >> n;
 for(i = 0; i < n; i++){
    cin >> aux;
 if(!am[aux]){
      l[aux] = i;
 }
 else{
      r[aux] = i;
 }
    am[aux]++;
    m = max(am[aux], m);
 }
 for(i = 1; i <= 1000000; i++){
 if(am[i] == m && res > r[i]-l[i]+1){
      res = r[i]-l[i]+1;
      left = l[i]+1;
      right = r[i]+1;
 }
 }
  cout << left << " " << right << endl;
}
