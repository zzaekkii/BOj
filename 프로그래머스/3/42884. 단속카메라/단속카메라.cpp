#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(),
        [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
    
    int answer = 1;
    int camera = routes[0][1];
    
    for (auto& route : routes) {
        if (route[0] > camera) {
            answer += 1;
            camera = route[1];
        }
    }
    
    return answer;
}