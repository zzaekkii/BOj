// 14585번 사수빈탕 - 실버1 / DP, 그리디
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M; // 사탕 바구니 N개, 각 바구니엔 사탕 M개.
pair<int,int> candy[301];
int dp[301];
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> candy[i].X >> candy[i].Y;
	
	// 가까운 순으로 정렬. 
	sort(candy,candy+N);
	
	// 이동거리만큼 빼주기. 
	ans=dp[0]=max(0,M-(candy[0].X+candy[0].Y));
	
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++)
      // 아래 애들만 흡수 가능.
			if(candy[i].X>=candy[j].X&&candy[i].Y>=candy[j].Y)
				dp[i]=max(dp[i],dp[j]);
		
		dp[i]+=max(0,M-(candy[i].X+candy[i].Y));
		ans=max(ans,dp[i]);
	}
	
	cout << ans;
}
