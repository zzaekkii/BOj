#include <bits/stdc++.h>
using namespace std;

int N; // 사탕 종류. 
double M,P; // 머니, 사탕 가격 
int money; // 머니*100. 
int kcal[5001]; // 각 사탕 칼로리. 
int price[5001]; // 각 사탕 가격 (정수).

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(1){
		cin >> N >> M;
		if(!N&&!M)break;
		
		money=M*100+0.5;
		
		for(int i=0;i<N;i++){
			cin >> kcal[i] >> P;
			price[i]=P*100+0.5;
		}
		
		int dp[10001]={0}; // 이 돈으로 살 수 있는 맥스 칼로리.
		for(int i=0;i<N;i++)
			for(int j=price[i];j<=money;j++)
				dp[j]=max(dp[j],dp[j-price[i]]+kcal[i]);
		
		cout << dp[money] << '\n';
	}
}
