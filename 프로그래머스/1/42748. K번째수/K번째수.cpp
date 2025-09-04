#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto command: commands){
        int st=command[0]-1, en=command[1]-1, seq=command[2]-1;
        
        int len=en-st+1;
        int tmp[101]={0};
        for(int i=0;i<len;i++)
            tmp[i]=array[st+i];
        
        sort(tmp,tmp+len);
        
        answer.emplace_back(tmp[seq]);
    }
    
    return answer;
}