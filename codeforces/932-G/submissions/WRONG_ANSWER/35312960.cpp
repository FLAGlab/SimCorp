#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long int
#define show(a) cerr<<#a<<" = "<<a<<endl;
#define sshow(a, b) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<endl;
#define pi 3.1415926536
const ll INF=1e18;
const int inf=1e9;
const ll mod=1e9+7;
const ll N=1e6+1;
using namespace std;
ll count=0;
ll lps[N];
ll* c_lps(string s)
{ int n=s.length(),i=1,len=0;
 while(i<n)
 { if(s[i]==s[len])
 { len++;
      lps[i]=len;
      i++;
 }
 else
 { if(len!=0)
        len=lps[len-1];
 else
 { lps[i]=0;
        i++;
 }
 }
 }
 return lps;
}
void calculate(string s)
{ if(s.length()==0)
 { ::count++;
 ::count%=mod;
 return ;
 }
  string temp;
  ll* lps,len,n;
  lps=c_lps(s);
  n=s.length();
  len=lps[n-1];
 while(len!=0)
 { if((n-2)*len==0)
      temp="";
 else
      temp=s.substr(len,n-2*len);
 //sshow(len,temp);
    calculate(temp);
    len=lps[len-1];
 }
 return ;
}
 
int main()
{ string s;
  cin>>s;
  calculate(s);
  cout<<::count;
}
