// 19942번 다이어트 - 골드4 / 백트래킹 
#include <bits/stdc++.h>
using namespace std;

struct Nut{
	int pro,fat,carb,vita;
};

struct Ingre{
	int pro,fat,carb,vita;
	int price;
};

int N;
Ingre ingre[16];
Nut stan; // 만족 조건. 
Nut total; // 가능한지 총량 체크. 

int mnPrice=10000;
vector<int> ans;
bool bought[16];

bool Condi(Nut cur){
	if(cur.pro>=stan.pro&&cur.fat>=stan.fat
		&&cur.carb>=stan.carb&&cur.vita>=stan.vita)
		return 1;
	else return 0;
}

void Dfs(int cur, Nut sum, int price){
	// 영양 기준 맞춘 경우.
	if(Condi(sum)){
		// 더 가성비인 경우 (사전순이라 등호 뺌) 
		if(mnPrice>price){
			ans.clear();
			
			mnPrice=price;
			for(int i=0;i<N;i++)
				if(bought[i])ans.emplace_back(i+1);
		}
		
		return;
	}
	
	for(int i=cur;i<N;i++){
		// 포함. 
		bought[i]=1;
		Nut nxt={sum.pro+ingre[i].pro,sum.fat+ingre[i].fat,
			sum.carb+ingre[i].carb,sum.vita+ingre[i].vita};
		Dfs(i+1,nxt,price+ingre[i].price);
		
		// 미포함. 
		bought[i]=0;
		Dfs(i+1,sum,price); 
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    // 기준 영양. 
    cin >> stan.pro >> stan.fat >> stan.carb >> stan.vita;
    
    // 재료 영양+가격. 
    for(int i=0;i<N;i++){
    	int pro,fat,carb,vita,price;
    	
    	cin >> pro >> fat >> carb >> vita >> price;
    	ingre[i]={pro,fat,carb,vita,price};
    	
    	total.pro+=pro;
    	total.fat+=fat;
    	total.carb+=carb;
    	total.vita+=vita;
	}
	
	// 다 사도 영양 기준을 만족할 수 없을 때. 
	if(!Condi(total)){
		cout << -1;
		return 0;
	}
	
	// 가성비 영양 기준 맞추기.
	Dfs(0,(Nut){0,0,0,0},0);
	
	// 정답 출력.
	cout << mnPrice << '\n';
	
	for(auto a: ans)
		cout << a << ' '; 
}
