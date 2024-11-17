// 2110번 공유기 설치 - 골드4 / #이분탐색 #매개변수탐색 
#include <bits/stdc++.h>
using namespace std;

int N, C; // 집 N개, 공유기 C개.
int H[200001]; // 집 좌표들.

int ans; // 최대 거리.

// 주어진 거리를 최소로 몇 개나 가능한가. 
int Cnt(int len){
	int cnt=1, prev=H[0]; // 현재 개수와 이전 값 기록.
	
	for(int i=1;i<N;i++)
		// 지금 좌표에서 이전 좌표 사이 거리가 충분한가, 
		if(H[i]-prev>=len){
			cnt++;
			prev=H[i];
		}
	
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    
    for(int i=0;i<N;i++)
    	cin >> H[i];
    
    // 좌표 오름차순 정렬. 
    sort(H, H+N);
    
    int st=1, en=H[N-1]; // 공유기간 최대 거리는 1 ~ H[N-1]에 존재. 
	while(st<=en){
		// 시험 해 볼 거리값.
		int md=(st+en)/2; 
		
		if(Cnt(md)>=C){
			ans=md;
			// 더 길게도 되나 확인. 
			st=md+1;
		}
		else en=md-1;
	}
	
	cout << ans;
}
