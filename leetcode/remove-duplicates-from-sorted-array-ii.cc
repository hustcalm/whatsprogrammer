#include <iostream>
using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return a<b?a:b;
    }
    
    int removeDuplicates(int A[], int n) {
        int length = 0;
        
        if(n == 0 || A == NULL) {
            return 0;
        }
        
        if(n == 1) {
            return 1;
        }
        
        int newStart = 0;
        int curLen = 0;
        int next = 0;
        //bool hasDuplicates = false;
        // at most twice, so we will get min{2,length} for each duplicate
        int i = 0;
        for(i = 0; i < n; ) {
            newStart = A[i];
            curLen = 1;
            //hasDuplicates = false;
            if(i + 1 < n && newStart == A[i+1]) {
                i++;
                while(i < n && newStart == A[i]) {
                    curLen++;
                    i++;
                }
            }

            if(curLen == 1) {
                // no duplicates, move on to next
                i++;
            } 

            length += min(curLen, 2);
        }
        
        return length;
    }
};

int main()
{
    Solution sln;
    int A[] = {1, 1, 1, 2, 2, 3};
    cout<<sln.removeDuplicates(A, 6)<<endl;;
    return 0;
}
