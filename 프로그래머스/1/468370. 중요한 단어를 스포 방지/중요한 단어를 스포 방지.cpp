#include <bits/stdc++.h>
using namespace std;

struct Keyword {
    string value;
    int st, en;
};

Keyword get_keyword(
    int start, int end,
    const string& message
) {
    string value = "";
    
    for (int i = start; i < end; i++) {
        if (message[i] == ' ') {
            return Keyword(value, start, i - 1);
        }
        
        value += message[i];
    }
    
    return Keyword(value, start, end);
}

bool is_spoiler(
    Keyword keyword,
    const vector<vector<int>>& spoiler_ranges
) { 
    for (auto range : spoiler_ranges) {
        if (range[0] <= keyword.st && keyword.st <= range[1]
            || range[0] <= keyword.en && keyword.en <= range[1]
            || keyword.st <= range[0] && range[0] <= keyword.en
            || keyword.st <= range[1] && range[1] <= keyword.en) {
            return true;
        }
    }
    
    return false;
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    vector<Keyword> all_keywords;
    unordered_set<string> public_keywords;
    int len = message.size();
    
    // 전체 단어 추가
    for (int i = 0; i < len;) {
        if (message[i] == ' ') {
            i += 1;
            continue;
        }
        
        Keyword cur = get_keyword(i, len, message);
        all_keywords.push_back(cur);
        
        // 공개 단어 추가
        if (!is_spoiler(cur, spoiler_ranges)) {
            public_keywords.insert(cur.value);
        }
        
        i += cur.value.size() + 1;
    }
    
    int answer = 0;
    for (Keyword cur : all_keywords) {
        string value = cur.value;
        
        if (public_keywords.find(value) == public_keywords.end()) {
            if (is_spoiler(cur, spoiler_ranges)) {
                answer += 1;
                public_keywords.insert(value);
            }
        }
    }
    
    return answer;
}
