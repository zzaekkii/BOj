#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    stack<char> st;
    
    for (char n : number) {        
        while (!st.empty() && st.top() < n && k > 0) {
            st.pop();
            k -= 1;
        }
        
        st.push(n);
    }
    
    while (k > 0) {
        st.pop();
        k -= 1;
    }
    
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}