// 1270번 전쟁 - 땅따먹기 - 실버3 / 해시맵
#include <bits/stdc++.h>
using namespace std;

int N, T;
long long X;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    while(N--){
    	cin >> T;
    	
		bool flag=1;
		long long soldier=0;
		unordered_map<long long,int> M;
		
    	for(int i=0;i<T;i++){
    		cin >> X;
    		M[X]++;
    		
    		if(M[X]>(T/2)){
				flag=0;
				soldier=X;
			}
		}
		
		if(flag)cout << "SYJKGW\n";
		else cout << soldier << '\n';
	}
}
