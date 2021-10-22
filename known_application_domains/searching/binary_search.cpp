
int main() {
	int a[] = {1, 2, 3, 4, 5};
	int k = 4, n = 5;
	int lo = 0, hi = n - 1, ans = -1;
	while(lo < hi) {
		int mid= (lo + hi)/2;
		if(k <= a[mid]) {
			hi = mid;
		} else {
		    lo=mid+1;
		}
	}
	if(a[lo] == k)
        ans = lo;
	return 0;
}