#include <bits/stdc++.h>
using namespace std;

int N,M;
int H[10];
bool prime[9001]={1,1}; // 소수는 0.
int sum,cnt;
vector<int> ans;
bool pick[9001];
bool vis[10];

void Dfs(int idx){
	if(cnt==M){
		if(!prime[sum]&&!pick[sum]){
			ans.push_back(sum);
			pick[sum]=1;
		}
		return;
	}
	
	for(int i=idx;i<N;i++){
		if(!vis[i]){
			vis[i]=1;
			cnt++;
			sum+=H[i];
			Dfs(i+1);
			vis[i]=0;
			cnt--;
			sum-=H[i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=2;i<=9000;i++)
		for(int j=i+i;j<=9000;j+=i)
			prime[j]=1;
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> H[i];
	
	Dfs(0);
	
	sort(ans.begin(),ans.end());
	
	if(!ans.size())cout << -1;
	else
		for(auto a: ans)
			cout << a << ' ';
}
