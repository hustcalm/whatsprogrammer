#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // see https://sites.google.com/site/periczeljkosmederevoenglish/matematika/roman-ad-arabic-numerus-racio-et-vice-versa
        // for some rules, yeah, we can do this in a simple way, I mean we can have a lookup table
        // or we can do it the hard way, do the dirty parsing job
        int result = 0;
        int length = s.size();
        std::cout << "length: " << length << std::endl;
        
        for(int i = 0; i < length; ) {
            switch (s[i]){
            case 'M':
                // M is the biggest digit, never be subtracted
                std::cout << "M" << std::endl;

                result += 1000;
                i++;
                break;
            case 'D':
                // D can never be subtracted
                result += 500;
                i++;
                break;
            case 'C':
                if(i+1 < length) {
                    if(s[i+1] == 'D') {
                        // CD
                        result += 500 - 100;
                        i += 2;
                        break;
                    }
                    else if(s[i+1] == 'M') {
                        // CM
                        result += 1000 - 100;
                        i += 2;
                        break;
                    }
                    else {
                        // C
                        result += 100;
                        i++;
                        break;
                    }
                }
                else {
                    // C
                    result += 100;
                    i++;
                    break;
                }
            case 'L':
                // L can never be subtracted
                result += 50;
                i++;
                break;
            case 'X':
                if(i+1 < length) {
                    if(s[i+1] == 'L') {
                        // XL
                        result += 50 - 10;
                        i += 2;
                        break;
                    }
                    else if(s[i+1] == 'C') {
                        // XC
                        result += 100 - 10;
                        i += 2;
                        break;
                    }
                    else {
                        // X
                        result += 10;
                        i++;
                        break;
                    }
                }
                else {
                    // X
                    result += 10;
                    i++;
                    break;
                }
            case 'V':
                // V can never be subtracted, but can add others to its right
                // OK, let's enumerate it
                if(i+3 < length && s[i+1] == 'I' && s[i+2] == 'I' && s[i+3] == 'I') {
                    // VIII
                    result += 5 + 1 + 1 + 1;
                    i += 4;
                    break;
                }
                else if(i+2 < length && s[i+1] == 'I' && s[i+2] == 'I') {
                    // VII
                    result += 5 + 1 + 1;
                    i += 3;
                    break;
                }
                else if(i+1 < length && s[i+1] == 'I') {
                    // VI
                    result += 5 + 1;
                    i += 2;
                    break;
                }
                else{
                    // V
                    result += 5;
                    i++;
                    break;
                }
                
            case 'I':
                // well, the most annoying digital in Roman numerical, however we can enumerate as V
                if(i+2 < length && s[i+1] == 'I' && s[i+2] == 'I') {
                    // III
                    result += 1 + 1 + 1;
                    i += 3;
                    break;
                }
                else if(i+1 < length && s[i+1] == 'I') {
                    // II
                    result += 1 + 1;
                    i += 2;
                    break;
                }
                else if(i+1 < length && s[i+1] == 'V') {
                    // IV
                    result += 5 - 1;
                    i += 2;
                    break;
                }
                else if(i+1 < length && s[i+1] == 'X') {
                    // IX
                    result += 10 - 1;
                    i += 2;
                    break;
                }
                else {
                    // I
                    result += 1;
                    i++;
                    break;
                }
        }
        }
        
        return result;
    }
};

int main()
{
    Solution slt;
    std::cout << slt.romanToInt("MMMCC") << std::endl;
    return 0;
}
