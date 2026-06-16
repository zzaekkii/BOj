#include <string>
#include <vector>
#define max(a, b) (((a)>(b))?a:b)

using namespace std;

int solution(vector<vector<int>> triangle) {
    int depth = triangle.size();
    
    vector<int> dp(depth, 0);
    dp[0]=triangle[0][0];
    
    for(int i=1;i<depth;i++) {
        for(int j=i;j>=1;j--) {
            dp[j]=triangle[i][j]+max(dp[j-1],dp[j]);
        }
        dp[0]+=triangle[i][0];
    }
    
    int answer=0;
    for(int i=0;i<depth;i++){
        answer=max(answer,dp[i]);
    }
    
    return answer;
}