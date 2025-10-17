#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int student[31]={0};
    
    for(int i=1;i<=n;i++)student[i]=1;
    
    for(int r: reserve)student[r]++;
    for(int l: lost)student[l]--;
    
    int ans=0;
    for(int i=1;i<=n;i++){
        if(student[i]==0){
            if(student[i-1]==2) ans++;
            else if(student[i+1]==2){
                student[i+1]=1;
                ans++;
            }
        }
        else ans++;
    }
        
    return ans;
}