//
//  sum-odd.cpp
//  
//

int main() {
    int a[] = {1, 2, 3, 4, 5};
	int n = 5, ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != 0)
            ans += a[i];
    }
    return 0;
}
