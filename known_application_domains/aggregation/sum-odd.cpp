//
//  sum-odd.cpp
//

int sum_odd(int *arr, int size) {
    int ans = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] % 2 != 0)
            ans += arr[i];
    }
    return ans;
}
