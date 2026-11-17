#include <bits/stdc++.h>
using namespace std;

struct Content {
    string head;
    int number;
    string tail;
    int idx;
    
    bool operator<(const Content& other) const {
        if (head != other.head) {
            return head < other.head;
        }
        
        if (number != other.number) {
            return number < other.number;
        }
        
        return idx < other.idx;
    }
};

Content trans_content(string file, int idx) {
    string head;
    
    int cur = 0;
    while (file[cur] < '0' || file[cur] > '9') {
        head += toupper(file[cur++]);
    }
    string str_number;
    int number = 0;
    while ('0' <= file[cur] && file[cur] <= '9') {
        number = number * 10 + (file[cur] - '0');
        str_number += file[cur++];
    }
    
    string tail;
    while (cur < file.size()) {
        tail += file[cur++];
    }
    
    return Content(head, number, tail, idx);
}

vector<string> solution(vector<string> files) {
    int files_count = files.size();
    vector<Content> contents;
    for (int i = 0; i < files_count; i++) {
        Content cur = trans_content(files[i], i);
        contents.push_back(cur);
    }
    
    sort(contents.begin(), contents.end());
    
    vector<string> answer;
    for (Content content : contents) {
        answer.push_back(files[content.idx]);
    }
    
    return answer;
}