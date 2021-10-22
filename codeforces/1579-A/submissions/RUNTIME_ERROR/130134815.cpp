#include<bits/stdc++.h>
 
using namespace std;
 
std::string isCasimir(std::string);
 
int main(int argc, char* argv[]) {
	cout << argv[0];
 for (int i = 0; i < 6; i++) {
        cout << isCasimir((std::string)argv[i+1]) << endl;
 }
 return 0;
}
 
std::string isCasimir(std::string s) {
 int numAs = 0, numBs = 0, numCs = 0;
 //find number of A's
 for (char x : s) {
 if (x == 'A') {
    		numAs++;
 } else if (x == 'B') {
    		numBs++;
 } else if (x == 'C') {
    		numCs++;
 }
 }
 
 if (numAs + numCs == numBs) {
 return "YES";
 } else {
 return "NO";
 }
}
