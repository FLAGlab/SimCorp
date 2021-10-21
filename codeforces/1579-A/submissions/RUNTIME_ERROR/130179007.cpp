#include <iostream>
#include <string>
using namespace std;
 
string func(string l) {
 int len = l.length();
 int a = 0, b = 0, c = 0;
 for (int i = 0; i < len; i++) {
 if (l[i] == 'A') a++;
 else if (l[i] == 'B') b++;
 else c++;
 }
 if (a + c == b) return("YES");
 else return("NO");
}
 
 
int main()
{
    string line[500];
 int num;
    cin >> num;
 for (int i = 0; i < num; i++) {
        cin >> line[i];
        line[i] = func(line[i]);
 }
 
 for (int i = 0; i < num; i++) {
        cout << line[i] << endl;
 }
 
}
