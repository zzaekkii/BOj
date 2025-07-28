#include <bits/stdc++.h>
using namespace std;

unordered_map<string,unordered_map<string,int>> relation;
unordered_map<string,int> send;
unordered_map<string,int> received;
unordered_map<string,int> gift_idx;
unordered_map<string,int> result;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 선물 기록.
    for(auto a: gifts){
        int pos = a.find(' ');
        string sender=a.substr(0,pos);
        string receiver=a.substr(pos+1);
        
        relation[sender][receiver]++;
        
        send[sender]++;
        received[receiver]++;
    }
    
    // 선물 지수 계산.
    for(auto a: friends)
        gift_idx[a]=send[a]-received[a];
    
    int len=friends.size();
    // friends 돌아가면서 1:1 확인.
    for(int i=0;i<len-1;i++){
        string a=friends[i];
        for(int j=i+1;j<len;j++){
            string b=friends[j];
            
            int a_cnt=relation[a][b];
            int b_cnt=relation[b][a];
            
            if(a_cnt>b_cnt)
                result[a]++;
            else if(a_cnt<b_cnt)
                result[b]++;
            else{
                if(gift_idx[a]>gift_idx[b])
                    result[a]++;
                else if(gift_idx[a]<gift_idx[b])
                    result[b]++;
            }
        }
    }
    
    // 최대값 판별.
    for(auto a: friends)
        if(answer<result[a])
            answer=result[a];
    
    return answer;
}