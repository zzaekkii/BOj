#include <bits/stdc++.h>
using namespace std;

int N, M;
string num;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> num;
	
	for(int i=0;i<N;i++){
		if(num[i]>'0'){
			int cur=num[i]-48;
		
			if(10-cur<=M){
				num[i]='0';
				M-=10-cur;
			}
		}
	}
	
	if(M>0)num[N-1]=(((num[N-1]-48)+M%10)%10)+48;
	
	cout << num;
}
