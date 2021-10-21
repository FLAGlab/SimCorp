#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
 
struct Point{
 long long x, y;
};
 
long long operator^ (const Point &a, const Point &b){
 return a.x * b.y - b.x * a.y;
}
 
long long operator| (const Point &a, const Point &b){
 return a.x * b.x + a.y * b.y;
}
 
Point operator- (const Point &a, const Point &b){
 return Point{a.x - b.x, a.y - b.y};
}
 
int n;
vector <Point> point;
 
bool find_top (Point a, Point b){
 if (a.y != b.y){
 return a.y < b.y;
 } else{
 return a.x > b.x;
 }
}
 
Point top;
 
bool comp (Point a, Point b){
 Point vec1 = a - top, vec2 = b - top;
 auto temp = (vec1^vec2);
 if (temp > 0){
 return true;
 } else if (temp == 0){
 return a.y > b.y;
 } else{
 return false;
 }
}
 
vector <Point> hull;
 
int main(){
//    ifstream cin ("txt.txt");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    point.resize(n);
 for (auto &i: point){
        cin >> i.x >> i.y;
        i.y -= i.x * i.x;
 }
    sort(point.begin(), point.end(), find_top);
    top = point.front();
    sort(point.begin() + 1, point.end(), comp);
    hull.push_back(point[0]);
    hull.push_back(point[1]);
 for (int i = 2; i < n; i++){
 Point vec1 = point[i] - hull[hull.size() - 1 - 1], vec2 = hull[hull.size() - 1 - 0] - hull[hull.size() - 1 - 1];
 while ((vec2^vec1) <= 0){
            hull.pop_back();
            vec2 = hull[hull.size() - 1 - 0] - hull[hull.size() - 1 - 1];
 }
        hull.push_back(point[i]);
 }
 int ans = 0;
 for (int i = 0; i < hull.size() - 1; i++) {
 if (hull[i + 1].x < hull[i].x) {
            ans++;
 }
 }
    cout << ans;
 return 0;
}
