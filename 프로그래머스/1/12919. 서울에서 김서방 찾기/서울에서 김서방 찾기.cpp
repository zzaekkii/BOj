#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int idx = 0;
    
    for (string s : seoul) {
        if (s == "Kim") {
            break;
        }
        
        idx += 1;
    }
    
    return "김서방은 " + to_string(idx) + "에 있다";
}