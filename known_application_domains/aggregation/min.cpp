int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = 5;
	int ans = n > 0 ? a[0] : 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < ans)
            ans = a[i];
    }
	return 0;
}