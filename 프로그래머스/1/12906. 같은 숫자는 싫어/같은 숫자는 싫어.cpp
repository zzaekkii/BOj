#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int len=arr.size();
    answer.emplace_back(arr[0]);
    
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<len;i++)
        if(s.top()!=arr[i]){
            s.push(arr[i]);
            answer.emplace_back(arr[i]);
        }

    return answer;
}