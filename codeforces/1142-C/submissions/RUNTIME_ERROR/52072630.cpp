#include <bits/stdc++.h>
 
using namespace std;
 
inline void initialize() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
double epsilon = 0.00000000;
 
struct Coord{
 long long x;
 long long y;
 
 Coord (void){
 };
 
 Coord (double x, double y){
 this->x = x;
 this->y = y;
 }
 
 bool operator<(Coord B){
 if (y < B.y)
 return true;
 if (x < B.x and y == B.y)
 return true;
 return false;
 }
 
 bool operator>=(Coord B){
 return !(*this<B);
 }
 
};
 
vector <Coord> points;
 
long long aria(Coord A, Coord B, Coord C){
 return A.x*B.y + B.x*C.y + C.x*A.y - C.x*B.y - B.x*A.y - A.x*C.y;
}
 
bool compareTwo(Coord A, Coord B, Coord C = points[0]){
 return (A.x*B.y + B.x*C.y + C.x*A.y) > (C.x*B.y - B.x*A.y - A.x*C.y);
}
 
bool compare(Coord A, Coord B, Coord C = points[0]){
 long long delta = aria(A, B, C);
 if (delta > epsilon)
 return true;
 if (delta < -epsilon)
 return false;
 return false;
}
 
bool trigger(Coord A, Coord B){
 return compare(A, B);
}
 
unordered_set <int> myHash;
 
unordered_map <int, int> yConfig;
 
const int N = 1e5+5;
 
Coord myStack[N];
 
int main(){
 int n;
    cin >> n;
 for (int i = 0 ; i < n; i++){
 int x, y;
        cin >> x >> y;
 
 if (myHash.find(x) == myHash.end()){
            yConfig[x] = y;
            myHash.insert(x);
 }
 else{
            yConfig[x] = max(yConfig[x], y);
 }
 }
 
 
 for (auto x : myHash){
        points.push_back({x, yConfig[x]-x*x});
 }
 
 Coord start = points[0];
 int startPos = 0;
 
 for (int i = 1; i < points.size(); i++){
 if (start < points[i]){
            startPos = i;
            start = points[i];
 }
 }
 
    swap(points[startPos], points[0]);
 
 auto it = points.begin();
    it++;
 
    sort(it, points.end(), trigger);
 
    myStack[0] = points[0];
    myStack[1] = points[1];
 int top = 2;
 
 for (int i = 2; i < points.size(); i++){
 for (; !compareTwo(myStack[top-2], myStack[top-1], points[i]);)
            top--;
        myStack[top++] = points[i];
 }
 
 /*
    cout << "\n" << points.size() << "\n";
    for(auto it : points){
        cout << it.x << " " << it.y << "\n";
    }
    */
 
    cout << max(top-1, 1);
}
