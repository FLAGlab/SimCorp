#include<iostream>
using namespace std;
#include<string>
int main()
{
 int n=0;
    cin>>n;
    string arr[n];
 for(int i=0;i<n;i++)
 {
        cin>>arr[i];
 }
 for(string j:arr)
 {
        cout<<j<<endl;
 }
}
