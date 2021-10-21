#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 int n ;
    cin>>n ;
 int arr[n] , freq[n] , MAX = 0 , ans;
    memset(freq , 0 , sizeof freq);
 for(int i = 0 ; i < n ; ++i)
 {
        cin>>arr[i] ;
        freq[arr[i]]++;
 if(freq[arr[i]] > MAX)
            ans = arr[i] , MAX = freq[arr[i]];
 }
 if(MAX == 1)
        cout<<"1 1";
 else
 {
 int st = -1 , en ;
 for(int i = 0 ; i < n ; ++i)
 {
 if(st == -1 && arr[i] == ans)
                st = i+1 ;
 if(arr[i] == ans)
                en = i+1 ;
 }
        cout<<st<<" "<<en;
 }
 return 0 ;
}
