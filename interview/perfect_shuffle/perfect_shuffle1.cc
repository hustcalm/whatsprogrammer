/*
 * O(n) time complexity
 * O(n) space complexity
 */
void perfect_shuffle1(int *a, int n) {
    int n2 = 2*n, b[n2];

    for(int i = 1; i <= n2; ++i) {
        b[(2*i)%(n2+1)] = a[i];
    }
    for(int i = 1; i <= n2; ++i) {
        a[i] = b[i];
    }
}
