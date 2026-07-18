#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    vector<int> expired(25 + k);
    int running = 0;
    int answer = 0;
    
    for (int hour = 0; hour < 24; hour++) {
        running -= expired[hour];
        
        int required = players[hour] / m;
        if (running < required) {
            int added = required - running;
            
            running += added;
            answer += added;
            
            expired[hour + k] += added;
        }
    }
    
    return answer;
}