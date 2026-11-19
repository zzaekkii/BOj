#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> st;
    
    int len = prices.size();
    vector<int> answer(len);
    for (int i = 0; i < len; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        
        st.push(i);
    }
    
    while (!st.empty()) {
        answer[st.top()] = len - 1 - st.top();
        st.pop();
    }
    
    return answer;
}