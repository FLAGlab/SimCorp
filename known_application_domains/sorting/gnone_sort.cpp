int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = 5;
	int i = 0;
  while (i < n) {
      if (i == 0 || a[i - 1] <= a[i])
        i++;
      else {
        int t = a[i-1];
        a[i - 1] = a[i];
        a[i] = t;
        i--;
      }
  }
	return 0;
}