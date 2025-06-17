// 11000번 강의실 배정 - 골드5 / 우선순위 큐, 그리디 
#include <bits/stdc++.h>
using namespace std;

int N;
pair<int,int> W[200001];
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> W[i].first >> W[i].second;
    
    sort(W,W+N);
    
    pq.push(W[0].second);
    for(int i=1;i<N;i++){
    	if(W[i].first>=pq.top())pq.pop();
    	
		pq.push(W[i].second);
	}
	
	cout << pq.size();
}
