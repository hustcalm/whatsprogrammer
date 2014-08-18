#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length = gas.size();
        int remaining = 0;
        int gas_count = 0;
        int starting_point = 0;
        
        for(int i = 0; i < length; i++) {
            remaining = 0;
            gas_count = 0;
            
            if(gas[i] >= cost[i]) {
                gas_count++;
                starting_point = i;
                
                if(gas_count == length) {
                    return i;
                }
                
                remaining += gas[i] - cost[i];
                //cout<<remaining<<endl;
                
                while(remaining >= 0) {
                    starting_point = (starting_point+1)%length;
                    remaining += gas[starting_point] - cost[starting_point];
                    //cout<<remaining<<endl;

                    if(remaining < 0) {
                        break;
                    }
                    
                    if(remaining >= 0) {
                        gas_count++;
                    }
                    
                    if(gas_count == length) {
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};

int main()
{
    Solution sln;
    int gas[] = {2, 4};
    vector<int> gasTest(gas, gas+sizeof(gas)/sizeof(int));
    int cost[] = {3,4};
    vector<int> costTest(cost, cost+sizeof(cost)/sizeof(int));
    cout<<sln.canCompleteCircuit(gasTest,costTest)<<endl;
}
