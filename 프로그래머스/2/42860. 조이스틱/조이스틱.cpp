#include <bits/stdc++.h>
#define MAX 520
using namespace std;

int solution(string name) {
    int total = 0;
    int len = name.size();
    
    for (char c : name) {
        total += min(c - 'A', 'Z' - c + 1);
    }

    int move = len - 1;

    for (int i = 0; i < len; i++) {
        int next = i + 1;

        while (next < len && name[next] == 'A') {
            next++;
        }

        int right_first = 2 * i + (len - next);
        int left_first = i + 2 * (len - next);

        move = min({move, right_first, left_first});
    }

    return total + move;
}