#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int len=schedules.size();
    for(int i=0;i<len;i++)schedules[i]=schedules[i]/100*60+schedules[i]%100;
    
    int answer=0;
    for(int i=0;i<len;i++){
        int cnt=0;
        
        for(int j=0;j<7;j++){
            int day=(j+startday)%7;
            if(day!=0&&day!=6){
                int arrived=timelogs[i][j]/100*60+timelogs[i][j]%100;
                if(arrived<=(schedules[i]+10))cnt++;
            }
        }
        
        if(cnt==5)answer++;
    }
    
    return answer;
}