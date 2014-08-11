#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // use DP to transform the problem into seeking the lowese element in interval [i,j]
        int result = 0;
        int length = height.size();
        int l[height.size()][height.size()];
        
        if(height.size() == 0)
            return 0;
            
        for(int i = 0; i < length; i++) {
            // we need j >= i, set the diagonal to 0
            l[i][i] = 0;
        }
        
        int currLow = height[0];
        // the first row
        for(int j = 0; j < length; j++) {
            if(height[j] < currLow) {
                currLow = height[j];
            }
            l[0][j] = currLow;
        }
        
        // do the update
        for(int i = 1; i < length; i++) {
            for(int j = i + 1; j < length; j++) {
                // the upper one and the left one
                if(l[i-1][j] <= l[i][j-1]) {
                    l[i][j] = l[i-1][j];
                }
                else {
                    l[i][j] = l[i][j-1];
                }
            }
        }
        
        // OK, we have all the intervals, do the calculation
        for(int i = 0; i < length; i++) {
            for(int j = i; j < length; j++) {
                int tmp = l[i][j]*(j-i+1);
                
                if(tmp > result) {
                    result = tmp;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sln;
    vector<int> height;
    /*
    for(int i = 0; i < 1000; i++) {
        height.push_back(i);
    }
    */
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);

    cout << sln.largestRectangleArea(height) << endl;
}
