int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = 5, k = 4;
	int ans = -1;
    for (int i = 0; i < n && ans == -1; ++i) {
        if (a[i] == k)
            ans = i;
    }
	return 0;
}