#include <string>
#include <vector>

using namespace std;

int time_to_int(string time){
    return (time[0]-48)*600+(time[1]-48)*60+(time[3]-48)*10+(time[4]-48);
}

string int_to_time(int total){
    int h=total/60;
    int m=total%60;
    return to_string(h/10)+to_string(h%10)+":"+to_string(m/10)+to_string(m%10);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_end=time_to_int(video_len);
    int cur=time_to_int(pos);
    int op_st=time_to_int(op_start);
    int op_en=time_to_int(op_end);
    
        
    if(op_st<=cur&&cur<=op_en)
        cur=op_en;
    
    for(auto c: commands){
        if(c=="prev"){
            cur=max(0,cur-10);
        }
        else if(c=="next"){
            cur=min(video_end,cur+10);
        }
        
        if(op_st<=cur&&cur<=op_en)
            cur=op_en;
    }
    
    return int_to_time(cur);
}