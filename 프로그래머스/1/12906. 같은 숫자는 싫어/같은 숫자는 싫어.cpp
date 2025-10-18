#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ans;
    
    int len=arr.size();
    ans.emplace_back(arr[0]);
    
    for(int i=1;i<len;i++)
        if(ans.back()!=arr[i])
            ans.emplace_back(arr[i]);

    return ans;
}