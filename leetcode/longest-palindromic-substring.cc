#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string lcs(string str1, string str2) {
        cout << str1 <<endl;
        cout << str2 << endl;
        int maxLen = 0;
        int startPosition = 0;
        for(int i = 0; i < str1.length(); i++) {
            for(int j = 0; j < str2.length(); j++) {
                int x = 0;
                while(str1[i+x] == str2[j+x]) {
                    x++;
                
                    if(x + i >= str1.length() || x + j >= str2.length()) {
                        break;
                    }
                }
                
                if(x > maxLen) {
                    maxLen = x;
                    startPosition = i;
                }
            }
        }
        
        return str1.substr(startPosition, maxLen);
    }
    
    string longestPalindrome(string s) {
        // transform the problem to the longest common string of one string and its reverse one?
        if(s.size() == 0) {
            return 0;
        }
        
        string reverse;
        int length = s.size();
        for(int i = 0; i < length; i++) {
            reverse.push_back(s[length - 1 - i]);
        }

        cout << reverse << endl;
        cout << s << endl;
        
        // the longest common string
        return lcs(s, reverse);
    }
};

int main() {

    Solution sln;
    string test = "a";
    cout << sln.longestPalindrome(test) << endl;
}
