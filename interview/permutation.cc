#include <iostream>  
#include <vector>  
#include <string.h>  
#include <functional>  
#include <numeric>  
using namespace std;  

// Print the permutation  
void PrintPermutation(const vector<int> & per)  
{  
    static int count = 1;  
    cout << count ++<<"\t: ";  
    for(int i = 0; i < per.size(); ++i)  
    {  
        cout << per[i] <<" ";  
    }  
    cout <<endl;  
}  
  
// flags : mark whether the element has been used.  
// array : the elements that need to be permutated  
// per   : used to store the permutation.  
// Len   : length of array or the permutation  
void Permutation(bool flags[] , int array[] , vector<int> & per, int Len)  
{  
    if (per.size() == Len)  
    {  
        PrintPermutation(per);  
        return;  
    }  
    for(int i = 0; i < Len; ++i)  
    {  
        if (flags[i]) continue;  
        per.push_back(array[i]);  
        flags[i] = true;  
        Permutation(flags, array, per, Len);  
        flags[i] = false;  
        per.pop_back();  
    }  
}  

// times : array数组中每个元素出现我次数  
// tLen  : array数组的长度  
// perLen: 最终生成的排列长度，等于times中每个元素的和  
void PermutationWithoutDuplicate(int times[], int array[], int tLen, vector<int> & per, int perLen)  
{  
    if (per.size() == perLen)  
    {  
        PrintPermutation(per);  
        return;  
    }  
      
    for(int i = 0; i < tLen; ++i)  
    {  
        //times[i] == 0说明该元素已经被全部使用  
        if (times[i] > 0)  
        {  
            times[i] --;//出现的次数减1，重复的元素可以多次出现  
            per.push_back(array[i]);  
            PermutationWithoutDuplicate(times, array, tLen, per, perLen);  
            times[i] ++;  
            per.pop_back();  
        }  
    }  
}  

int main()  
{  
    int array[] = {1,2,3,4};  
    bool flags[] = {0,0,0,0};  
    vector<int> per;  
    Permutation(flags, array, per, sizeof(array)/sizeof(int));  
      
    cout <<" Permutations without duplicated elements"<<endl;  
      
    //without duplicated permutation  
    {  
        int array[] = {1,2,3,4};  
        int times[] = {1,2,1,2};  
        per.clear();  
        int sum = 0;  
        PermutationWithoutDuplicate(times, array, sizeof(array)/4, per, accumulate(times, times+ sizeof(times)/4, sum));  
    }  
    return 0;  
}  
