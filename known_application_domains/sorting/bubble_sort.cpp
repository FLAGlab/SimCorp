int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = 5;
	int j = n;
    bool s = true;
    while (s) {
        s = false;
        for (int i = 1; i < j; i++) {
            if (a[i] < a[i - 1]) {
                int t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = true;
            }
        }
        j--;
    }
	return 0;
}