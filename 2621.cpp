#include <bits/stdc++.h>
using namespace std;

char C; // 색.
int N; // 숫자.
int op;

// 같은 색이 몇개인지 -> map size() 및 요소 탐색 
map<char,int> color;
bool desc_col(pair<char,int>& a,pair<char,int>& b){
	return a.second>b.second;
}
// 숫자가 연속적이다 -> value기준 정렬 후 +1 판별.
bool asc_num(pair<int,int>& a,pair<int,int>& b){
	return a.second<b.second;
}
// 같은 숫자가 몇 개인지 -> map으로 판별.
map<int,int> number;
bool desc_num(pair<int,int>& a,pair<int,int>& b){
	return a.second>b.second;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<5;i++){
		cin >> C >> N;
		color[C]++;
		number[N]++;
	}
	
	// 정렬용 벡터. 
	vector<pair<char,int>> vc(color.begin(),color.end());
	vector<pair<int,int>> vn(number.begin(),number.end());
	
	// 숫자 내림차순 정렬
	sort(vn.begin(),vn.end(),desc_num); 
	
	// 모든 숫자가 연속적인지 판별.
	bool seq=1;
	int prev=0;
	for(auto i=number.begin();i!=number.end();i++){
		if(i==number.begin()){
			prev=i->first;
			continue;
		}
		if(prev+1!=i->first)seq=0;
		prev=i->first;
	}
	if(number.size()!=5)seq=0; 
	
	// ① if 5장 모두 같은 색 && 모든 숫자가 연속적:
	// => 가장 큰 수 + 900
	if(color.size()==1&&seq){
		cout << (--number.end())->first+900;
	}
	// ② if 같은 숫자 4장:
	// => 같은 수 + 800
	else if(vn.begin()->second==4){
		cout << (vn.begin()->first+800);
	}
	// ③ if 같은 숫자 3장 && 같은 숫자 2장:
	// => 3장인 수 * 10 + 2장인 수 + 700 
	else if(vn.begin()->second==3&&(++vn.begin())->second==2){
		cout << vn.begin()->first*10+(++vn.begin())->first+700;
	}
	// ④ if 5장 모두 같은 색:
	// => 가장 큰 수 + 600
	else if(color.size()==1){
		cout << (--number.end())->first+600;
	}
	// ⑤ if 모든 숫자가 연속적:
	// => 가장 큰 수 + 500
	else if(seq){
		cout << (--number.end())->first+500;
	}
	// ⑥ if 같은 숫자 3장:
	// => 같은 수 + 400
	else if(vn.begin()->second==3){
		cout << vn.begin()->first+400;
	}
	// ⑦ if 같은 숫자 2장 && 같은 숫자 2장:
	// => 같은 숫자 중 큰 수 * 10 + 작은 수 + 300
	else if(vn.begin()->second==2&&(++vn.begin())->second==2){
		cout << max(vn.begin()->first,(++vn.begin())->first)*10+min(vn.begin()->first,(++vn.begin())->first)+300;
	}
	// ⑧ if 같은 숫자 2장:
	// => 같은 수 + 200
	else if(vn.begin()->second==2){
		cout << vn.begin()->first+200;
	}
	// ⑨ default:
	// => 가장 큰 수 + 100
	else{
		cout << (--number.end())->first+100;
	}
}

// 어떤 색이 몇 개인지, 어떤 숫자가 몇 개인지만 기록 후 판별. 
