#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int max(int a, int b) {return a>b?a:b;}
    
    int maxArea(vector<int> &height) {
        height.push_back(0);
        int i = 0;
        stack<int> stk;
        int maxArea = 0;
        while(i < height.size()) {
            if(stk.empty() || (height[stk.top()] < height[i])) {
                stk.push(i++);
            }
            else {
                int t = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[t]*(stk.empty()?i:(i - stk.top() - 1)));
            }
        }
        
        return maxArea;
    }
};

int main() {
    Solution sln;
    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    cout << sln.maxArea(height) << endl;    
}
