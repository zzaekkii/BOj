// 1374번 강의실 - 골드5 / 그리디, 우선순위 큐 
#include <bits/stdc++.h>
using namespace std;

int N, T;
pair<int,int> lec[100001];
priority_queue<int,vector<int>,greater<int>> pq;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> T >> lec[i].first >> lec[i].second;
	
	sort(lec,lec+N);
	
	for(int i=0;i<N;i++){
		if(!pq.empty()){
			if(pq.top()>lec[i].first)ans++;
			else pq.pop();
		}
		else ans++;
		
		pq.push(lec[i].second);
	}
	
	cout << ans;
}
