// 14248번 점프 점프 - 실버2 / BFS 
#include <bits/stdc++.h>
using namespace std;

int N, S;
int rock[100001];
bool vis[100001];

queue<int> Q;
int cnt; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<=N;i++)
    	cin >> rock[i];
    
    cin >> S;
    
    Q.push(S);
    
    while(!Q.empty()){
    	int cur=Q.front(); Q.pop();
    	vis[cur]=1;
    	
    	int left=cur-rock[cur];
    	int right=cur+rock[cur];
    	
    	if(left>=1&&!vis[left])Q.push(left);
    	if(right<=N&&!vis[right])Q.push(right);
    	
    	cnt++;
	}
	
	cout << cnt;
}
