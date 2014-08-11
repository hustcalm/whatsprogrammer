#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) {
            return 0;
        }
        
        long result = 0;
        long shiftCounter = 1;
        bool negtive = false;
        
        // the result is negtive?
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            negtive = true;
        }
        
        long dividend_long = (long)dividend;
        long divisor_long = (long)divisor;
        
        if(dividend < 0)
            dividend_long = -dividend_long;
        if(divisor < 0)
            divisor_long = -divisor_long;
        
        
        while(dividend_long - divisor_long >= 0) {
            // add divisors
            result += shiftCounter;
            shiftCounter <<= 1;
            dividend_long -= divisor_long;
            divisor_long <<= 1;
        }
        
        shiftCounter >>= 1;
        divisor_long >>= 1;
        
        while(shiftCounter >= 1 && dividend_long > 0) {
            if(dividend_long - divisor_long >= 0) {
                result += shiftCounter;
                dividend_long -= divisor_long;
            }
            
            shiftCounter >>= 1;
            divisor_long >>= 1;
        }
        
        
        if(negtive == true)
            result = -result;
            
        return result;
    }
};

int main()
{
    cout << 8/3 << " " << -8/3 << endl;
    Solution sln;
    //cout << sln.divide(21, 1) << endl;
    //cout << sln.divide(2147483467, 1) << endl;
    cout << sln.divide(1, 1) << endl;
    cout << sln.divide(99999999, 3) << endl;
    cout << INT_MAX << " " << INT_MIN << endl;
    cout << LONG_MAX << " " << LONG_MIN << endl;
    cout << sln.divide(-2147483648, -2147483648) << endl;
    
}
