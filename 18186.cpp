// 18186번 라면 사기 (Large) - 다이아몬드4 / #그리디 
#include <bits/stdc++.h>
using namespace std;

int N;
long long B, C;
int A[1000001];
long long ans;

void BuyTwo(int idx){
	int mn=min(A[idx],A[idx+1]);
	A[idx]-=mn,A[idx+1]-=mn;
	ans+=mn*(B+C);
}

void BuyThree(int idx){
	int mn=min({A[idx],A[idx+1],A[idx+2]});
	A[idx]-=mn,A[idx+1]-=mn,A[idx+2]-=mn;
	ans+=mn*(B+2*C);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> B >> C;
	
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	if(B<C) // 1개가 더 싸면 굳이 세트 안 삼.
		for(int i=0;i<N;i++)
			ans+=A[i]*B;
	else{
		for(int i=0;i<N-2;i++){
			if(A[i+1]>A[i+2]){
				// BuyTwo(i); <- min 바뀌어야 함.
				int mn=min(A[i],A[i+1]-A[i+2]);
				A[i]-=mn,A[i+1]-=mn;
				ans+=mn*(B+C);		
				BuyThree(i);
			}
			else{
				BuyThree(i);
				BuyTwo(i);
			}
			ans+=B*A[i]; // 남은 거 처리.
			A[i]=0;
		}
		
		if(N>=2){
			BuyTwo(N-2);
			ans+=B*A[N-2];
			A[N-2]=0;
		}
		if(N>=1){
			ans+=B*A[N-1];
			A[N-1]=0;
		}
	}
	
	cout << ans;
}
