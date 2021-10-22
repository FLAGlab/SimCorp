// A utility function to swap two elements
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}


// This is code is contributed by rathbhupendra

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = 5, h = n - 1, l = 0;
	// Create an auxiliary stack
	int stack[h - l + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (top >= 0) {
		// Pop h and l
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int x = a[h];
		int i = (l - 1);

		for (int j = l; j <= h - 1; j++) {
			if (a[j] <= x) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i + 1], &a[h]);
		int p = (i + 1);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
	return 0;
}