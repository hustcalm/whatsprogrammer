#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int oldL = L;
        int currCounter = 0;
        int startIndex = 0;
        
        if(words.size() == 0) {
            return result;
        }
        
        for(int i = 0; i < words.size();) {
            cout << "i: " << i << endl;
            currCounter = 0;
            L = oldL;
            string tmp;
            startIndex = i;

            if(words[i].size() == 0) {
                // empty string
                while(L--)
                    tmp.append(" ");
                result.push_back(tmp);
                i++;
                continue;
            }
            
            while(words[i].size() <= L && i < words.size()) {
                L -= words[i].size();
                cout << "L: " << L << endl;
                currCounter++;
                i++;
            }
            
            // got currCounter words in the line and left L spaces
            int spaceNumber = L;
            cout << "Space number: " << spaceNumber << endl;
            cout << "Word number: " << currCounter << endl;
            
            // need to fill currCounter - 1 gaps
            if(currCounter == 1) {
                tmp.append(words[startIndex]);
                while(spaceNumber-- > 0){
                    tmp.append(" ");
                }
            }
            else {
                int spacePerGapBase = spaceNumber / (currCounter - 1);
                int spacePerGapMod = spaceNumber - spacePerGapBase*(currCounter - 1);
                cout << "Base: " << spacePerGapBase << " Mod: " << spacePerGapMod << endl;
                int j;
                for(j = 0; j < currCounter - 1; j++) {
                        tmp.append(words[startIndex + j]);
                        for(int k = 0; k < spacePerGapBase; k++) {
                            tmp.append(" ");
                        }
                        if(j < spacePerGapMod) {
                            tmp.append(" ");
                        }
                }
                // the last word
                tmp.append(words[startIndex + j]);
            }
            
            result.push_back(tmp);
        }
        return result;
    }
};

int main()
{
    Solution sln;
    vector<string> words;
    words.push_back("hello");
    words.push_back("hello");
    words.push_back("hello");
    words.push_back("hello");
    words.push_back("hello");
    int L = 14;

    words.clear();
    words.push_back("");
    L = 0;

    words.clear();
    words.push_back("a");
    L = 1;

    std::cout << sln.fullJustify(words, L).size() << std::endl;
    vector<string> result = sln.fullJustify(words, L);
    cout << "result: " << endl;
    for(int i = 0; i <  result.size(); i++) {
        
        cout << result[i] << endl;
    }
}
