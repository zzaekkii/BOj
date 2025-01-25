// 18185번 라면 사기 (Small) - 다이아몬드5 / #그리디 
#include <bits/stdc++.h>
using namespace std;

int N;
int A[10001];
long long ans;

// 1 2 1 <- 7+3, 5+5 같네.
// 2 3 1 <- 7+5+3, 5+5+5 같네.

// 1 2 1 2 <- 7+3+3, 5+7+3, 5+5+3+3(오름차순에선 ㄴ) 
// 2 3 1 1 <- 7+5+3+3, 5+5+7. 4개 이상 연속엔 걸리네. 

// 4개 이상 연속에서 3번째가 2번째보다 작으면 2개로. 
void BuyTwo(int idx){
	int mn=min(A[idx],A[idx+1]);
	A[idx]-=mn,A[idx+1]-=mn;
	ans+=mn*5;
}

void BuyThree(int idx){
	int mn=min({A[idx],A[idx+1],A[idx+2]});
	A[idx]-=mn,A[idx+1]-=mn,A[idx+2]-=mn;
	ans+=mn*7;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
		
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	for(int i=0;i<N-2;i++){
		if(A[i+1]>A[i+2]){
			// BuyTwo(i); <- min 바뀌어야 함. 
			// 반례 - 4: 1 3 3 1
			// 아이 이부분 3개 무시하고 지나갔네.
			int mn=min(A[i],A[i+1]-A[i+2]);
			A[i]-=mn,A[i+1]-=mn;
			ans+=5*mn;		
			BuyThree(i);
		}
		else{
			BuyThree(i);
			BuyTwo(i);
		}
		ans+=3*A[i]; // 남은 거 처리.
		A[i]=0;
	}
	
	// N-2 넘어서 남으면? 
	// 0 | 1 1 <- two
	// 0 | 1 2 <- two, one
	// 0 | 0 2 <- one
	
	if(N>=2){
		BuyTwo(N-2);
		ans+=3*A[N-2];
		A[N-2]=0;
	}
	if(N>=1){
		ans+=3*A[N-1];
		A[N-1]=0;
	}
	
	cout << ans;
}
