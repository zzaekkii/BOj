#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1) {
        answer.emplace_back(-1);
        return answer;
    }
    
    int min = arr[0];
    
    for (int a : arr) {
        if (min > a) {
            min = a;
        }
    }
    
    for (int a: arr) {
        if (a != min) {
            answer.emplace_back(a);
        }
    }
    
    return answer;
}