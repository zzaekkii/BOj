// 1477번 휴게소 세우기 - 골드4 / #이분탐색 #매개변수탐색 
#include <bits/stdc++.h>
using namespace std;

int N, M, L; // 현재 휴게소 N개, 증설 M개, 고속도로 길이 L.
int loc[55]; 
int ans=1000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> L;
    
    N+=2;
    loc[0]=0,loc[1]=L; // 양 끝 위치 추가. 
    for(int i=2;i<N;i++)
    	cin >> loc[i];
    
    sort(loc,loc+N);
    
    int st=1,en=L;
    while(st<=en){
    	int md=(st+en)/2;
    	int cnt=0;
    	
    	for(int i=1;i<N;i++){
    		int dis=loc[i]-loc[i-1]-1;
    		cnt+=dis/md;
    	}
    	
    	if(cnt<=M){
    		ans=md;
			en=md-1;
		}
		else st=md+1;
	}
	
	cout << ans;
}
