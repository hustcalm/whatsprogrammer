/*
 * Divide and Conquer
 * O(nlogn) time
 * O(1) space
 */
void perfect_shuffle2(int *a, int n) {
    int t, i;

    if(n == 1) {
        t = a[1];
        a[1] = a[2];
        a[2] = t;
    }

    int n2 = n*2, n3=n/2;

    // deal with odd
    if(n % 2 == 1) {
        t = a[n];
        for(i = n + 1; i <= n2; ++i) {
            // move the elements one step forward
            a[i-1] = a[i];
        }
        // place the tailing element to the right place
        a[n2] = t;
        --n;
    }

    // now n is even
    for(i = n3 + 1; i <= n; ++i) {
        t = a[i];
        a[i] = a[i+n3];
        a[i+n3] = t;
    }

    // divide and conquer recursively
    perfect_shuffle2(a, n3);
    perfect_shuffle2(a+n, n3);
}

