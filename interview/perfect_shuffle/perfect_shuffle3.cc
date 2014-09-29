/*
 * A key observation when 2*n = (3^k - 1)
 * O(n) time
 * O(1) space
 */

//数组下标从1开始，from是圈的头部，mod是要取模的数 mod 应该为 2 * n + 1，时间复杂度O(圈长）
void cycle_leader(int *a,int from, int mod) {
int last = a[from],t,i;
    
    for (i = from * 2 % mod;i != from; i = i * 2 % mod) {
        t = a[i];
        a[i] = last;
        last = t;
        
    }
    a[from] = last;
}

//翻转字符串时间复杂度O(to - from)
void reverse(int *a,int from,int to) {
int t;
    for (; from < to; ++from, --to) {
        t = a[from];
        a[from] = a[to];
        a[to] = t;
    }
    
}

//循环右移num位 时间复杂度O(n)
void right_rotate(int *a,int num,int n) {
    reverse(a, 1, n - num);
    reverse(a, n - num + 1,n);
    reverse(a, 1, n);
}

//时间O(n)，空间O(1)
void perfect_shuffle3(int *a,int n) {
int n2, m, i, k,t;
    for (;n > 1;) {
        // step 1
        n2 = n * 2;
        for (k = 0, m = 1; n2 / m >= 3; ++k, m *= 3)
        ;
        m /= 2;
        // 2m = 3^k - 1 , 3^k <= 2n < 3^(k + 1)
        
        // step 2
        right_rotate(a + m, m, n);
        
        // step 3
        
        for (i = 0, t = 1; i < k; ++i, t *= 3) {
            cycle_leader(a , t, m * 2 + 1);
            
        }
        
        //step 4
        a += m * 2;
        n -= m;
    
    }
    // n = 1
    t = a[1];
    a[1] = a[2];
    a[2] = t;
    
}
