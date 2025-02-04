// 14011번 Small PhD Restaurant - 실버3 / 그리디, 정렬
#include <bits/stdc++.h>
using namespace std;

struct Challenge{
	int pay, reward;
};

int N, M;
Challenge c[1001];

bool cmp(Challenge x, Challenge y){
	int x_value=x.reward-x.pay;
	int y_value=y.reward-y.pay;
	
	if(x.pay==y.pay)return x_value>y_value;
	else return x.pay<y.pay;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> c[i].pay;
	
	for(int i=0;i<N;i++)
		cin >> c[i].reward;
	
	sort(c,c+N,cmp);
	
	for(int i=0;i<N;i++){
		if((c[i].reward>c[i].pay)&&(M>=c[i].pay))
			M+=c[i].reward-c[i].pay;
	}
	
	cout << M;
}
