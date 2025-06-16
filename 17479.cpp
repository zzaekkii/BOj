// 17479번 정식당 - 실버3 / 구현 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A, B, C, P, N;
unordered_map<string,int> price;
unordered_map<string,int> type; // 0: gen, 1: spe, 2: ser.
ll gen, spe, ser;
string S;

bool pos=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> C;
    
    for(int i=0;i<A;i++){
    	cin >> S >> P;
    	type[S]=0;
    	price[S]=P;
	}
	
	for(int i=0;i<B;i++){
    	cin >> S >> P;
    	type[S]=1;
    	price[S]=P;
	}
	
	for(int i=0;i<C;i++){
    	cin >> S;
    	type[S]=2;
	}
	
	cin >> N;
	
	while(N--){
		cin >> S;
		
		switch(type[S]){
			case 0:
				gen+=price[S];
				break;
			case 1:
				spe+=price[S];
				break;
			case 2:
				if(ser)pos=0;
				ser++;
				break;
		}
	}
	
	if(ser&&((gen+spe)<50000))pos=0;
	if(spe&&(gen<20000))pos=0;
	
	if(pos)cout << "Okay";
	else cout << "No";
}
