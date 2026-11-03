#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}


int solution(vector<vector<int>> signals) {
    int end = 1;
    
    for (auto& signal : signals) {
        int cycle = signal[0] + signal[1] + signal[2];
        end = lcm (cycle, end);
    }
    
    int answer = 0;
    for (int i = 0; i <= end; i++) {
        bool all_yellow = true;
        
        for (auto& signal : signals) {
            int g = signal[0], y = signal[1], r = signal[2];
            int cycle = g + y + r;
            int cur = i % cycle;
            
            if (cur <= g || cur > g + y) {
                all_yellow = false;
                break;
            }
        }
        
        if (all_yellow) {
            return i;
        }
    }
    
    return -1;
}