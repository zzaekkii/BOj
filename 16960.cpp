#include <bits/stdc++.h>
using namespace std;
int N, M, T, K;
int arr[2001];
vector<int> V[2001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
    	cin >> T;
    	while(T--){
    		cin >> K;
    		arr[K]++;
    		V[i].push_back(K);
		}
	}
	
	bool f=0;
	for(int i=0;i<N;i++){
		f=1;
		for(int j=0;j<V[i].size();j++)
			if(arr[V[i][j]]<=1){
				f=0;
				break;
			}
		if(f)break;
	}
	cout << f;
}
