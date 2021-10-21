void sort(int *a, int n) {
  int i = 0, t;
  while (i < n) {
      if (i == 0 || a[i - 1] <= a[i])
        i++;
      else {
        t = a[i-1];
        a[i - 1] = a[i];
        a[i] = t;
        i--;
      }
  }
}
