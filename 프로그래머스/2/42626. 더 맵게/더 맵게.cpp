#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int s : scoville) {
        pq.push(s);
    }
    
    int answer = 0;
    while (pq.top() < K) {
        if (pq.size() == 1) {
            return -1;
        }
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        pq.push(first + second * 2);
        answer += 1;
    }
    
    return answer;
}