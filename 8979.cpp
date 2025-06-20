// 8979번 올림픽 - 실버5 / 정렬 
#include <bits/stdc++.h>
using namespace std;

struct Country{
	int g, s, b;
};

int N, K;
Country con[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    for(int i=0;i<N;i++){
    	int num, g, s, b;
    	cin >> num >> g >> s >> b;
    	
    	con[num]={g,s,b};
	}
	
	int rank=1;
	for(int i=1;i<=N;i++){
		if(con[K].g!=con[i].g)rank+=con[K].g<con[i].g;
		else if(con[K].s!=con[i].s)rank+=con[K].s<con[i].s;
		else rank+=con[K].b<con[i].b;
	}
	
	cout << rank;
}
