// 2343번 기타 레슨 - 실버1 / #매개변수탐색 
#include <bits/stdc++.h>
using namespace std;

int N, M; // 강의 N개를 블루레이 M개에 나눠 담을 예정.
int A[100001]; // 강의 시간.
int sum; // 누적합. 

int ans; // 최소 블루레이 크기. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    int st=0, en=0;
    for(int i=0;i<N;i++){
    	cin >> A[i];
    	st=max(st,A[i]); // 단일 길이가 가장 긴 영상. 
    	en+=A[i]; // 하나에 영상을 다 담을 때(누적합). 
    }
    
    while(st<=en){
    	int md=(st+en)/2;
		
		// 블루레이에 담긴 길이 cur, 블루레이 수. 
		int cur=0, cnt=1;
		
		for(int i=0;i<N;i++){
			// 탈출: 지금 블루레이 크기로는 담기 불가능. 
			if(md<A[i]){
				cnt=M+1;
				break;
			}
			
			// 현재 블루레이에 담기면, 
			if(cur+A[i]<=md) cur+=A[i];
			else {
				cur=A[i];
				cnt++;
			}
		}
		
		// M개 안으로 가능.
		if(cnt<=M){
			ans=md;
			// 더 줄여지나 알아보기.
			en=md-1;
		}
		// 크기 늘리는 걸로.
		else st=md+1;
	}
    
    
    cout << ans;
}
