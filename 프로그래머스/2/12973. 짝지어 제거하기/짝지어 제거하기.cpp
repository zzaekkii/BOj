#include <string>

using namespace std;

int solution(string s) {
    string stack;
    
    for (char c : s) {
        if (!stack.empty() && stack.back() == c) {
            stack.pop_back();
        }
        else {
            stack.push_back(c);
        }
    }
    
    return stack.empty();
}