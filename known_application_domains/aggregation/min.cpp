int get_min(int *a, int n) {
    int ans = n > 0 ? a[0] : 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < ans)
            ans = a[i];
    }
    return ans;
}
