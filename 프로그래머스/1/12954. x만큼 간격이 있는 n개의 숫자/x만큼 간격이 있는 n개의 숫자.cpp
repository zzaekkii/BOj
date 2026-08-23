#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);
    
    long long target = x;
    answer[0] = target;
    
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] + target;
    }
    
    return answer;
}