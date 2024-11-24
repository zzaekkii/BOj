// 3079번 입국심사 - #이분탐색 #매개변수탐색
#include <bits/stdc++.h> 
typedef long long ll;
using namespace std;

int N, M; // 입국 심사대 N곳, 총 M명.
int T[100001]; // 심사대별 소요 시간. 

ll ans; // 심사 최소 시간. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
    	cin >> T[i];
    
    sort(T,T+N); // 소요 시간별로 오름차순 정렬. 
    // 필요 없을 수 있지만,
	// 정렬된 데이터가 계산에 더 효율적인지 궁금. 
    
    ll st=0;
    ll en=1'000'000'000'000'000'000;
    unsigned long long cnt=0;
    while(st<=en){
    	ll md=(st+en)/2;
    	cnt=0;
    	
    	for(int i=0;i<N&&cnt<M;i++)
    		cnt+=(md/T[i]);
    	
    	if(cnt>=M){
    		ans=md;
    		en=md-1;
		}
		else st=md+1;
	}
    
    cout << ans;
}
